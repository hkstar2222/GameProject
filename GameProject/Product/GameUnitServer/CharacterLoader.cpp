#include "CharacterLoader.h"
#include "XmlTool.h"


namespace
{



	_BOOL toCharacter(const XmlNode& p_objNode, Character& p_objCharacter)
	{
		//xml必要属性
		_INT nID = 0;
		if (!p_objNode.getAttribute("ID", nID)) {
			return false;
		}
		p_objCharacter.m_nID = nID;
		
		//xml可选属性
		std::string strName;
		if (p_objNode.getAttribute("Name", strName)) {
			p_objCharacter.setName(strName.c_str());
		}

		p_objNode.getAttribute("HP", p_objCharacter.m_stBaseAttribute.m_nHP);
		p_objNode.getAttribute("MP", p_objCharacter.m_stBaseAttribute.m_nMP);
		p_objNode.getAttribute("ATK", p_objCharacter.m_stBaseAttribute.m_nATK);
		p_objNode.getAttribute("DEF", p_objCharacter.m_stBaseAttribute.m_nDEF);

		return true;
	}

};


_BOOL CharacterLoader::getCharacterAttrList(const std::string& p_strFilePath, std::vector<Character>& p_objCharacterList)
{
	p_objCharacterList.clear();

	XmlNode p_objFileNode;
	if (!XmlTool::parseXmlFile(p_strFilePath, p_objFileNode)) {
		return false;
	}

	XmlNode p_objListNode;
	if (!p_objFileNode.getChildNode("CharacterList", p_objListNode)) {
		XmlTool::releaseXmlNode(p_objFileNode);
		return false;
	}
	
	std::vector<XmlNode> objCharacterNodeList;
	if (!p_objListNode.getAllChildNode(objCharacterNodeList)) {
		XmlTool::releaseXmlNode(p_objFileNode);
		return false;
	}

	for (_UINT i = 0; i < objCharacterNodeList.size(); ++i)
	{
		const XmlNode& objNode = objCharacterNodeList[i];
		Character objCharacter;
		if (!::toCharacter(objNode, objCharacter))
		{
			XmlTool::releaseXmlNode(p_objFileNode);
			return false;
		}
		p_objCharacterList.push_back(objCharacter);
	}

	XmlTool::releaseXmlNode(p_objFileNode);
	return true;
}

