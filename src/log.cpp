#include "_Mebius.h"
#include <fstream>

std::ofstream logfile;

void MebLogWrite(const std::string& content) {
	if (!logfile.is_open()) {
		logfile.open("mebius.log");
		logfile << "---------------------------------\n";
		logfile << "Mebius Loader ver 0.04 status log\n";
		logfile << "---------------------------------\n";
	}
	logfile << content << "\n";
}