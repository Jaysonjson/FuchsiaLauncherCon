#pragma once
namespace CommandDiscord {
	void DoCommandNull(FHXTIME::Time fakeUseTime, std::vector<std::string> arguments) {
		if (arguments.size() >= 1) {
			std::string url = "";
			if (arguments[1] == "-fuchsia") {
				url = "https://discord.gg/jhK6Ab3";
			}
			else if (arguments[1] == "-graviarts") {
				url = "https://discord.gg/7h6tqua";
			}
			if (url != "") {
				debug(url, fakeUseTime);
				debug("Opening in Browser...", fakeUseTime);
				system(std::string("start " + url).c_str());
			}
			else {
				debug("Unknown Argument", fakeUseTime);
			}
		}
		else {
			debug("Not enough Arguments!", fakeUseTime);
		}
	}
};