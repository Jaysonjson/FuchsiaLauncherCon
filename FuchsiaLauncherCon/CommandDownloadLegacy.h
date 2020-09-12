#pragma once
namespace CommandDownloadLegacy {
	void DoCommand(FHXTIME::Time fakeUseTime) {
        wchar_t* link = new wchar_t[4096];
        MultiByteToWideChar(CP_ACP, 0, FHXV::root["legacy"].asCString(), -1, link, 4096);
        debug("Downloading...", fakeUseTime);
        HRESULT result = URLDownloadToFile(NULL, link, L"FuchsiaLauncherLegacy.jar", 0, NULL);
        if (result == 0) {
            debug("Downloaded! [" + std::to_string(GetFileSize("FuchsiaLauncherLegacy.jar")) + " Bytes]", fakeUseTime);
        }
        else {
            debug("Couldn't download! >> " + result, fakeUseTime);
        }
        delete[] link;
	}
};