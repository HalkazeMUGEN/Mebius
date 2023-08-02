#pragma once
#include "Mebius.h"
#include <vector>

struct HOOK
{
    void* targetStartAddr = NULL;
    void* targetReturnAddr = NULL;
    BYTE *targetOrigBytes;
    vector<void*> cbHeadFuncAddr;
    vector<void*> cbTailFuncAddr;
};

void Head(void);
void ESCAPE_RET(void);
int __stdcall Tail(int eax);
int findTargetHookByStart(void* target);
int findTargetHookByReturn(void* target);
int addHook(void* target);
void writeOffset(void* target, void* addr, BYTE* bytes);
int calcTrampolineSize(void* target);

extern vector<HOOK> gHookList;

