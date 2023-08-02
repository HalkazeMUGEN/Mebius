#include <_Mebius.h>
#include <Zydis/Zydis.h>

void Hook(void* target, void (*head)(void**)) {
    // フック済みか検索
    int index = findTargetHookByStart(target);

    // もしフックが存在しなければ
    if (index == HOOK_NOT_FOUND) {
        index = addHook(target);
    }

    if (!count(gHookList[index].cbHeadFuncAddr.begin(), gHookList[index].cbHeadFuncAddr.end(), head)) {
        gHookList[index].cbHeadFuncAddr.push_back(head);
    }
    return;
}

void Hook(void* target, int (*tail)(void**, int)) {
    // フック済みか検索
    int index = findTargetHookByStart(target);

    // もしフックが存在しなければ
    if (index == HOOK_NOT_FOUND) {
        index = addHook(target);
    }

    if (!count(gHookList[index].cbTailFuncAddr.begin(), gHookList[index].cbTailFuncAddr.end(), tail)) {
        gHookList[index].cbTailFuncAddr.push_back(tail);
    }
    return;
}

int addHook(void* target) {
    HOOK h;
    h.targetStartAddr = target;

    // ディスアセンブル
    PDWORD old;
    int size = calcTrampolineSize(target);
    h.targetOrigBytes = new BYTE[size + 5];
    memcpy(h.targetOrigBytes, target, size);
    writeJmpOpcode(h.targetOrigBytes + size, (void*)((DWORD)target + size));
    VirtualProtect(h.targetOrigBytes, size + 5, PAGE_EXECUTE_READWRITE, old);

    // indexをリストの最後にする
    int index = gHookList.size();
    gHookList.push_back(h);
    writeCallOpcode(target, Head);
    return index;
}

int calcTrampolineSize(void* target) {
    ZyanU32 runtime_address = (DWORD)target;
    ZyanU8* data = (ZyanU8*)target;
    ZyanUSize offset = 0;
    ZydisDisassembledInstruction instruction;
    int length = 5;
    while (length > offset && ZYAN_SUCCESS(ZydisDisassembleIntel(
       ZYDIS_MACHINE_MODE_LONG_COMPAT_32,
       runtime_address,
       data + offset,
       sizeof(data) - offset,
       &instruction
    ))) {
        offset += instruction.info.length;
        runtime_address += instruction.info.length;
    }
    return offset;
}

void Head(void) {
    void** stack;
    _asm {
        MOV stack, EBP
        ADD stack, 0x04
    }
    // 先頭アドレスを検索してターゲットをオリジナルのバイト列に戻す
    int index = findTargetHookByStart((void*)((DWORD)*stack - 5));
    writeBytesToROM(gHookList[index].targetStartAddr, gHookList[index].targetOrigBytes, 5);

    // Headのリターンをターゲットのアドレスに変える
    *stack = gHookList[index].targetStartAddr;

    // ターゲットのリターンアドレスを保存する
    gHookList[index].targetReturnAddr = *(stack + 1);

    // Tailへのフックコールを作成
    writeCallOpcode((void*)((DWORD) * (stack + 1) - 5), ESCAPE_RET);

    // ターゲットのリターンアドレスをターゲットの呼び出し位置にする
    *(stack + 1) = (void*)((DWORD) * (stack + 1) - 5);

    for (size_t i = 0; i < gHookList[index].cbHeadFuncAddr.size(); i++) {
        auto hooked = reinterpret_cast<void (*)(void**)>(gHookList[index].cbHeadFuncAddr[i]);
        hooked(stack + 2);
    }

    return;
}

void ESCAPE_RET(void) {
    _asm {
        XCHG EAX, [ESP]
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

    // リターンアドレスを検索
    int index = findTargetHookByReturn(*stack);

    // ターゲットのコール元をもとに戻す
    writeCallOpcode((void*)((DWORD)*stack - 5), gHookList[index].targetStartAddr);

    // Headへのフックコールを作成
    writeCallOpcode(gHookList[index].targetStartAddr, Head);

    int ret = RETVALUE;
    for (size_t i = 0; i < gHookList[index].cbTailFuncAddr.size(); i++) {
        auto hooked = reinterpret_cast<int (*)(void**, int)>(gHookList[index].cbTailFuncAddr[i]);
        ret = hooked(stack + 2, RETVALUE);
    }

    return ret;
}