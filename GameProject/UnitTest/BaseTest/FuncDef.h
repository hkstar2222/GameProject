#include "BaseDef.h"
#include <stdio.h>

enum TEST_RET
{
	SUCCESS = 0,
	FAILED = -1,
};


namespace TEST_FUNC
{
	TEST_RET testRandom();

	TEST_RET testPassTime();

	TEST_RET testCurTime();

	TEST_RET testLog();

	TEST_RET testThread();

	TEST_RET testSleepTime();

	TEST_RET testThreadCreate_mem();	//ÄÚÑ­»·  ²âÄÚ´æÐ¹Â©

	TEST_RET testLockClass();
};


