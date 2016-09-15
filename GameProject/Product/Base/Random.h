#ifndef _RANDOM_H_
#define	_RANDOM_H_

//提供指定范围内的一个随机数

#include "BaseDef.h"

class Random
{
public:
	DLL_API static _INT getRandomNum(_INT p_nMin, _INT p_nMax);

};



#endif	//_RANDOM_H_