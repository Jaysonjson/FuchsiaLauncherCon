#include "VersionData.h"
size_t WriteCallback(char* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

bool UpdateVersionData(VersionsData &vs) {
    CURL* curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://raw.githubusercontent.com/Jaysonjson/Fuchsia/master/launcher/versions.json");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &vs.json);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        Json::CharReaderBuilder b;
        Json::CharReader* reader(b.newCharReader());
        std::string errors;
        bool parsedSuccess = reader->parse(vs.json.c_str(), vs.json.c_str() + vs.json.length(), &vs.root, &errors);
        if (!parsedSuccess) {
            std::cout << "Couldn't parse json " << std::endl;
            /*if (FHXS::debug) {
                std::cout << "[FHXV]" << errors << std::endl;
            }*/
            return false;
        }
        vs.builds = vs.root["builds"];
        vs.windows = vs.builds["windows"];
        vs.windows_games = vs.windows["games"];
        vs.latest = vs.root["latest"];
        Json::Value windows_games_riretrim = vs.windows_games["riretrim"];
        Json::Value windows_games_riretrim_dev = windows_games_riretrim["dev"];
        /*if (FHXS::debug) {
            std::cout << "[FHXV] Wrote Data on: " << &vs.json << std::endl;
        }*/
        return true;
    }
    return false;
}
