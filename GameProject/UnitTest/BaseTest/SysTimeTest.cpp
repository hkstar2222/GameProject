#include "FuncDef.h"
#include "SysTime.h"


TEST_RET TEST_FUNC::testSleepTime()
{
	for (_UINT i = 0; i < 10; ++i)
	{
		printf("wait 1s \n");
		SysTime::wait(1000);
	}
	
	return TEST_RET::SUCCESS;
}


TEST_RET TEST_FUNC::testCurTime()
{
	SysTime_st curTime;

	curTime = SysTime::getCurSysTime();

	printf("%4d/%02d/%02d %02d:%02d:%02d.%03d ÐÇÆÚ%1d UTC=%d\n", 
		curTime.m_nYear, curTime.m_nMonth, curTime.m_nDay, 
		curTime.m_nHour, curTime.m_nMinute, curTime.m_nSecond, curTime.m_nMillisecond, 
		curTime.m_nDayOfWeek, curTime.m_nUTCSecond);

	return TEST_RET::SUCCESS;
}



TEST_RET TEST_FUNC::testPassTime()
{
	SysTime objSysTime;


	objSysTime.setBeginTime();

	SysTime_st curTime;
	curTime = SysTime::getCurSysTime();
	
	objSysTime.setEndTime();

	_UINT_64 ret = objSysTime.getPassTime();

	printf("Pass time = %lld \n", ret);

	return TEST_RET::SUCCESS;
}
