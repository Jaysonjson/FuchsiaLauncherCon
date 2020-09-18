#pragma once
namespace CommandUpdateVersion {
	void DoCommand(FHXTIME::Time fakeUseTime, VersionsData& vsData) {
        debug("Updating Data...", fakeUseTime);
        if (UpdateVersionData(vsData)) {
            debug("Updated Data!", fakeUseTime);
        }
        else {
            debug("Failed to update Data...", fakeUseTime);
        }
	}
};