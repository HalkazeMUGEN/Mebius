#include "_Mebius.h"

void Hook(void* target, void* callback, H_TYPE flag) {
    // フック済みか検索
    int index = findTargetHookByStart(target);

    // もしフックが存在しなければ
    if (index == HOOK_NOT_FOUND) {
        HOOK h;
        h.targetStartAddr = target;
        memcpy(h.targetOrigBytes, target, 5);
        // indexをリストの最後にする
        index = gHookList.size();
        gHookList.push_back(h);
        writeCallOpcode(target, Head);
    }

    switch (flag) {
    case HEAD: {
        if (!count(gHookList[index].cbHeadFuncAddr.begin(), gHookList[index].cbHeadFuncAddr.end(), callback)) {
            gHookList[index].cbHeadFuncAddr.push_back(callback);
        }
        break;
    }
    case TAIL: {
        if (!count(gHookList[index].cbTailFuncAddr.begin(), gHookList[index].cbTailFuncAddr.end(), callback)) {
            gHookList[index].cbTailFuncAddr.push_back(callback);
        }
        break;
    }
    default: {
        break;
    }
    }


    return;
}

void Head(void) {
    void** stack;
    _asm {
        MOV stack, EBP
    }
    // 先頭アドレスを検索してターゲットをオリジナルのバイト列に戻す
    int index = findTargetHookByStart((void*)((DWORD) * (stack + 1) - 5));
    writeBytesToROM(gHookList[index].targetStartAddr, gHookList[index].targetOrigBytes, 5);

    // Headのリターンをターゲットのアドレスに変える
    *(stack + 1) = gHookList[index].targetStartAddr;

    // ターゲットのリターンアドレスを保存する
    gHookList[index].targetReturnAddr = *(stack + 2);

    // Tailへのフックコールを作成
    writeCallOpcode((void*)((DWORD) * (stack + 2) - 5), ESCAPE_RET);

    // ターゲットのリターンアドレスをターゲットの呼び出し位置にする
    *(stack + 2) = (void*)((DWORD) * (stack + 2) - 5);

    for (size_t i = 0; i < gHookList[index].cbHeadFuncAddr.size(); i++) {
        auto hooked = reinterpret_cast<void (*)(void)>(gHookList[index].cbHeadFuncAddr[i]);
        hooked();
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
    }

    // リターンアドレスを検索
    int index = findTargetHookByReturn(*(stack + 1));

    // ターゲットのコール元をもとに戻す
    writeCallOpcode((void*)((DWORD) * (stack + 1) - 5), gHookList[index].targetStartAddr);

    // Headへのフックコールを作成
    writeCallOpcode(gHookList[index].targetStartAddr, Head);

    int ret = RETVALUE;
    for (size_t i = 0; i < gHookList[index].cbTailFuncAddr.size(); i++) {
        auto hooked = reinterpret_cast<int (*)(int)>(gHookList[index].cbTailFuncAddr[i]);
        ret = hooked(RETVALUE);
    }

    return ret;
}