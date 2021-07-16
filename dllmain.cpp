#include "pch.h"
#include "offsets.h"

uintptr_t BaseAddress = Utility::CustomAPI::GetModuleA("POLYGON-Win64-Shipping.exe"); // game base

typedef bool(__fastcall* t_OnShoot)(__int64 instance);
t_OnShoot sub_OnShoot = (t_OnShoot)(BaseAddress + c_onshoot); // define as a function to recall at the end of the hook

uintptr_t OnShootInstance = 0;

bool __fastcall OnShoot(__int64 instance) {
    OnShootInstance = instance;
    return sub_OnShoot(instance);
}

DWORD WINAPI MainThread()
{
    MessageBox(0, "Made by GoLang#9039", "Success Injection", MB_ICONINFORMATION);

    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourAttach(&(LPVOID&)sub_OnShoot, &OnShoot); // initialize hook for retrieving weapon instance
    DetourTransactionCommit();

    AItem_Weapon_General* AItem_General = nullptr; // define weapon class

    while (!GetAsyncKeyState(VK_END)) {
        AItem_General = (AItem_Weapon_General*)(OnShootInstance);

        if (GetAsyncKeyState(VK_F1) & 1) {
            if (OnShootInstance > 0) {
                AItem_General->WeaponDamage = (int32_t)1337;
                AItem_General->TimeBetweenShots = (float)0.01f; // tip: use a value up to 0.f
                AItem_General->WeaponRecoil = (float)0.f;
                AItem_General->AccuracyHip = (float)0.f;
                AItem_General->AccuracySight = (float)0.f;
                AItem_General->SpreadShot = (float)0.f;
                AItem_General->CurrentMagazineAmmo = (int32_t)999;
                AItem_General->CurrentStockAmmo = (uint16_t)999;
            }
            else
                MessageBox(NULL, "Please give a shoot to initialize", "Error", MB_ICONERROR);
        }
    }

    return 0;
}

bool __stdcall DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CloseHandle(CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)MainThread, 0, 0, NULL)); // close handle and create a single-threaded function
    case DLL_PROCESS_DETACH:
        break;
    }

    return true;
}