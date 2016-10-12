#ifndef _THREAD_H_
#define _THREAD_H_

#include "BaseDef.h"

#define _THREAD_FUNC_	__cdecl	//�̺߳�����ʶ  win�µĶ����̻߳ص� ���������˱�ʶ
//���ӣ� _INT _THREAD_FUNC_ ThreadFunc();

struct ThreadInfo_st;

//�̷߳�װ��
//֧�ֶ����ڲ���������
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
	//��ʼ��  �󶨻ص�����
	//p_pFunc�� �ص��ķ���ָ��
	//p_pObj�� �ص��������ڵĶ���ָ��
	//p_strThreadName�� �߳�����
	template<class T>
	_BOOL init(_INT(_THREAD_FUNC_ T::*p_pFunc)(), void* p_pObj, const char* p_strThreadName)
	{
		union
		{
			_INT(_THREAD_FUNC_ T::*pClassFunc)();
			_INT(*pFunc)();
		} uThreadFunc;
		uThreadFunc.pClassFunc = p_pFunc;

		return init(uThreadFunc.pFunc, p_pObj, p_strThreadName);
	}

	_BOOL init(_INT(*p_pFunc)(), void* p_pObjPoint, const char* p_strThreadName);


	//��ʼ�߳�  ʧ�ܷ���false
	_BOOL start();

	//ֹͣ�߳�	
	void stop();

private:
	_INT threadFunc();

private:
	ThreadInfo_st*	m_stThreadInfo;
};


#endif	//_THREAD_H_

