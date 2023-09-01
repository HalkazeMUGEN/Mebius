#include <_Plugin.hpp>

using namespace mebius;

void mebius::LoadPlugins(const std::string & ext) {
    plugin::PluginsLoader::GetInstance().Load(ext);
}
