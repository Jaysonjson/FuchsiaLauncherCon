#pragma once
namespace CommandDownload {
    using namespace std;
    void DoTask(FHXTIME::Time fakeUseTime, std::vector<std::string> arguments);

    void DoCommand(FHXTIME::Time fakeUseTime, std::vector<std::string> arguments) {
        std::thread commandThread(DoTask, fakeUseTime, arguments);
        commandThread.detach();
    }

    void DoTask(FHXTIME::Time fakeUseTime, std::vector<std::string> arguments) {
        if (arguments.size() >= 3) {
            std::string gameInput = arguments[1];
            std::string typeInput = arguments[2];
            std::string versionInput = arguments[3];
            if (FHXV::windows_games[gameInput]) {
                Json::Value windows_game = FHXV::windows_games[gameInput];
                if (windows_game[typeInput]) {
                    Json::Value windows_game_type = windows_game[typeInput];
                    if (windows_game_type[versionInput]) {
                        Json::Value version = windows_game_type[versionInput];
                        debug(arguments[1] + "_" + arguments[2] + "_" + arguments[3], fakeUseTime);
                        string usedLink = windows_game_type[versionInput]["url"].asCString();
                        debug("Found Build! [" + versionInput + "::Win]", fakeUseTime);
                        debug("Downloading [" + usedLink + "]", fakeUseTime);
                        wchar_t* link = new wchar_t[4096];
                        MultiByteToWideChar(CP_ACP, 0, usedLink.c_str(), -1, link, 4096);
                        std::string fileNameString = gameInput + typeInput + ".zip";
                        debug("Will save as: " + fileNameString, fakeUseTime);
                        wchar_t* fileName = new wchar_t[4096];
                        MultiByteToWideChar(CP_ACP, 0, fileNameString.c_str(), -1, fileName, 4096);
                        HRESULT result = URLDownloadToFile(NULL, link, fileName, 0, NULL);
                        if (result == 0) {
                            debug("Downloaded!", fakeUseTime);
                        }
                        else {
                            debug("Couldn't download! >> " + result, fakeUseTime);
                        }
                        delete[] link;
                        delete[] fileName;
                    }
                    else {
                        debug("Version " + versionInput + " not found for Game " + gameInput + " in " + typeInput, fakeUseTime);

                    }
                }
                else {
                    debug("Type " + typeInput + " not found for Game " + gameInput, fakeUseTime);
                }
            }
            else {
                debug("Game " + gameInput + " not found for Platform Windows", fakeUseTime);
            }
        }
    }
};