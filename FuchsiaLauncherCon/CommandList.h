#pragma once
void DisplayCommands(FHXTIME::Time fakeUseTime) {
    debug("Available Commands:"
        "\n --versions -json : Shows current Versions Json"
        "\n --update -version : Updates Version Jsons"
        "\n --help : Shows Commands"
        "\n --libs : Shows used Libraries"
        "\n --download game type version : Downloads a version of the game; Example: --download riretrim dev 0.0.0.0.7"
        "\n --discord -fuchsia : Shows and Opens a Discord Invitation for the Fuchsia Server"
        "\n --discord -graviarts : Shows and Opens a Discord Invitation for the Graviarts Server"
        "\n --debug Enables Debug-Mode for this Session"
        "\n --exit : Exists the Application", fakeUseTime);
}