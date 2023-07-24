#include "_Mebius.h"
#include <fstream>

bool isFirst = TRUE;

void MebLogWrite(const std::string& content) {
	std::ofstream logfile;
	logfile.open("mebius.log");
	if (isFirst) {
		isFirst = FALSE;
		logfile << "---------------------------------\n";
		logfile << "Mebius Loader ver 0.04 status log\n";
		logfile << "---------------------------------\n";
	}
	logfile << content << "\n";
	logfile.close();
}