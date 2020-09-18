#pragma once
#include <json/json.h>
#include <curl/curl.h>
#include <iostream>
#include "Settings.h"
struct VersionsData;
size_t WriteCallback(char* contents, size_t size, size_t nmemb, void* userp);
bool UpdateVersionData(VersionsData& vs);

struct VersionsData
{
    std::string json;
    Json::Value root;
    Json::Value builds;
    Json::Value windows;
    Json::Value windows_games;
    Json::Value latest;
};
