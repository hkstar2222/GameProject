#ifndef _THREAD_H_
#define _THREAD_H_

#include "BaseDef.h"

#define _THREAD_FUNC_	__cdecl	//线程函数标识  win下的对象线程回调 必须声明此标识
//例子： _INT _THREAD_FUNC_ ThreadFunc();

struct ThreadInfo_st;

//线程封装类
//支持对象内部方法调用
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
	//初始化  绑定回调方法
	//p_pFunc： 回调的方法指针
	//p_pObj： 回调方法所在的对象指针
	//p_strThreadName： 线程名称
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


	//开始线程  失败返回false
	_BOOL start();

	//停止线程	
	void stop();

private:
	_INT threadFunc();

private:
	ThreadInfo_st*	m_stThreadInfo;
};


#endif	//_THREAD_H_

