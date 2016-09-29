#ifndef _LOCK_H_
#define _LOCK_H_

#include "BaseDef.h"

//�߳���
class DLL_API MutexLock
{
public:
	MutexLock(const char* p_szName = "");
	~MutexLock();

public:
	void lock();
	void unlock();

private:

	void*	m_pHandle;
};

//�Զ��ӽ�������
class DLL_API AutoLockTool
{
public:
	AutoLockTool(MutexLock* p_objLock);
	~AutoLockTool();

private:
	AutoLockTool();	//��ֹ�޲ι���

private:

	MutexLock*	m_objLock;
};

#define LOCK_MUTEX(_Lock_) AutoLockTool LockTool_##_Lock_(&_Lock_)

#endif	//_LOCK_H_

