#include "XmlTool.h"
#include "tinyxml.h"


_BOOL XmlTool::parseXmlFile(const std::string& p_strFileName, XmlNode& p_pobjNode)
{
	FILE* pFile = fopen(p_strFileName.c_str(), "r");
	if (pFile == NULL) {
		return false;
	}

	TiXmlDocument* pobjTiXmlDocument = new TiXmlDocument();
	if (!pobjTiXmlDocument->LoadFile(pFile))
	{
		fclose(pFile);
		return false;
	}
	fclose(pFile);

	p_pobjNode.setNode((void*)pobjTiXmlDocument);
	return true;
}

//_BOOL XmlTool::saveXmlFile(const XmlNode& p_pobjNode, const std::string& p_strFileName)
//{
//	FILE* pFile = fopen(p_strFileName.c_str(), "w+");
//	if (pFile == NULL) {
//		return false;
//	}
//
//	return true;
//}
//
//_BOOL XmlTool::createXmlNode(const std::string& p_strName, XmlNode& p_objNode)
//{
//	TiXmlElement* p = new TiXmlElement(p_strName);
//	p_objNode.setNode(p);
//	return true;
//}

void XmlTool::releaseXmlNode(XmlNode& p_objNode)
{
	p_objNode.cleanNode();
}



