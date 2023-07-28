#pragma once
#include <windows.h>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

enum HOOK_CODE {
    HOOK_FOUND = 0,
    HOOK_NOT_FOUND = -1
};

#ifdef MEBIUS_EXPORT
#define CLASS_DECLSPECEC extern "C" __declspec(dllexport)
#define CLASS_DECLSPEC __declspec(dllexport)
#else
#define CLASS_DECLSPECEC extern "C" __declspec(dllimport)
#define CLASS_DECLSPEC __declspec(dllimport)
#endif

CLASS_DECLSPECEC void LoadAllDLL(const fs::path& dirpath, const char* ex);
CLASS_DECLSPECEC void FreeAllDLL(const fs::path& dirpath, const char* ex);
CLASS_DECLSPECEC void writeBytesToROM(void* target, BYTE* bytes, size_t size);
CLASS_DECLSPECEC void readBytesFromMem(void* target, BYTE* bytes, size_t size);
CLASS_DECLSPECEC void writeCallOpcode(void* target, void* addr);
CLASS_DECLSPECEC void MebLogWrite(const std::string& content);
CLASS_DECLSPEC void Hook(void* target, void (*head)(void**));
CLASS_DECLSPEC void Hook(void* target, int (*tail)(void**, int));