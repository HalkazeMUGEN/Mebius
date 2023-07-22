#include "_Mebius.h"

void writeBytesToROM(void* target, BYTE* bytes, size_t size) {
    DWORD old = PAGE_EXECUTE_READ;
    VirtualProtect(target, size, PAGE_EXECUTE_READWRITE, &old);
    memcpy(target, bytes, size);
    VirtualProtect(target, size, old, &old);
}

void readBytesFromMem(void* target, BYTE* bytes, size_t size) {
    memcpy(bytes, target, size);
}

void writeCallOpcode(void* target, void* addr) {
    BYTE bytes[5] = { 0xE8 };
    void* func = (void*)((DWORD)addr - (DWORD)target - 5);
    memcpy(&bytes[1], &func, 4);
    writeBytesToROM(target, bytes, 5);
}




