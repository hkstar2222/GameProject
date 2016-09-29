#include "Thread.h"


namespace NS_Thread
{
	DWORD WINAPI Func(LPVOID pM)
	{
		_INT(*pFunc)(void) = (_INT(*)(void))pM;

		while (true)
		{
			if (pFunc() != 0)
			{
				break;
			}
		}
		
		return 0;
	}
};




#ifdef WIN32

Thread::Thread()
{

}

Thread::~Thread()
{

}



_INT Thread::init(_INT(*p_pFunc)(void), const char* p_strThreadName)
{
	m_pFunc = p_pFunc;

	//DWORD (*pFunc)(LPVOID) = &Func;
	
	CreateThread(NULL, 0, NS_Thread::Func, m_pFunc, 0, NULL);


	return 0;
}

_BOOL Thread::start()
{
	return true;
}

_BOOL Thread::stop()
{
	return false;
}


#endif	//WIN32



