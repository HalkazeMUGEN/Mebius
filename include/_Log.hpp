#pragma once

#include "Log.hpp"
#include "Error.hpp"
#include <format>
#include <fstream>

namespace mebius {
	constexpr static inline char LOG_FILENAME[] = "mebius.log";
	constexpr static inline char LOG_LOGO[] =	"----------------------------------\n"
												"Mebius Loader ver 0.0.5 status log\n"
												"----------------------------------\n";

	class LogWriter {
	public:
		explicit LogWriter(const std::string& filename) : _stream(filename) {
			if (_stream.is_open()) {
				_stream << LOG_LOGO;
			}
			else {
				throw MebiusError(std::format("Can't open the file: {}.", LOG_FILENAME));
			}
		}

		void write(const std::string& message) noexcept {
			_stream << message << std::endl;
		}

	private:
		std::ofstream _stream;
	};
}
