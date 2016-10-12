#include "FuncDef.h"
#include "Thread.h"

#include "SysTime.h"
#include <stdio.h>


class ThreadClass
{

public:
	_BOOL start();
	void stop();

	int m_nNum;

private:
	_INT _THREAD_FUNC_ ThreadFunc();

private:
	Thread m_nThread;
	
};

_BOOL ThreadClass::start()
{
	_BOOL bRet = m_nThread.init(&ThreadClass::ThreadFunc, this, "test");
	if (!bRet)
	{
		return false;
	}
	
	return m_nThread.start();
}

void ThreadClass::stop()
{
	m_nThread.stop();
}

_INT ThreadClass::ThreadFunc()
{
	m_nNum++;
	_PRINT_("ThreadClass....%d %p \n", m_nNum, this);
	SysTime::wait(200);
	return Thread::RET_CONTINUE;
}



TEST_RET TEST_FUNC::testThread()
{

	ThreadClass objThreadClass;
	objThreadClass.m_nNum = 100;
	_BOOL bRet = objThreadClass.start();
	_PRINT_("objThreadClass.... %p\n", &objThreadClass);
	getchar();
	objThreadClass.stop();

	getchar();

	return TEST_RET::SUCCESS;
}


TEST_RET TEST_FUNC::testThreadCreate_mem()
{

	while (true)
	{
		ThreadClass objThreadClass;
		objThreadClass.m_nNum = 100;
		_BOOL bRet = objThreadClass.start();
		SysTime::wait(1000);

		ThreadClass objThreadClass1;
		objThreadClass1.m_nNum = 200;
		bRet = objThreadClass1.start();
		SysTime::wait(1000);

	}

	return TEST_RET::SUCCESS;
}