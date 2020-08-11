#include <windows.h>
#include <iostream>
#include <string>
typedef std::string(__stdcall* f_loadData)();
typedef bool(__stdcall* f_available)();

int loadDLL()
{
    HINSTANCE hGetProcIDDLL = LoadLibrary(TEXT("vs0001.dll"));

    if (!hGetProcIDDLL) {
        std::cout << "could not load the dynamic library" << std::endl;
        return EXIT_FAILURE;
    }

    f_loadData loadData = (f_loadData)GetProcAddress(hGetProcIDDLL, "GetData");
    f_available available = (f_available)GetProcAddress(hGetProcIDDLL, "DLL_VS0001_Available");
    if (!loadData) {
        std::cout << "could not locate the function: LoadData" << std::endl;
        return EXIT_FAILURE;
    }
    if (!available) {
        std::cout << "could not locate the function: Available" << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << available();

    return EXIT_SUCCESS;
}