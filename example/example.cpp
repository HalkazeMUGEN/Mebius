#include "example.hpp"

using namespace mebius;

static inline void hooking() noexcept;


static auto ErrorExit = reinterpret_cast<void (*)(void)>(0x415860);
static auto TeamLifeBack = reinterpret_cast<int32_t (*)(int32_t)>(0x423be0);
static void hook_ErrorExit(void);
static int32_t hook_TeamLifeBack(int32_t original_result, int32_t teamIndex);


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
    HookOnTail(TeamLifeBack, hook_TeamLifeBack);
}

static void hook_ErrorExit(void) {
    MessageBoxA(NULL, "Hello, World!", NULL, MB_OK);
}

static int32_t hook_TeamLifeBack(int32_t original_result, int32_t teamIndex) {
    return original_result ^ teamIndex;
}