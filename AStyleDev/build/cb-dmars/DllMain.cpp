#include <windows.h>

extern "C" BOOL APIENTRY DllMain(HINSTANCE, DWORD fdwReason, LPVOID)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
 //           MessageBox(0, "ATTACH", "DLL Message", MB_OK | MB_ICONINFORMATION);
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
 //           MessageBox(0, "DETACH", "DLL Message", MB_OK | MB_ICONINFORMATION);
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}
