#pragma once
namespace CommandUpdateVersion {
	void DoCommand(FHXTIME::Time fakeUseTime) {
        debug("Updating Data...", fakeUseTime);
        if (FHXV::UpdateData()) {
            debug("Updated Data!", fakeUseTime);
        }
        else {
            debug("Failed to update Data...", fakeUseTime);
        }
	}
};