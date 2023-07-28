#pragma once
#include "Mebius.h"
#include <vector>

struct HOOK
{
    void* targetStartAddr = NULL;
    void* targetReturnAddr = NULL;
    BYTE targetOrigBytes[5] = { 0xCC, 0xCC, 0xCC, 0xCC, 0xCC };
    vector<void*> cbHeadFuncAddr;
    vector<void*> cbTailFuncAddr;
};

void Head(void);
void ESCAPE_RET(void);
int __stdcall Tail(int eax);
int findTargetHookByStart(void* target);
int findTargetHookByReturn(void* target);
int addHook(void* target);

extern vector<HOOK> gHookList;