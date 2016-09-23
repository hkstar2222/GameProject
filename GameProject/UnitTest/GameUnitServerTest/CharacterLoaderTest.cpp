#include "FuncDef.h"
#include "CharacterLoader.h"

_INT TEST_FUNC::testCharacterLoader()
{
	while (true)
	{
		std::vector<Character> objCharacterList;
		_BOOL bRet = CharacterLoader::getCharacterAttrList("TestData/Character.xml", objCharacterList);
	}




	return TEST_RET::SUCCESS;
}