#include "FuncDef.h"
#include "Thread.h"
#include "SysTime.h"


//class MyClass
//{
//public:
//	MyClass();
//	~MyClass();
//
//private:
//	_INT ThreadFunc();
//
//private:
//	Thread tmp;
//};
//
//MyClass::MyClass()
//{
//	tmp
//}
//
//MyClass::~MyClass()
//{
//}
//
//_INT MyClass::ThreadFunc()
//{
//	_PRINT_("ThreadFunc....\n");
//}

_INT ThreadFunc()
{
	static _INT i = 0;
	SysTime::wait(500);
	i++;
	_PRINT_("ThreadFunc....%d\n", i);

	return Thread::RET_CONTINUE;
}



TEST_RET TEST_FUNC::testThread()
{
	while (true)
	{
		_PRINT_("new thread \n");
		Thread tmp;
		_BOOL bRet = tmp.init(ThreadFunc, "ThreadName", NULL);
		bRet = tmp.start();
		
		SysTime::wait(2000);

		_PRINT_("new thread 1 \n");
		Thread tmp1;
		bRet = tmp1.init(ThreadFunc, "ThreadName1", NULL);
		bRet = tmp1.start();

		SysTime::wait(2000);

	}

	getchar();

	return TEST_RET::SUCCESS;
}
