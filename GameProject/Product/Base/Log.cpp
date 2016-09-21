#include "Log.h"
#include <stdio.h>
#include <stdarg.h>

_INT Log::log(const char* p_szFormat, ...)
{
	char buf[1024] = { '0' };
	va_list args;
	va_start(args, p_szFormat);
	vsprintf_s(buf, sizeof(buf), p_szFormat, args);
	va_end(args);

	_PRINT_("%s", buf);
	return 0;
}

