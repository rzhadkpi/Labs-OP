#include <iostream>
#include "choosemode.h"

int choose_mode(int argc, char** argv, int& mode) {
	if (argc != 3) {
		return 0;
	}

	int flag = 1;

	if (strcmp(argv[1], "-mode") != 0) {
		return 0;
	}

	if (strcmp(argv[2], "FilePointer") == 0) {
		mode = 0;
	}
	else if (strcmp(argv[2], "FileStream") == 0) {
		mode = 1;
	}
	else {
		flag = 0;
	}
	return flag;
}
