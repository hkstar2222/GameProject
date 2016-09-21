#include "FuncDef.h"
#include "Random.h"

#include <map>

_INT TEST_FUNC::testRandom()
{
	_INT nMin = 1;
	_INT nMax = 2;
	_UINT nRunTimes = 100000;
	std::map<_INT, _UINT> retList;

	for (_INT i = nMin; i <= nMax; ++i)
	{
		retList.insert(std::pair<_INT, _UINT>(i, 0));
	}

	for (_UINT i = 0; i < nRunTimes; i++)
	{
		_INT nRandnum = Random::getRandomNum(nMin, nMax);
		++retList[nRandnum];
	}

	std::map<_INT, _UINT>::const_iterator itor = retList.begin();

	for (; itor != retList.end(); ++itor)
	{
		printf("%d => %d \n", itor->first, itor->second);
	}

	return TEST_RET::SUCCESS;
}
