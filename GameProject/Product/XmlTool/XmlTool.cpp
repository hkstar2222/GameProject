#include "XmlTool.h"
//#include "mxml.h"
#include "tinyxml.h"

//_BOOL XmlTool::openXmlFile(const std::string& p_strFileName)
//{
//	//FILE* pFile = fopen(p_strFileName.c_str(), "r");
//
//	//if (pFile == NULL)
//	//{
//	//	return false;
//	//}
//
//	//fseek(pFile, 0, SEEK_SET);
//
//	//int ch = getc(pFile);
//
//	//mxml_node_t *top = NULL;
//	//mxml_node_t	*p = mxmlLoadFile(top, pFile, NULL);
//
//	//fclose(pFile);
//
//	return true;
//}

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

	void* p = (void*)pobjTiXmlDocument->RootElement();
	if (p == NULL)
	{
		return false;
	}
	
	p_pobjNode.setNode(p);
	return true;
}





