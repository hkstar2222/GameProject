#include "FuncDef.h"
#include <malloc.h>


#include <Windows.h>

DWORD WINAPI Func(LPVOID pM)
{
	return 0;
}


int main()
{
	//TEST_FUNC::testXmlTool();

	//TEST_FUNC::testPassTime();

	//TEST_FUNC::testCurTime();

	//TEST_FUNC::testLog();

	//DWORD(*pFunc)(LPVOID) = &Func;

	CreateThread(NULL, 0, Func, NULL, 0, NULL);

	getchar();
}