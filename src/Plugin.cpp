#include <_Plugin.hpp>

using namespace mebius;

void mebius::LoadPlugins(const std::string & ext) {
    PluginsLoader::GetInstance().Load(ext);
}
