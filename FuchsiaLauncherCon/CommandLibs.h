#pragma once
namespace CommandLibs {
	void DoCommand(FHXTIME::Time fakeUseTime) {
		debug("Libraries used:"
			"\nJsoncpp : https://github.com/open-source-parsers/jsoncpp"
			"\ncURL/libcurl : https://curl.haxx.se/"
			"\nlibzip : https://libzip.org/"
			, fakeUseTime);
	}
};