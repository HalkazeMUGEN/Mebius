#include "example.hpp"

using namespace mebius;

static inline void hooking() noexcept;


static auto ErrorExit = reinterpret_cast<void (*)(void)>(0x415860);
static auto TeamLifeBack = reinterpret_cast<int32_t (*)(int32_t)>(0x423be0);
static auto SysExplodCreate_Sys = reinterpret_cast<void(*)(void*, int, int)>(0x41af40);
static auto ComboAdd = reinterpret_cast<void(*)(int, int)>(0x421ef0);

static void hook_ErrorExit(void);
static int32_t hook_TeamLifeBack(int32_t original_result, int32_t teamIndex);
static void hook_SysExplodCreate_sys(void* viewItem, int posX, int posY);
static void hook_ComboAdd(int teamSide, int value);

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH: {
        hooking();
        break;
    }
    case DLL_PROCESS_DETACH: {
        break;
    }
    }
    return TRUE;
}

static inline void hooking() noexcept {
    HookOnHead(ErrorExit, hook_ErrorExit);
    HookOnHead(ComboAdd, hook_ComboAdd);
    HookOnHead(SysExplodCreate_Sys, hook_SysExplodCreate_sys);
    HookOnTail(TeamLifeBack, hook_TeamLifeBack);
}

static void hook_ErrorExit(void) {
    mebius::ShowErrorDialog("Hello, World!");
}

static int32_t hook_TeamLifeBack(int32_t original_result, int32_t teamIndex) {
    return original_result ^ teamIndex;
}

static void hook_SysExplodCreate_sys(void* viewItem, int posX, int posY) {

}

static void hook_ComboAdd(int teamSide, int value) {

}
