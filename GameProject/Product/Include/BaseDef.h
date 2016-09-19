#ifndef _BASE_DEF_H_
#define _BASE_DEF_H_

//定义基本变量类型

#include <stdint.h>

typedef uint32_t		_UINT_32;
typedef uint64_t		_UINT_64;

typedef int32_t			_INT_32;
typedef int64_t			_INT_64;

typedef int				_INT;
typedef unsigned int	_UINT;

typedef double	_DOUBLE;


//动态库导入导出
#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif




#endif	//_BASE_DEF_H_