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

	_UINT_64	m_nUTCSecond = 0;	//1970�����ڵ�����

};

class SysTime
{
public:

	//��ȡ��ǰ��ʱ��
	DLL_API static SysTime_st getCurSysTime();

	//�������ڳ�������ʱ���ʱ
	DLL_API void setBeginTime();	//��ǿ�ʼʱ��
	DLL_API void setEndTime();		//��ǽ���ʱ��
	DLL_API _UINT_64 getPassTime();		//��� setBeginTime �� setEndTime ��ľ���ʱ��	��λ΢��

private:

	_UINT_64	m_nBeginTime;	
	_UINT_64	m_nEndTime;

};

#endif	//_SYS_TIME_H_

