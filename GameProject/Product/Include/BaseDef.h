#ifndef _BASE_DEF_H_
#define _BASE_DEF_H_

//���������������

#include <stdint.h>

typedef uint32_t		_UINT_32;
typedef uint64_t		_UINT_64;

typedef int32_t			_INT_32;
typedef int64_t			_INT_64;

typedef int				_INT;
typedef unsigned int	_UINT;

typedef double	_DOUBLE;


//��̬�⵼�뵼��
#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif




#endif	//_BASE_DEF_H_