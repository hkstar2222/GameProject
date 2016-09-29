#include "BaseDef.h"
#include <stdio.h>

enum TEST_RET
{
	SUCCESS = 0,
	FAILED = -1,
};


namespace TEST_FUNC
{
	_INT testRandom();

	_INT testPassTime();

	_INT testCurTime();

	_INT testLog();

	_INT testDbServer();
};


