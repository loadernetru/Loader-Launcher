// Loader Launcher.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Loader Launcher.h"
#include <string>
#include <Windows.h>
#include <ShlObj.h> // For SHGetKnownFolderPath and FOLDERID_LocalAppData
#include <Urlmon.h>


#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
//ATOM                MyRegisterClass(HINSTANCE hInstance);
//BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.
    std::wstring df;
    PWSTR pszPath = nullptr;
    HRESULT hr = SHGetKnownFolderPath(FOLDERID_LocalAppData, 0, nullptr, &pszPath);
    if (SUCCEEDED(hr)) {
        LPCWSTR pszPathFull = pszPath; // +L"Loader";
        df = std::wstring(pszPath) + L"\\Loader\\loaderenv";
        SetCurrentDirectory(df.c_str());
        system("powershell -WindowStyle hidden -ExecutionPolicy Bypass -F run.ps1");
        return (int)0;
    }
    else {
        return (int)2;
    }
}


