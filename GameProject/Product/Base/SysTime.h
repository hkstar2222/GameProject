#ifndef _SYS_TIME_H_
#define _SYS_TIME_H_

#include "BaseDef.h"


struct SysTime_st
{
	_UINT		m_nYear = 0;
	_UINT		m_nMonth = 0;
	_UINT		m_nDay = 0;
	_UINT		m_nHour = 0;
	_UINT		m_nMinute = 0;
	_UINT		m_nSecond = 0;
	_UINT		m_nMillisecond = 0;
	_UINT		m_nDayOfWeek = 0;

	_UINT_64	m_nUTCSecond = 0;	//1970到现在的秒数

};

class SysTime
{
public:

	//获取当前的时间
	DLL_API static SysTime_st getCurSysTime();

	//以下用于程序运行时间计时
	DLL_API void setBeginTime();	//标记开始时间
	DLL_API void setEndTime();		//标记结束时间
	DLL_API _UINT_64 getPassTime();		//获得 setBeginTime 和 setEndTime 间的经过时间	单位微秒

private:

	_UINT_64	m_nBeginTime;	
	_UINT_64	m_nEndTime;

};

#endif	//_SYS_TIME_H_

