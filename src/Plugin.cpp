#include <_Plugin.hpp>

using namespace mebius;

std::vector<HMODULE> PluginsLoader::_plugins;

void mebius::LoadPlugins(const std::string & ext) {
    PluginsLoader loader(ext);
    loader.loadall();
}

void mebius::FreePlugins() {
    PluginsLoader::freeall();
}
