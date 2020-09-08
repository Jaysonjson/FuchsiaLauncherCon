#pragma once
#include <iostream>
#include <fstream>
namespace CommandOpenLegacy {
	void DoCommand() {
		std::ifstream ifile("legacy/FuchsiaLauncher.jar");
		if (ifile) {
			system("java -jar legacy/FuchsiaLauncher.jar");
		}
		else {
			std::cout << "Couldn't find Legacy Launcher!" << std::endl;
		}
	}
};
class CommandOpenLegacyOld: public Command {
};