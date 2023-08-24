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
					if (HMODULE lib = LoadLibraryA(p.path().string().c_str())) {
						// ƒ[ƒh‚µ‚½î•ñ‚ğŒŸõ‚µ‚Ä”í‚è‚ª‚È‚¯‚ê‚ÎVector‚É’Ç‰Á
						if (std::find(_plugins.begin(), _plugins.end(), lib) == _plugins.end()) {
							_plugins.push_back(std::move(lib));
						}
					}
				}
			}
		}
		static void free(void) {
			for (auto&& h : _plugins) {
				FreeLibrary(h);
			}
		}
	private:
		static std::vector<HMODULE> _plugins;
		const std::string& _extension;
		const std::string& _path;
	};
}

