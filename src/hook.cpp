#include <_Mebius.h>
#include <Zydis/Zydis.h>
#include <asmjit/asmjit.h>
#include <asmtk/asmtk.h>

using namespace asmjit;
using namespace asmtk;

void* createTrampoline(void* target) {
    // 宣言
    static JitRuntime rt;
    static Environment env(Arch::kX86);
    static unsigned int MIN_LENGTH = 10;

    CodeHolder code;
    code.init(env);
    x86::Assembler assembler(&code);
    AsmParser parser(&assembler);

    ZyanU32 runtime_address = (DWORD)target;
    ZyanU8* data = (ZyanU8*)target;
    ZyanUSize offset = 0;
    ZydisDisassembledInstruction instruction;

    while (MIN_LENGTH > offset && ZYAN_SUCCESS(ZydisDisassembleIntel(ZYDIS_MACHINE_MODE_LEGACY_32, runtime_address, data + offset, 0x7FFFFFFF, &instruction)))
    {
        parser.parse(instruction.text);
        offset += instruction.info.length;
        runtime_address += instruction.info.length;
    }
    assembler.jmp((DWORD)target + offset);

    void* func = nullptr;
    rt.add(&func, &code);
    return func;
}

void createHook(void* target) {
    // Hook済みなら終了
    auto it = gHookList.find(target);
    if (it != gHookList.end()) return;

    HOOK h;
    h.trampolineFunc = createTrampoline(target);

    writeJumpOpcode(target, Head, OP_CALL);
    writeJumpOpcode((void*)((DWORD)target + 5), Tail_Escape, OP_CALL);
    // Hookを追加
    gHookList.emplace(target, h);

    return;
}

void Hook(void* target, void (*head)(void**)) {
    // Hookを作成
    createHook(target);
    // head_hookを追加
    auto it = gHookList.find(target);
    it->second.cbHeadFuncAddr.push_back(head);
    return;
}

void Hook(void* target, int (*tail)(void**, int)) {
    // Hookを作成
    createHook(target);
    // tail_hookを追加
    auto it = gHookList.find(target);
    it->second.cbTailFuncAddr.push_back(tail);
    return;
}

void Head(void) {
    void** stack;
    _asm {
        MOV stack, EBP
        ADD stack, 0x04
    }

    // ターゲットを特定
    auto it = gHookList.find((void*)((DWORD)*stack - 5));
    HOOK& h = it->second;

    // ターゲットのリターンアドレスを保存
    h.returnAddr.push_back((void*)*(stack + 1));

    // ターゲットのリターンアドレスをTailの呼び出し位置にする
    *(stack + 1) = (void*)((DWORD) * (stack));

    // Headのリターンアドレスをトランポリンに変更
    *stack = h.trampolineFunc;

    // head_hookをすべて実行
    for (void *addr : h.cbHeadFuncAddr) {
        auto hook_head = reinterpret_cast<void (*)(void**)>(addr);
        hook_head(stack + 2);
    }

    return;
}


void __declspec(naked) Tail_Escape(void) {
    _asm {
        XCHG [ESP], EAX
        PUSH EAX
        JMP Tail
    }
}

int __stdcall Tail(int RETVALUE) {
    void** stack;
    _asm {
        MOV stack, EBP
        ADD stack, 0x04
    }

    // ターゲットを特定
    auto it = gHookList.find((void*)((DWORD)*stack - 10));
    HOOK& h = it->second;

    // Tailのリターンをターゲットのリターンに修復
    *stack = h.returnAddr.back();
    h.returnAddr.pop_back();

    // tail_hookをすべて実行
    for (void* addr : h.cbTailFuncAddr) {
        auto hook_tail = reinterpret_cast<int (*)(void**, int)>(addr);
        RETVALUE = hook_tail(stack + 2, RETVALUE);
    }

    return RETVALUE;
}