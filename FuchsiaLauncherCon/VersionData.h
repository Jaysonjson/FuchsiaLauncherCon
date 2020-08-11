#pragma once
#include <json/json.h>
#include <curl/curl.h>
#include <iostream>
#include "Settings.h"
namespace FHXV {
		std::string json;
        Json::Value root;
        Json::Value builds;
        Json::Value windows;
        Json::Value windows_games;
        Json::Value latest;

        size_t WriteCallback(char* contents, size_t size, size_t nmemb, void* userp)
        {
            ((std::string*)userp)->append((char*)contents, size * nmemb);
            return size * nmemb;
        }

        bool UpdateData() {
            CURL* curl;
            CURLcode res;

            curl = curl_easy_init();
            if (curl) {
                curl_easy_setopt(curl, CURLOPT_URL, "https://raw.githubusercontent.com/Jaysonjson/Fuchsia/master/launcher/versions.json");
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &json);
                res = curl_easy_perform(curl);
                curl_easy_cleanup(curl);
                Json::CharReaderBuilder b;
                Json::CharReader* reader(b.newCharReader());
                std::string errors;
                bool parsedSuccess = reader->parse(json.c_str(), json.c_str() + json.length(), &root, &errors);
                if (!parsedSuccess) {
                    std::cout << "Couldn't parse json " << std::endl;
                    if (FHXS::debug) {
                        std::cout << "[FHXV]" << errors << std::endl;
                    }
                    return false;
                }
                builds = root["builds"];
                windows = builds["windows"];
                windows_games = windows["games"];
                latest = root["latest"];
                Json::Value windows_games_riretrim = windows_games["riretrim"];
                Json::Value windows_games_riretrim_dev = windows_games_riretrim["dev"];
                if (FHXS::debug) {
                    std::cout << "[FHXV] Wrote Data on: " << &json << std::endl;
                }
                return true;
            }
            return false;
        }

            std::string GetData() {
                return json;
            }
}