#ifndef _THREAD_H_
#define _THREAD_H_

#include "BaseDef.h"

#define THREAD_NAME_LEN	 64

#ifdef WIN32
#include <Windows.h>

//Ïß³Ì
class DLL_API Thread
{
public:
	Thread();
	~Thread();

public:

	_INT init(_INT (*p_pFunc)(void), const char* p_strThreadName);

	_BOOL start();

	_BOOL stop();


private:
	char		m_strThreadName[THREAD_NAME_LEN];

	_INT		(*m_pFunc)();
};

#endif //WIN32
#endif	//_THREAD_H_

