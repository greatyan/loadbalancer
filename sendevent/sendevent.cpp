// sendevent.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	if (argc != 2) {
		wprintf(L"sendevent <eventName>\n");
		wprintf(L"\tap<PID>_sutdown shutdown Apache process PID\n");
		wprintf(L"\tap<PID>_restart restart Apache process PID\n");
		return 1;
	}

	_TCHAR* eventName = argv[1];
	PSECURITY_ATTRIBUTES sa = NULL; //GetNullACL();
	HANDLE hEvent = CreateEvent(sa, FALSE, FALSE, eventName);
	if (hEvent == 0) {
		//failed to load the error
		//CleanNullACL((void*)sa);
		return 1;
	}
	if (SetEvent(hEvent) == 0) {
		//failed to trigger the event
		CloseHandle(hEvent);
		//CleanNullACL((void*)sa);
		return 1;
	}
	CloseHandle(hEvent);
	//CleanNullACL((void*)sa);
	return 0;
}

