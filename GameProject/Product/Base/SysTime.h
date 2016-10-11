#ifndef _SYS_TIME_H_
#define _SYS_TIME_H_

//ʱ����ص�Ӧ�ýӿ�

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

class DLL_API SysTime
{
public:
	//�ȴ�	��λ����
	static void wait(_UINT p_nMillisecond);

	//��ȡ��ǰ��ʱ��
	static SysTime_st getCurSysTime();

	//�������ڳ�������ʱ���ʱ
	void setBeginTime();	//��ǿ�ʼʱ��
	void setEndTime();		//��ǽ���ʱ��
	_UINT_64 getPassTime();		//��� setBeginTime �� setEndTime ��ľ���ʱ��	��λ΢��

private:

	_UINT_64	m_nBeginTime;	
	_UINT_64	m_nEndTime;

};

#endif	//_SYS_TIME_H_

