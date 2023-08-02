#include <_Mebius.h>

void writeBytesToROM(void* target, BYTE* bytes, size_t size) {
    DWORD old = PAGE_EXECUTE_READ;
    VirtualProtect(target, size, PAGE_EXECUTE_READWRITE, &old);
    memcpy(target, bytes, size);
    VirtualProtect(target, size, old, &old);
}

void readBytesFromMem(void* target, BYTE* bytes, size_t size) {
    memcpy(bytes, target, size);
}

void writeJumpOpcode(void* target, void* addr, SETEIP_TYPE type) {
    BYTE bytes[5];
    if (type == OP_CALL) {
        bytes[0] = { 0xE8 };
    }
    else {
        bytes[0] = { 0xE9 };
    }
    writeOffset(target, addr, &bytes[1]);
    writeBytesToROM(target, bytes, 5);
}

void writeOffset(void* target, void* addr, BYTE* bytes) {
    void* func = (void*)((DWORD)addr - (DWORD)target - 5);
    memcpy(bytes, &func, 4);
}

