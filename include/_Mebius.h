#pragma once
#include "Mebius.h"
#include <vector>

void Head(void);
void ESCAPE_EAX(void);
int __stdcall Tail(int eax);
int findTargetHookByStart(void* target);
int findTargetHookByReturn(void* target);

struct HOOK
{
    void* targetStartAddr = NULL;
    void* targetReturnAddr = NULL;
    BYTE targetOrigBytes[5] = { 0xCC, 0xCC, 0xCC, 0xCC, 0xCC };
    vector<void*> cbHeadFuncAddr;
    vector<void*> cbTailFuncAddr;
};