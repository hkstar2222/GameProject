#include "Character.h"
#include <memory.h>

Character::Character(
	_INT p_nID,
	const char*	p_szName,
	const Character_attribute_st& p_objAttribute
	)
	: GameUnit(UnitType::CHARACTER, p_nID)
	, m_stBaseAttribute(p_objAttribute)
{

	memset(m_strName, 0, CHARACTER_NAME_LENTH);
	this->setName(p_szName);
}

Character::~Character()
{

}

Character::Character(const Character& p_objCharacter)
:GameUnit(p_objCharacter)
, m_stBaseAttribute(p_objCharacter.m_stBaseAttribute)
, m_stCurAttribute(p_objCharacter.m_stCurAttribute)
{
	memset(m_strName, 0, CHARACTER_NAME_LENTH);
	this->setName(p_objCharacter.getName());
}

Character& Character::operator=(const Character& p_objCharacter)
{
	this->setName(p_objCharacter.getName());
	m_stBaseAttribute = p_objCharacter.m_stBaseAttribute;
	m_stCurAttribute = p_objCharacter.m_stCurAttribute;
	return *this;
}


void Character::setName(const char* p_szName)
{
	if (p_szName == NULL) {
		return;
	}

	if (strlen(p_szName) >= CHARACTER_NAME_LENTH) {
		return;
	}

	memset(m_strName, 0, CHARACTER_NAME_LENTH);
	strcpy(m_strName, p_szName);
}

const char* Character::getName() const
{
	return m_strName;
}