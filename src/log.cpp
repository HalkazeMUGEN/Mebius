#include <_Log.hpp>

using namespace mebius;

void mebius::WriteLog(const std::string& content)
{
	try {
		static LogWriter file{LOG_FILENAME};
		file.write(content);
	}
	catch (const MebiusError& e) {
		ShowErrorDialog(e.what());
	}
}
