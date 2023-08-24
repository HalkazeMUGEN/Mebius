#include <_Plugin.hpp>

using namespace mebius;

std::vector<HMODULE> PluginsLoader::_plugins;

void mebius::LoadPlugins(const std::string & ext) {
    std::shared_ptr <PluginsLoader> loader(new PluginsLoader(ext));
}

void mebius::FreePlugins() {
    PluginsLoader::free();
}
