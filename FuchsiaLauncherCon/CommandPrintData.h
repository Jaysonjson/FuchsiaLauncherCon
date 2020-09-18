#pragma once
#include <curl/curl.h>
#include "VersionData.h"
namespace CommandPrintData {
	void DoCommand(VersionsData& vsData) {
		if (vsData.json != "") {
			std::cout << vsData.json;
		}
		else {
			std::cout << "json seems empty..." << std::endl;
		}
	}
}