#include "Lock.h"


#ifdef WIN32
#include <Windows.h>

MutexLock::MutexLock(const char* p_szName)
:m_pHandle(NULL)
{
	HANDLE hMutex = CreateMutex(NULL, TRUE, p_szName);
	if (hMutex)
	{
		if (ERROR_ALREADY_EXISTS == GetLastError())
		{
			_PRINT_("MutexLock ERROR_ALREADY_EXISTS");
			return;
		}
	}

	m_pHandle = (void*)hMutex;

}

MutexLock::~MutexLock()
{
	if (m_pHandle == NULL)
	{
		return;
	}

	ReleaseMutex(m_pHandle);
	CloseHandle(m_pHandle);
	m_pHandle = NULL;
}

void MutexLock::lock()
{
	if (m_pHandle != NULL)
	{
		WaitForSingleObject(m_pHandle, INFINITE);
	}
}

void MutexLock::unlock()
{
	if (m_pHandle != NULL)
	{
		ReleaseMutex(m_pHandle);
	}
}


AutoLockTool::AutoLockTool(MutexLock* p_objLock)
:m_objLock(p_objLock)
{
	if (m_objLock != NULL)
	{
		m_objLock->lock();
	}
}

AutoLockTool::~AutoLockTool()
{
	if (m_objLock != NULL)
	{
		m_objLock->unlock();
	}
}

#endif


