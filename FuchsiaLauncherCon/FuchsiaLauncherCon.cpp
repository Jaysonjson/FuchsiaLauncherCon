#include <iostream>
#include <Windows.h>
using namespace std;
#pragma comment(lib,"URLMon.lib")

void showCommands();
void getCommand();
bool validCommand(string& input, string command);
void command_DownloadArg3();

int main() {
	int d = 5;
	showCommands();
	return 0;
}

void showCommands() {
	cout << "--download (game) (type) (version)" << endl;
	getCommand();
}

void getCommand() {
	string input;
	cout << "Awaiting command: ";
	cin >> input;
	if (validCommand(input, "--download")) {
		command_DownloadArg3();
		getCommand();
	}
	cout << "Command not Found!" << endl;
	getCommand();
}

bool validCommand(string& input, string command) {
	if (input == command || "--" + input == command) {
		return true;
	}
	return false;
}

void command_DownloadArg3() {
	HRESULT result = URLDownloadToFile(NULL, L"https://www.dropbox.com/s/z48mhkb0b0mo47q/mpbot.jar?dl=1", L"Test.zip", 0, NULL);
	cout << "Result: " << result;
	cout << "Downloaded!" << endl;
}