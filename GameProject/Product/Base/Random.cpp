#include "Random.h"

#define _CRT_RAND_S
#include <stdlib.h>

namespace {

	_DOUBLE getBaseRandomNum() 
	{
		errno_t err;
		_UINT nNumber;
		err = rand_s(&nNumber);
		if (err != 0)
		{
			return 0;//²úÉúÊ§°Ü£¬·µ»Ø0  
		}

		return (double)nNumber / (double)UINT_MAX;
	}

};


_INT Random::getRandomNum(_INT p_nMin, _INT p_nMax)
{
	if (p_nMax < p_nMin)
	{
		return p_nMax;
	}

	_DOUBLE per = ::getBaseRandomNum();

	_INT tmp = (_INT)((_DOUBLE)(p_nMax - p_nMin + 1) * per);

	_INT ret = p_nMin + tmp;

	return ret;
}

