#pragma once
#include <curl/curl.h>
#include "VersionData.h"
namespace CommandPrintData {
	void DoCommand() {
		if (FHXV::json != "") {
			std::cout << FHXV::json;
		}
		else {
			std::cout << "json seems empty..." << std::endl;
		}
	}
}