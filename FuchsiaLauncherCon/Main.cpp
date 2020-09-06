#include <iostream>
#include <map>
#include <string>
#include <json/json.h>
#include <curl/curl.h>
#include <zip.h>
#include <chrono>
#include <thread>
#include <vector>
#include "Time.h"
#include "Console.h"
#include "VersionData.h"
#include "Settings.h"
#include "CommandList.h"
#include "ProgressBar.h"
#include "Commands.h"
#pragma comment(lib,"URLMon.lib")
using namespace std;

void Start();
bool GetCommandAction(const string& currentCommandIn);
void TimeCounter();
void CreateArguments(string currentCommandIn, vector<std::string>& arguments);
void PrintVersion();
FHXTIME::Time fakeUseTime;

int main() {
    std::thread counter(TimeCounter);
    PrintVersion();
    debug("Getting Data...", fakeUseTime);
    if (FHXV::UpdateData()) {
        debug("Got Data!\n", fakeUseTime);
    }
    else { 
        debug("Problem at getting Data...\n", fakeUseTime);
        //return 2;
    }
    DisplayCommands(fakeUseTime);
    Start();
	return 0;
}

void Start() {
    string currentCommand;
    getline(cin, currentCommand);
    debug("Using Command: " + currentCommand, fakeUseTime);
    if (GetCommandAction(currentCommand)) {
        Start();
    }
    else {
        debug("Invalid Command!", fakeUseTime);
        Start();
    }
}

bool GetCommandAction(const string& currentCommandIn) {
    string fakePrefix = "--";
    vector<std::string> arguments{};
    CreateArguments(currentCommandIn, arguments);
    if (currentCommandIn.find(fakePrefix) == string::npos) {
        fakePrefix = "";
        debug("Used " + currentCommandIn + " Command without Prefix", fakeUseTime);
    }
    if (currentCommandIn.find(string::npos)) {
        if (currentCommandIn == fakePrefix + "versions -json") {
            CommandPrintData::DoCommand();
            return true;
        }

        if (currentCommandIn.find(fakePrefix + "download") != string::npos) {
            CommandDownload::DoCommand(fakeUseTime, arguments);
            return true;
        }
        if (currentCommandIn == fakePrefix + "update -version") {
            CommandUpdateVersion::DoCommand(fakeUseTime);
            return true;
        }

        if (currentCommandIn == fakePrefix + "help") {
            DisplayCommands(fakeUseTime);
            return true;
        }

        if (currentCommandIn == fakePrefix + "libs") {
            CommandLibs::DoCommand(fakeUseTime);
            return true;
        }

        if (currentCommandIn == fakePrefix + "debug") {
            FHXS::debug = true;
            cout << "Enabled" << endl;
            return true;
        }

        if (currentCommandIn.find(fakePrefix + "discord") != string::npos) {
            CommandDiscord::DoCommandNull(fakeUseTime, arguments);
            return true;
        }

        if (currentCommandIn == fakePrefix + "easteregg") {
            cout << "A";
            char nextChar = 0;

            for (int i = 0; i < 58000; i++) {
                cout << "\r";
                cout << ProgressBarOld(i, 58000, 5000, true);
            }

            for (int i = 0; i < 8800; i++) {
                nextChar += rand() % 5;
                cout << "\r";
                cout << nextChar;
            }
            cout << endl;
            return true;
        }

        if (currentCommandIn == fakePrefix + "progressbar") {
            for (int i = 0; i < 10801; i++) {
                cout << "\r";
                cout << ProgressBar(i, 10801, 500, false) << " : " << i << ";" << 10800 << " :: " << i / 500 << ";" << 10800 / 500;
            }
            cout << endl;
            return true;
        }

        if (currentCommandIn == fakePrefix + "exit") {
            exit(1);
        }
    }
    arguments.clear();
    return false;
}

void TimeCounter() {
    std::this_thread::sleep_for(1s);
    fakeUseTime.seconds++;
    if (fakeUseTime.seconds >= 60) {
        fakeUseTime.minutes++;
        fakeUseTime.seconds = 0;
    }
    TimeCounter();
}

void CreateArguments(string currentCommandIn, vector<std::string>& arguments) {
    string placeholderString = "";
    currentCommandIn.push_back(0x20);
    for (char const& ch : currentCommandIn) {
        if (ch != 0x20) {
            placeholderString.push_back(ch);
        }
        else {
            if (placeholderString.size() != 0) {
                arguments.push_back(placeholderString.c_str());
                placeholderString = "";
            }
        }
    }
}

void PrintVersion() {
    string line = "=-";
    //string title = "Fuchsia Launcher Console V. " + to_string(version);
    string title = "Fuchsia Launcher Console V. 0.2";

    for (int i = 1; i < title.length(); i++)
    {
        line.push_back('-');
    }
    line.push_back('=');
    cout << line + "\n" << " " + title + " \n" << line << endl;
}