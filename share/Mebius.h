#pragma once
#include <windows.h>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

enum SETEIP_TYPE {
    OP_CALL,
    OP_JMP
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
CLASS_DECLSPECEC void writeJumpOpcode(void* target, void* addr, SETEIP_TYPE type);
CLASS_DECLSPECEC void MebLogWrite(const std::string& content);
CLASS_DECLSPEC void Hook(void* target, void (*head)(void**));
CLASS_DECLSPEC void Hook(void* target, int (*tail)(void**, int));