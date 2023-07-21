// dllmain.cpp : DLL アプリケーションのエントリ ポイントを定義します。
#include "framework.h"
#include "Mebius.h"
#include <vector>

// プロトタイプ宣言
void Head(void);
void ESCAPE_EAX(void);
int __stdcall Tail(int eax);
int findTargetHookByStart(void* target);
int findTargetHookByReturn(void* target);

// フックリスト
struct HOOK
{
    void* targetStartAddr = NULL;
    void* targetReturnAddr = NULL;
    BYTE targetOrigBytes[5] = { 0xCC, 0xCC, 0xCC, 0xCC, 0xCC };
    vector<void*> cbHeadFuncAddr;
    vector<void*> cbTailFuncAddr;
};

vector<HOOK> gHookList;

int findTargetHookByStart(void* target) {
    for (size_t i = 0; i < gHookList.size(); i++) {
        if (gHookList[i].targetStartAddr == target) {
            return static_cast<int>(i);
        }
    }
    return HOOK_NOT_FOUND;
}

int findTargetHookByReturn(void* target) {
    for (size_t i = 0; i < gHookList.size(); i++) {
        if (gHookList[i].targetReturnAddr == target) {
            return static_cast<int>(i);
        }
    }
    return HOOK_NOT_FOUND;
}

void writeBytesToROM(void* target, BYTE* bytes, size_t size) {
    DWORD old = PAGE_EXECUTE_READ;
    VirtualProtect(target, size, PAGE_EXECUTE_READWRITE, &old);
    memcpy(target, bytes, size);
    VirtualProtect(target, size, old, &old);
}

void readBytesFromMem(void* target, BYTE* bytes, size_t size) {
    memcpy(bytes, target, size);
}

void writeGotoOpcode(void* target, void* addr, H_TYPE mode) {
    BYTE bytes[5] = {};
    if (mode == JMP) {
        bytes[0] = 0xE9;
    }
    else {
        bytes[0] = 0xE8;
    }
    void* func = (void*)((DWORD)addr - (DWORD)target - 5);
    memcpy(&bytes[1], &func, 4);
    writeBytesToROM(target, bytes, 5);
}

void Head(void) {
    void** stack;
    _asm {
        MOV stack, EBP
    }
    // 先頭アドレスを検索してターゲットをオリジナルのバイト列に戻す
    int index = findTargetHookByStart((void*)((DWORD)*(stack + 1) - 5));
    writeBytesToROM(gHookList[index].targetStartAddr, gHookList[index].targetOrigBytes, 5);

    // Headのリターンをターゲットのアドレスに変える
    *(stack + 1) = gHookList[index].targetStartAddr;

    // ターゲットのリターンアドレスを保存する
    gHookList[index].targetReturnAddr = *(stack + 2);

    // Tailへのフックコールを作成
    writeGotoOpcode((void*)((DWORD)*(stack + 2) - 5), ESCAPE_EAX, CALL);

    // ターゲットのリターンアドレスをターゲットの呼び出し位置にする
    *(stack + 2) = (void*)((DWORD)*(stack + 2) - 5);

    for (size_t i = 0; i < gHookList[index].cbHeadFuncAddr.size(); i++) {
        auto hooked = reinterpret_cast<void (*)(void)>(gHookList[index].cbHeadFuncAddr[i]);
        hooked();
    }

    return;
}

#pragma optimize("g", on)
void ESCAPE_EAX(void) {
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
    writeGotoOpcode((void*)((DWORD)*(stack + 1) - 5), gHookList[index].targetStartAddr, CALL);

    // Headへのフックコールを作成
    writeGotoOpcode(gHookList[index].targetStartAddr, Head, CALL);

    int ret = RETVALUE;
    for (size_t i = 0; i < gHookList[index].cbTailFuncAddr.size(); i++) {
        auto hooked = reinterpret_cast<int (*)(int)>(gHookList[index].cbTailFuncAddr[i]);
        ret = hooked(RETVALUE);
    }

    return ret;
}

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
        writeGotoOpcode(target, Head, CALL);
    }

    if (flag == H_TYPE::HEAD) {
        if (!count(gHookList[index].cbHeadFuncAddr.begin(), gHookList[index].cbHeadFuncAddr.end(), callback)) {
            gHookList[index].cbHeadFuncAddr.push_back(callback);
        }
    }
    else {
        if (!count(gHookList[index].cbTailFuncAddr.begin(), gHookList[index].cbTailFuncAddr.end(), callback)) {
            gHookList[index].cbTailFuncAddr.push_back(callback);
        }
    }

    return;
}

void LoadAllDLL(const fs::path& dirpath, const char* ex)
{
    for (const auto& entry : fs::directory_iterator(dirpath)) {
        if (entry.is_directory()) {
            // サブディレクトリが見つかった場合、再帰的に探索します
            LoadAllDLL(entry.path(), ex);
        }
        else if (entry.is_regular_file() && entry.path().extension() == ex) {
            LoadLibraryA(entry.path().string().c_str());
        }
    }
}

void FreeAllDLL(const fs::path& dirpath, const char* ex)
{
    for (const auto& entry : fs::directory_iterator(dirpath)) {
        if (entry.is_directory()) {
            // サブディレクトリが見つかった場合、再帰的に探索します
            FreeAllDLL(entry.path(), ex);
        }
        else if (entry.is_regular_file() && entry.path().extension() == ex) {
            auto dll = LoadLibraryA(entry.path().string().c_str());
            FreeLibrary(dll);
        }
    }
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH: {
        LoadAllDLL("mods", ".mx");
        break;
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH: {
        FreeAllDLL("mods", ".mx");
        break;
    }
    }
    return TRUE;
}

