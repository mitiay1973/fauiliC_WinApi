#include <Windows.h>
#include <malloc.h>
#include <stdio.h>
int WINAPI WinMain(HINSTANCE hlnstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	HANDLE  FileHandle = CreateFile(L"zadacha.txt",
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_WRITE | FILE_SHARE_READ,
		NULL,
		CREATE_NEW,
		FILE_ATTRIBUTE_HIDDEN| FILE_ATTRIBUTE_ARCHIVE,
		0);

	LPSTR st = "hello"; //calloc(255, 1);
	DWORD d;
	//BOOL b = ReadFile(FileHandle,st,255, &d,NULL);
	WriteFile(FileHandle, st, 255, &d, NULL);
		CloseHandle(FileHandle);
		return 0;
}