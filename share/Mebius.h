#pragma once
#include <windows.h>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

enum H_TYPE {
    HEAD,
    TAIL,
    CALL
};

enum HOOK_CODE {
    HOOK_FOUND = 0,
    HOOK_NOT_FOUND = -1
};

#ifdef MEBIUS_EXPORT
#define CLASS_DECLSPEC extern "C" __declspec(dllexport)
#else
#define CLASS_DECLSPEC extern "C" __declspec(dllimport)
#endif

CLASS_DECLSPEC void LoadAllDLL(const fs::path& dirpath, const char* ex);
CLASS_DECLSPEC void FreeAllDLL(const fs::path& dirpath, const char* ex);
CLASS_DECLSPEC void Hook(void* target, void* callback, H_TYPE flag);
CLASS_DECLSPEC void writeBytesToROM(void* target, BYTE* bytes, size_t size);
CLASS_DECLSPEC void readBytesFromMem(void* target, BYTE* bytes, size_t size);
CLASS_DECLSPEC void writeCallOpcode(void* target, void* addr);