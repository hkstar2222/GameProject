#include "FuncDef.h"
#include "SysTime.h"


_INT TEST_FUNC::testCurTime()
{
	SysTime_st curTime;

	curTime = SysTime::getCurSysTime();

	D_LOG("%4d/%02d/%02d %02d:%02d:%02d.%03d ����%1d UTC=%d\n", 
		curTime.m_nYear, curTime.m_nMonth, curTime.m_nDay, 
		curTime.m_nHour, curTime.m_nMinute, curTime.m_nSecond, curTime.m_nMillisecond, 
		curTime.m_nDayOfWeek, curTime.m_nUTCSecond);

	return TEST_RET::SUCCESS;
}



_INT TEST_FUNC::testPassTime()
{
	SysTime objSysTime;


	objSysTime.setBeginTime();

	SysTime_st curTime;
	curTime = SysTime::getCurSysTime();
	
	objSysTime.setEndTime();

	_UINT_64 ret = objSysTime.getPassTime();

	D_LOG("Pass time = %lld \n", ret);

	return TEST_RET::SUCCESS;
}