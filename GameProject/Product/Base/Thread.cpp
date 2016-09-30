#include "Thread.h"


#ifdef WIN32
#include <Windows.h>

#define THREAD_NAME_LEN	 64

struct ThreadInfo_st
{
	char		m_szThreadName[THREAD_NAME_LEN];
	_INT(*m_pFunc)() = NULL;
	_BOOL		m_bRunFlag = false;
	_INT		m_nHandler = 0;
};

namespace NS_Thread
{
	DWORD WINAPI Func(LPVOID pM)
	{
		ThreadInfo_st* pThreadInfo = (ThreadInfo_st*)pM;

		while (pThreadInfo->m_bRunFlag)
		{
			if (pThreadInfo->m_pFunc() != Thread::RET_CONTINUE)
			{
				pThreadInfo->m_bRunFlag = false;
				break;
			}
		}
		
		return 0;
	}
};


Thread::Thread()
:m_stThreadInfo(new ThreadInfo_st())
{

}

Thread::~Thread()
{
	stop();
	delete m_stThreadInfo;
}



_BOOL Thread::init(_INT(*p_pFunc)(void), const char* p_strThreadName)
{
	m_stThreadInfo->m_pFunc = p_pFunc;
	strcpy_s(m_stThreadInfo->m_szThreadName, sizeof(m_stThreadInfo->m_szThreadName) - 1, p_strThreadName);

	return true;
}

_BOOL Thread::start()
{
	if (m_stThreadInfo->m_bRunFlag)
	{
		return true;
	}

	m_stThreadInfo->m_bRunFlag = true;
	HANDLE hHandle = CreateThread(NULL, 0, NS_Thread::Func, m_stThreadInfo, 0, NULL);
	m_stThreadInfo->m_nHandler = (_INT)hHandle;

	return true;
}

_BOOL Thread::stop()
{
	m_stThreadInfo->m_bRunFlag = false;
	DWORD ret = STILL_ACTIVE;
	while (true)
	{
		BOOL bRet = GetExitCodeThread((void*)m_stThreadInfo->m_nHandler, &ret);
		if (ret != STILL_ACTIVE)
		{
			break;
		}
	}

	CloseHandle((void*)m_stThreadInfo->m_nHandler);
	return true;
}


#endif	//WIN32



