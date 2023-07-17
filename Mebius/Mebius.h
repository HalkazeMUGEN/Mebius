#pragma once
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

#define _EXPORTING
#ifdef _EXPORTING
#define CLASS_DECLSPEC extern "C" __declspec(dllexport)
#else
#define CLASS_DECLSPEC extern "C" __declspec(dllimport)
#endif

enum H_TYPE {
    HEAD,
    TAIL,
    CALL,
    JMP
};

enum HOOK_CODE {
    HOOK_FOUND = 0,
    HOOK_NOT_FOUND = -1
};

CLASS_DECLSPEC void LoadAllDLL(const fs::path& dirpath, const char* ex);
CLASS_DECLSPEC void FreeAllDLL(const fs::path& dirpath, const char* ex);
CLASS_DECLSPEC void Hook(DWORD target, DWORD callback, H_TYPE flag);
CLASS_DECLSPEC void writeBytesToROM(DWORD target, void* bytes, size_t size);
CLASS_DECLSPEC void readBytesFromMem(DWORD target, void* bytes, size_t size);
CLASS_DECLSPEC void writeGotoOpcode(DWORD target, DWORD addr, H_TYPE mode);