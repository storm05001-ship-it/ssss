#include <Windows.h>
#include <iostream>

DWORD WINAPI MainThread(LPVOID lpParam) {
    // Ждем запуск игры
    while (!GetModuleHandle("GTA5.exe")) {
        Sleep(1000);
    }
    
    MessageBoxA(0, "Cheat injected! Press INSERT for menu", "RageMP Cheat", 0);
    
    while (true) {
        // Горячие клавиши
        if (GetAsyncKeyState(VK_INSERT) & 1) {
            // Открываем веб-меню
            system("start http://localhost:8080/menu.html");
        }
        
        if (GetAsyncKeyState(VK_NUMPAD1) & 1) {
            // Добавляем деньги (пример адреса)
            uintptr_t moneyAddr = 0x12345678; // Нужно найти через Cheat Engine
            *(int*)moneyAddr = 9999999;
        }
        
        Sleep(10);
    }
    
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved) {
    if (reason == DLL_PROCESS_ATTACH) {
        CreateThread(0, 0, MainThread, 0, 0, 0);
    }
    return TRUE;
}
