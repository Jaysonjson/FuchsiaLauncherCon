#pragma once
void debug(std::string text, FHXTIME::Time fakeUseTime) {
	std::cout << "[" << fakeUseTime.minutes << ":" << fakeUseTime.seconds << "] " << text << std::endl;
}