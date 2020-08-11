#pragma once
std::string ProgressBarOld(int progress, int maxProgress, int percent, bool text) {
    std::string bar = "[";
    int mid = (maxProgress / 2) / percent;
    for (int i = 0; i < progress / percent; i++) {
        bar += "#";
        if (mid == i) {
            bar += (int)((float)(progress / maxProgress) * 100);
            bar += "%";
        }
    }
    for (int i = (progress / percent); i < (maxProgress / percent); i++) {
        bar += "-";
        if (mid == i) {
            bar += progress + "";
            bar += "%";
        }
    }
    bar += "]";
    return bar;
}

std::string ProgressBar(int progress, int maxProgress, int percent, bool text) {
    std::string bar = "[";
    int mid = (maxProgress / 2) / percent;
    for (int i = 0; i < progress / percent; i++) {
        bar += "#";
        if (mid == i && text) {
            //bar += (int)((float)(progress / maxProgress) * 100);
            bar += "%";
        }
    }
    for (int i = (progress / percent); i < (maxProgress / percent); i++) {
        bar += "-";
        if (mid == i && text) {
            //bar += progress + "";
            bar += "%";
        }
    }
    bar += "]";
    return bar;
}