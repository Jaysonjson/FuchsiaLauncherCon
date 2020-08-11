#pragma once
#include <iostream>
#include <fstream>
namespace CommandOpenLegacy {
	void DoCommand() {
		ifstream ifile("legacy/FuchsiaLauncher.jar");
		if (ifile) {
			system("java -jar legacy/FuchsiaLauncher.jar");
		}
		else {
			cout << "Couldn't find Legacy Launcher!" << endl;
		}
	}
};
class CommandOpenLegacyOld: public Command {
};