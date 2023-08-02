#include <_Mebius.h>
#include <fstream>

bool isFirst = TRUE;

void MebLogWrite(const std::string& content) {
	std::ofstream logfile;
	if (isFirst) {
		isFirst = FALSE;
		logfile.open("mebius.log");
		logfile << "----------------------------------\n";
		logfile << "Mebius Loader ver 0.0.5 status log\n";
		logfile << "----------------------------------\n";
	}
	else {
		logfile.open("mebius.log", std::ios_base::app);
	}
	logfile << content << "\n";
	logfile.close();
}