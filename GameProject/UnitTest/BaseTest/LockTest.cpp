#include "FuncDef.h"
#include "Thread.h"
#include "SysTime.h"
#include <vector>
#include "Lock.h"

class ResourceClass
{

public:

	ResourceClass()
		:m_objMutexLock("123")
		, m_objMutexLock1("123")
	{

	}

	_INT _THREAD_FUNC_ add()
	{
		LOCK_MUTEX(m_objMutexLock1);
		LOCK_MUTEX(m_objMutexLock);
		m_objList.push_back(0);
		_PRINT_("List size %d\n", m_objList.size());

		return Thread::RET_CONTINUE;
	}

	_INT _THREAD_FUNC_ del()
	{
		LOCK_MUTEX(m_objMutexLock1);
		LOCK_MUTEX(m_objMutexLock);
		if (m_objList.size() != 0)
		{
			m_objList.pop_back();
		}
		_PRINT_("List size %d\n", m_objList.size());

		return Thread::RET_CONTINUE;
	}


private:
	MutexLock	m_objMutexLock;
	MutexLock	m_objMutexLock1;
	std::vector<_INT>	m_objList;
};



TEST_RET TEST_FUNC::testLockClass()
{
	ResourceClass objResourceClass;

	Thread Thread1;
	Thread Thread2;

	Thread1.init(&ResourceClass::add, &objResourceClass, "addThread");
	Thread2.init(&ResourceClass::del, &objResourceClass, "delThread");

	Thread1.start();
	Thread2.start();

	getchar();

	return TEST_RET::SUCCESS;
}