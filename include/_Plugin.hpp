#pragma once

#include "Log.hpp"
#include "Error.hpp"
#include "Plugin.hpp"
#include <Windows.h>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

namespace mebius {
	void FreePlugins(void);

	class PluginsLoader {
	public:
		explicit PluginsLoader(const std::string& ext) : _extension(ext), _path(fs::current_path().string() + "\\mods\\") {
			for (auto& p : fs::recursive_directory_iterator(_path))
			{
				if (p.path().extension() == ext) {
					_files.push_back(p.path().string().c_str());
				}
			}
		}
		void load(void) {
			for (auto&& f : _files) {
				LoadLibraryA(f);
			}
		}
		static void free(void) {
			for (auto&& h : _plugins) {
				FreeLibrary(h);
			}
		}
	private:
		static std::vector<HMODULE> _plugins;
		std::vector<LPCSTR> _files;
		const std::string& _extension;
		const std::string& _path;
	};
}

