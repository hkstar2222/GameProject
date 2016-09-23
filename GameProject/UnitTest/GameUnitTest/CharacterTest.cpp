#include "FuncDef.h"
#include "Character.h"


_INT TEST_FUNC::testCharacter()
{
	Character_attribute_st stAttr;
	stAttr.m_nHP = 100;
	stAttr.m_nMP = 200;
	stAttr.m_nATK = 10;
	stAttr.m_nDEF = 5;

	Character objCharacter(1, "test", stAttr);

	const char* szName = objCharacter.getName();

	Character objCharacter_copy;
	objCharacter_copy = objCharacter;


	return TEST_RET::SUCCESS;
}

