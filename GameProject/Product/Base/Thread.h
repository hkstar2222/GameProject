#ifndef _THREAD_H_
#define _THREAD_H_

#include "BaseDef.h"

struct ThreadInfo_st;

//Ïß³Ì
class DLL_API Thread
{
public:
	Thread();
	~Thread();

	enum Thread_Ret
	{
		RET_CONTINUE = 0,
		RET_BREAK = -1
	};

public:

	_BOOL init(_INT(*p_pFunc)(void), const char* p_strThreadName);

	_BOOL start();

	_BOOL stop();

private:
	ThreadInfo_st*	m_stThreadInfo;
};

#endif	//_THREAD_H_

