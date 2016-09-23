#ifndef _CHARACTER_H_
#define _CHARACTER_H_

//��Ϸ��ɫʵ����

#include "GameUnit.h"
#include <string>


struct DLL_API Character_attribute_st
{
	_INT m_nHP = 0;		//HP
	_INT m_nMP = 0;		//MP

	_INT m_nATK = 0;	//����
	_INT m_nDEF = 0;	//����
};


class DLL_API Character : public GameUnit
{
public:
	Character(
		_INT p_nID	= 0,
		const char*	p_szName = "",
		const Character_attribute_st& p_stAttribute = Character_attribute_st()
		);

	~Character();
	Character(const Character& p_objCharacter);
	Character& operator=(const Character& p_objCharacter);

public:
	void setName(const char* p_szName);
	const char* getName() const;


public:
	Character_attribute_st m_stBaseAttribute;	//��ɫ����

	Character_attribute_st m_stCurAttribute;	//��ɫ��ǰ����

private:
	char	m_strName[CHARACTER_NAME_LENTH];
};

#endif	//_CHARACTER_H_

