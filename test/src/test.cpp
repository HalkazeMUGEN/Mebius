#include "Mebius.h"

int main() {
	HMODULE hLib = LoadLibraryExA("..\\Mebius.dll", NULL, LOAD_LIBRARY_SEARCH_APPLICATION_DIR);
	return hLib == NULL;
}
