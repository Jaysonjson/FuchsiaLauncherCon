#pragma once
namespace CommandWriteVersion {

	void DoCommand(FHXTIME::Time fakeUseTime) {
		std::ofstream versionFile;
		versionFile.open("data/versions.json");
		versionFile << FHXV::json;
		versionFile.close();
		debug("Wrote Data [" + std::to_string(std::filesystem::file_size("data/versions.json")) + " Bytes]", fakeUseTime);
	}

};