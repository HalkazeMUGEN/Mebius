#pragma once
#include "Mebius.h"
#include <unordered_map>
#include <deque>
#include <vector>

struct HOOK
{
    BYTE *trampolineCode = nullptr;
    deque<void*> returnAddr;
    vector<void*> cbHeadFuncAddr;
    vector<void*> cbTailFuncAddr;
};

extern unordered_map<void*, HOOK> gHookList;

void writeOffset(void* target, void* addr, BYTE* bytes);


