#pragma once

#include "Log.hpp"
#include "Error.hpp"
#include "Plugin.hpp"
#include <Windows.h>
#include <filesystem>
#include <vector>

namespace mebius {
	namespace fs = std::filesystem;

	constexpr static inline char MODS_DIRNAME[] = "mods";

	class PluginsLoader {
	public:
		static PluginsLoader& GetInstance() noexcept {
			static PluginsLoader instance{};
			return instance;
		}
		PluginsLoader(const PluginsLoader&) = delete;
		PluginsLoader& operator=(const PluginsLoader&) = delete;
		PluginsLoader(PluginsLoader&&) = delete;
		PluginsLoader& operator=(PluginsLoader&&) = delete;

		void Load(const std::string& ext) noexcept {
			for (auto&& dir : fs::recursive_directory_iterator(_modsdir)) {
				if (dir.path().extension() == ext) {
					if (auto&& plugin = LoadLibraryA(dir.path().string().c_str())) {
						if (std::find(_plugins.begin(), _plugins.end(), plugin) == _plugins.end()) {
							_plugins.emplace_back(std::move(plugin));
						}
					}
				}
			}
		}

	private:
		const fs::path& _modsdir;
		std::vector<HMODULE> _plugins;

		PluginsLoader() noexcept : _modsdir(std::move((fs::current_path() /= MODS_DIRNAME))), _plugins() {}
		~PluginsLoader() noexcept {
			for (auto&& plugin : _plugins) {
				FreeLibrary(std::move(plugin));
			}
		}
	};
}

