#include "_Mebius.h"

void LoadAllDLL(const fs::path& dirpath, const char* ex)
{
    for (const auto& entry : fs::directory_iterator(dirpath)) {
        if (entry.is_directory()) {
            // サブディレクトリが見つかった場合、再帰的に探索します
            LoadAllDLL(entry.path(), ex);
        }
        else if (entry.is_regular_file() && entry.path().extension() == ex) {
            std::stringstream log;
            log << "Load: " << entry.path().string().c_str();
            MebLogWrite(log.str());

            LoadLibraryA(entry.path().string().c_str());
        }
    }
}

void FreeAllDLL(const fs::path& dirpath, const char* ex)
{
    for (const auto& entry : fs::directory_iterator(dirpath)) {
        if (entry.is_directory()) {
            // サブディレクトリが見つかった場合、再帰的に探索します
            FreeAllDLL(entry.path(), ex);
        }
        else if (entry.is_regular_file() && entry.path().extension() == ex) {
            auto dll = LoadLibraryA(entry.path().string().c_str());
            if (dll) {
                std::stringstream log;
                log << "Free: " << entry.path().string().c_str();
                MebLogWrite(log.str());
                FreeLibrary(dll);
            }
        }
    }
}