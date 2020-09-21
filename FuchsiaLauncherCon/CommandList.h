#pragma once
void DisplayCommands(FHXTIME::Time fakeUseTime) {
    debug("Available Commands:"
        "\n --versions -json : Shows current Versions Json"
        "\n --versions -write : Writes data to Json"
        "\n --update -version : Updates Version Jsons"
        "\n --help : Shows Commands"
        "\n --libs : Shows used Libraries"
        "\n --legacy : Opens Legacy Launcher (Java)"
        "\n --legacy -download : Downloads Legacy Launcher (Java)"
        "\n --download game type version : Downloads a version of the game; Example: --download riretrim dev 0.0.0.0.7"
        "\n --discord -server : Shows and Opens a Discord Invitation for the given Server"
        "\n --debug Enables Debug-Mode for this Session"
        "\n --exit : Exists the Application"
        , fakeUseTime, false);
}