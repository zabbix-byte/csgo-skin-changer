#include <iostream>
#include <Windows.h>
#include <vector>
#include <TlHelp32.h>

char* registry_read_local_machine(LPCTSTR subkey, LPCTSTR name, DWORD type)
{
	HKEY key;
	TCHAR value[100];
	DWORD value_length = 100;
	RegOpenKey(HKEY_LOCAL_MACHINE, subkey, &key);
	RegQueryValueEx(key, name, NULL, &type, (LPBYTE)&value, &value_length);
	RegCloseKey(key);

	char path_steam_result[100];
	wcstombs(path_steam_result, value, wcslen(value) + 1);

	return path_steam_result;

}
