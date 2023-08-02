#include <_Mebius.h>
#include <Winmugen.h>

void test_head(void** stack) {
    return;
}
void test_head_sub(void** stack) {
    return;
}

int test_tail(void** stack, int RETVALUE) {
    return RETVALUE;
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH: {
        Hook(SCtrlParseTrigger, test_head);
        Hook(SCtrlParseTrigger, test_head_sub);
        Hook(SCtrlParseTrigger, test_tail);
        LoadAllDLL("mods", ".mx");
        break;
    }
    case DLL_THREAD_ATTACH: {
        break;
    }
    case DLL_THREAD_DETACH: {
        break;
    }
    case DLL_PROCESS_DETACH: {
        FreeAllDLL("mods", ".mx");
        break;
    }
    }
    return TRUE;
}
