#include "SysTime.h"
#include <time.h>

#ifdef WIN32
#include <windows.h>


void SysTime::wait(_UINT p_nMillisecond)
{
	Sleep(p_nMillisecond);
}

SysTime_st SysTime::getCurSysTime()
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);

	SysTime_st retTime;
	retTime.m_nYear = sys.wYear;
	retTime.m_nMonth = sys.wMonth;
	retTime.m_nDay = sys.wDay;
	retTime.m_nHour = sys.wHour;
	retTime.m_nMinute = sys.wMinute;
	retTime.m_nSecond = sys.wSecond;
	retTime.m_nMillisecond = sys.wMilliseconds;
	retTime.m_nDayOfWeek = sys.wDayOfWeek;

	retTime.m_nUTCSecond = (_UINT_64)time(0);		//1970到现在的秒数

	return retTime;
}

void SysTime::setBeginTime()
{
	LARGE_INTEGER   litmp;
	QueryPerformanceCounter(&litmp);
	m_nBeginTime = (_UINT_64)litmp.QuadPart;
}

void SysTime::setEndTime()
{
	LARGE_INTEGER   litmp;
	QueryPerformanceCounter(&litmp);
	m_nEndTime = (_UINT_64)litmp.QuadPart;
}

_UINT_64 SysTime::getPassTime()
{
	LARGE_INTEGER  feq;
	QueryPerformanceFrequency(&feq);
	_DOUBLE nSec = ((_DOUBLE)m_nEndTime - (_DOUBLE)m_nBeginTime) / (_DOUBLE)feq.QuadPart;
	return (_UINT_64)(nSec * 1000000);
}

#endif // WIN32

//
//#include <iostream>  
//#include <string>  
//#include <stdio.h>  
//#include <sys/time.h>  
//#include <time.h>  
//#include <unistd.h>  

//struct timeval tv;
//gettimeofday(&tv, NULL);
//struct tm* pTime;
//pTime = localtime(&tv.tv_sec);

//charsTemp[30] = { 0 };
//snprintf(sTemp, sizeof(sTemp), "%04d%02d%02d%02d%02d%02d%03d%03d", pTime->tm_year + 1900, \
	//		pTime->tm_mon + 1, pTime->tm_mday, pTime->tm_hour, pTime->tm_min, pTime->tm_sec, \
	//		tv.tv_usec / 1000, tv.tv_usec % 1000);
//return (string)sTemp;