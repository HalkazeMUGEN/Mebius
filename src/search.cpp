#include <_Mebius.h>

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
