#include <Windows.h>
#include <iostream>

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) 
{
    DWORD old_protect;

    unsigned char* hook_location = (unsigned char*)0x004637E9;

    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH :

        VirtualProtect((void*)hook_location, 2, PAGE_EXECUTE_READWRITE, &old_protect); 
                                                                                    
        *hook_location = 0x90; 
        *(hook_location + 1) = 0x90;
    }
  
    return true;
}
