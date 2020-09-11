#pragma once
namespace CommandLegacy {
	void DoCommand() {
		std::ifstream ifile("FuchsiaLauncherLegacy.jar");
		if (ifile) {
			system("java -jar FuchsiaLauncherLegacy.jar");
		}
		else {
			std::cout << "Couldn't find Legacy Launcher! Try: --legacy -download" << std::endl;
		}
	}
};