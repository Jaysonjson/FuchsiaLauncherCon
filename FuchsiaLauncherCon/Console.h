#pragma once

void debug(std::string text, FHXTIME::Time fakeUseTime, bool showUseTime) {
	if (showUseTime) {
		std::string seconds = "";
		std::string minutes = "";
		if (9 > fakeUseTime.seconds) {
			seconds.push_back('0');
		}
		seconds += std::to_string(fakeUseTime.seconds);
		if (9 > fakeUseTime.minutes) {
			minutes.push_back('0');
		}
		minutes += std::to_string(fakeUseTime.minutes);
		std::cout << "[" << minutes << ":" << seconds << "] " << text << std::endl;
	}
	else {
		std::cout << text << std::endl;
	}
}

void debug(std::string text, FHXTIME::Time fakeUseTime) {
	debug(text, fakeUseTime, true);
}
