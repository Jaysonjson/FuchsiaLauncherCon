#include "WinRegistry.h"
/*BOOL readUserInfoFromRegistry(HKEY hKeyParent, PWCHAR* readData)
{
    HKEY hKey;
    DWORD len = 1024;
    DWORD readDataLen = len;
    PWCHAR readBuffer = (PWCHAR)malloc(sizeof(PWCHAR) * len);
    if (readBuffer == NULL)
        return FALSE;
    //Check if the registry exists
    DWORD Ret = RegOpenKeyEx(
        hKeyParent,
        L"Software\\FuchsiaTest",
        0,
        KEY_READ,
        &hKey
    );
    if (Ret == ERROR_SUCCESS)
    {
        Ret = RegQueryValueEx(
            hKey,
            L"mc",
            NULL,
            NULL,
            (BYTE*)readBuffer,
            &readDataLen
        );
        while (Ret == ERROR_MORE_DATA)
        {
            // Get a buffer that is big enough.
            len += 1024;
            readBuffer = (PWCHAR)realloc(readBuffer, len);
            readDataLen = len;
            Ret = RegQueryValueEx(
                hKey,
                L"mc",
                NULL,
                NULL,
                (BYTE*)readBuffer,
                &readDataLen
            );
        }
        if (Ret != ERROR_SUCCESS)
        {
            RegCloseKey(hKey);
            return false;;
        }
        *readData = readBuffer;
        RegCloseKey(hKey);
        return true;
    }
    else
    {
        return false;
    }
}
void ts() {
    DWORD Ret;
    HKEY hKey;
    //Check if the registry exists
    Ret = RegOpenKeyEx(
        HKEY_CURRENT_USER,
        L"Software\\FuchsiaTest",
        0,
        KEY_WRITE,
        &hKey
    );
    if (Ret == ERROR_SUCCESS)
    {
        if (ERROR_SUCCESS !=
            RegSetValueEx(
                hKey,
                L"mc",
                0,
                REG_SZ,
                (LPBYTE)("thefuck"),
                ((((DWORD)lstrlen(L"thefuck") + 1)) * 2)))
        {
            RegCloseKey(hKey);
        }
        RegCloseKey(hKey);
    }
}

int main() {
    CreateDirectory(L"data", NULL);
    DWORD dwDisposition; //It verify new key is created or open existing key
    HKEY  hKey;
    DWORD Ret;
    Ret =
        RegCreateKeyEx(
            HKEY_CURRENT_USER,
            L"Software\\FuchsiaTest",
            0,
            NULL,
            REG_OPTION_NON_VOLATILE,
            KEY_ALL_ACCESS,
            NULL,
            &hKey,
            &dwDisposition);
    if (Ret != ERROR_SUCCESS)
    {
        printf("Error opening or creating key.\n");
        return FALSE;
    }
    RegCloseKey(hKey);
    ts();
    BOOL status;
    DWORD readData;
    PWCHAR readMessage = nullptr;
    status = readUserInfoFromRegistry(HKEY_CURRENT_USER, &readMessage); //read string
    if (status != TRUE)
        return FALSE;
    if (readMessage != nullptr)
    {
        cout << *readMessage << endl;
        free(readMessage);
        readMessage = nullptr;
    }
}
*/