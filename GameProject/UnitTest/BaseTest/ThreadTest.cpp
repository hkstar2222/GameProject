#include "FuncDef.h"
#include "Thread.h"


_INT ThreadFunc()
{
	_PRINT_("ThreadFunc....\n");

	return Thread::RET_CONTINUE;
}



TEST_RET TEST_FUNC::testThread()
{
	
		Thread tmp;
		_BOOL bRet = tmp.init(ThreadFunc, "ThreadName");
		bRet = tmp.start();
		_PRINT_("1111111");
		

	getchar();


	return TEST_RET::SUCCESS;
}
