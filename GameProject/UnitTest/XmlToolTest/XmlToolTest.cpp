#include "FuncDef.h"
#include "XmlTool.h"
#include "XmlNode.h"


_INT testXmlFileRead()
{
	XmlNode objFileNode;
	_BOOL bRet = XmlTool::parseXmlFile("TestData/test.xml", objFileNode);

	std::vector<XmlNode> objNodeList;
	bRet = objFileNode.getAllChildNode(objNodeList);

	XmlNode objRootNode;
	bRet = objFileNode.getChildNode("root", objRootNode);

	XmlNode objInfoNode;
	bRet = objRootNode.getChildNode("info", objInfoNode);

	XmlNode objNodeA;
	bRet = objInfoNode.getChildNode("NodeA", objNodeA);

	std::string strName;
	bRet = objNodeA.getAttribute("name", strName);

	_INT nNum = 0;
	bRet = objNodeA.getAttribute("name", nNum);

	_BOOL bFlag = false;
	bRet = objNodeA.getAttribute("flag", bFlag);

	_DOUBLE nDouble = 0.0;
	bRet = objNodeA.getDoubleAttribute("name", nDouble);

	std::string strChString;
	bRet = objNodeA.getAttribute("ch", strChString);


	XmlNode objInfoListNode;
	bRet = objRootNode.getChildNode("infoList", objInfoListNode);
	bRet = objInfoListNode.getAllChildNode(objNodeList);

	for (_UINT i = 0; i < objNodeList.size(); ++i)
	{
		_INT nID = 0;
		objNodeList[i].getAttribute("ID", nID);
		//printf("%d", nID);
	}

	XmlTool::releaseXmlNode(objFileNode);

	return TEST_RET::SUCCESS;
}

//_INT testXmlFileWrite()
//{
//	XmlNode objNode;
//	_BOOL bRet = XmlTool::createXmlNode("TestNode", objNode);
//
//	bRet = objNode.setAttribute("name", "hkstar");
//	bRet = objNode.setAttribute("num", 233);
//	bRet = objNode.setAttribute("name", true);
//	bRet = objNode.setDoubleAttribute("double", 2.56);
//
//	XmlTool::releaseXmlNode(objNode);
//}


_INT TEST_FUNC::testXmlTool()
{
	//²âÊÔÊÇ·ñÄÚ´æÐ¹Â©
	while (true)
	{
		testXmlFileRead();
	}

	return TEST_RET::SUCCESS;
}

