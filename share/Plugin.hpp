#pragma once

#include <string>

#ifdef MEBIUS_EXPORT
#define MEBIUSAPI __declspec(dllexport)
#else
#define MEBIUSAPI __declspec(dllimport)
#endif

namespace mebius {
	extern "C" MEBIUSAPI void LoadPlugins(const std::string & ext);
}
