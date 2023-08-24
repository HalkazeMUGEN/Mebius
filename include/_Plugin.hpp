#pragma once

#include "Log.hpp"
#include "Error.hpp"
#include "Plugin.hpp"
#include <Windows.h>
#include <filesystem>
#include <unordered_set>

namespace mebius {
	namespace plugin {
		namespace fs = std::filesystem;

		constexpr static inline char MODS_DIRNAME[] = "mods";

		namespace internal {
			class HModuleWrapper {
			public:
				HModuleWrapper(HMODULE&& handle) noexcept : _handle(handle) {}
				HModuleWrapper(const HModuleWrapper&) = delete;
				HModuleWrapper& operator=(const HModuleWrapper&) = delete;
				HModuleWrapper(HModuleWrapper&&) = delete;
				HModuleWrapper& operator=(HModuleWrapper&&) = delete;

				~HModuleWrapper() noexcept {
					FreeLibrary(_handle);
				}

				operator HMODULE() const noexcept {
					return _handle;
				}

			private:
				HMODULE _handle;
			};
		}

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
					if (dir.path().extension().string() == ext) {
						if (auto&& plugin = LoadLibraryEx(dir.path().native().c_str(), NULL, LOAD_LIBRARY_SEARCH_APPLICATION_DIR)) {
							_plugins.emplace(std::move(plugin));
						}
					}
				}
			}

			/*
			* wstring実装
			* 拡張子にワイド文字を使用することを考慮するならこちらを使用する
			*
			void Load(const std::wstring& ext) noexcept {
				for (auto&& dir : fs::recursive_directory_iterator(_modsdir)) {
					if (dir.path().extension().native() == ext) {
						if (auto&& plugin = LoadLibraryEx(dir.path().native().c_str(), NULL, LOAD_LIBRARY_SEARCH_APPLICATION_DIR)) {
							_plugins.emplace(std::move(plugin));
						}
					}
				}
			}
			*/

		private:
			const fs::path& _modsdir;
			std::unordered_set<internal::HModuleWrapper> _plugins;

			PluginsLoader() noexcept : _modsdir(std::move((fs::current_path() /= MODS_DIRNAME))), _plugins() {}
			~PluginsLoader() noexcept = default;
		};
	}
}
