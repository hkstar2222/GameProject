#include "Thread.h"


#ifdef WIN32
#include <Windows.h>
#include <process.h>

#define THREAD_NAME_LEN	 64

union FuncUnion
{
	_INT(*Func_thread)(void*);
	_INT(*Func_class)();
};

struct ThreadInfo_st
{
	char		m_szThreadName[THREAD_NAME_LEN];
	_BOOL		m_bRunFlag = false;
	_INT		m_nHandler = 0;
	void*		m_pObjPoint = NULL;
	FuncUnion	m_uThreadPoint;
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

_BOOL Thread::init(_INT(*p_pFunc)(), void* p_pObjPoint, const char* p_strThreadName)
{
	m_stThreadInfo->m_uThreadPoint.Func_class = p_pFunc;
	m_stThreadInfo->m_pObjPoint = p_pObjPoint;
	strcpy_s(m_stThreadInfo->m_szThreadName, sizeof(m_stThreadInfo->m_szThreadName) - 1, p_strThreadName);

	return true;
}

_INT Thread::threadFunc()
{
	while (m_stThreadInfo->m_bRunFlag)
	{
		if (m_stThreadInfo->m_uThreadPoint.Func_thread(m_stThreadInfo->m_pObjPoint) != Thread::RET_CONTINUE)
		{
			m_stThreadInfo->m_bRunFlag = false;
			break;
		}
	}

	return 0;
}

_BOOL Thread::start()
{
	if (m_stThreadInfo->m_bRunFlag) {
		return true;
	}

	union
	{
		//DWORD(*FUNC_thread)(void*);
		_INT(Thread::*FUNC_class)();
		void(*ThreadProc)(void *);

	} proc;

	proc.FUNC_class = &Thread::threadFunc;

	m_stThreadInfo->m_bRunFlag = true;
	_INT nRet = (_INT)_beginthread(proc.ThreadProc, 0, this);
	if (-1 == nRet)
	{
		return false;
	}

	m_stThreadInfo->m_nHandler = nRet;
	return true;
}

void Thread::stop()
{
	m_stThreadInfo->m_bRunFlag = false;
	DWORD ret = STILL_ACTIVE;
	while (true)
	{
		BOOL bRet = GetExitCodeThread(reinterpret_cast<HANDLE>(m_stThreadInfo->m_nHandler), &ret);
		if ((ret != STILL_ACTIVE)
			|| (0 == bRet))
		{
			break;
		}
	}

	//CloseHandle(reinterpret_cast<HANDLE>(m_stThreadInfo->m_nHandler));
	//CloseHandle((void*)m_stThreadInfo->m_nHandler);
	return;
}

#endif	//WIN32



