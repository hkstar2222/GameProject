#ifndef _CHARACTER_LOADER_H_
#define _CHARACTER_LOADER_H_

//∂¡»°xmlΩ«…´ Ù–‘≈‰÷√

#include "BaseDef.h"
#include <string>
#include <vector>
#include "Character.h"

class CharacterLoader
{
public:

	DLL_API static _BOOL getCharacterAttrList(const std::string& p_strFilePath, std::vector<Character>& p_objCharacterList);

};


#endif	//_CHARACTER_LOADER_H_

