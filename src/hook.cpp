#include <_Mebius.h>
#include <Zydis/Zydis.h>
#include <asmjit/asmjit.h>
#include <asmtk/asmtk.h>

using namespace asmjit;
using namespace asmtk;

int createTrampoline(void* target) {
    Environment env(Arch::kX86);
    CodeHolder code;
    code.init(env);

    // Attach x86::Assembler to `code`.
    x86::Assembler a(&code);
    AsmParser p(&a);

    Error err = p.parse(
        "mov eax, ebx\n"
        "ret\n");




    ZyanU32 runtime_address = (DWORD)target;
    ZyanU8* data = (ZyanU8*)target;
    ZyanUSize offset = 0;
    ZydisDisassembledInstruction instruction;
    unsigned int length = 10;
    while (length > offset && ZYAN_SUCCESS(ZydisDisassembleIntel(
        ZYDIS_MACHINE_MODE_LEGACY_32,
        runtime_address,
        data + offset,
        0x7FFFFFFF,
        &instruction
    ))) {
        offset += instruction.info.length;
        runtime_address += instruction.info.length;
    }
    return offset;
}

void createHook(void* target) {
    // Hook済みなら終了
    auto it = gHookList.find(target);
    if (it != gHookList.end()) return;

    HOOK h;
    // トランポリン作成
    int size = createTrampoline(target);
    h.trampolineCode = new BYTE[size + 5];
    memcpy(h.trampolineCode, target, size);
    writeJumpOpcode(h.trampolineCode + size, (void*)((DWORD)target + size), OP_JMP);
    DWORD old = 0;
    VirtualProtect(h.trampolineCode, size + 5, PAGE_EXECUTE_READWRITE, &old);
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
    *stack = h.trampolineCode;

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