#include "FuncDef.h"
#include "XmlTool.h"
#include "XmlNode.h"

_INT TEST_FUNC::testXmlTool()
{

	for (_INT i = 0;; i++)
	{
		XmlNode objRootNode;
		_BOOL bRet = XmlTool::parseXmlFile("TestData/test.xml", objRootNode);

		std::vector<XmlNode> objNodeList;
		//bRet = objRootNode.getAllChildNode(objNodeList);

		XmlNode objInfoNode;
		bRet = objRootNode.getChildNode("info", objInfoNode);

		objRootNode.cleanNode();

		printf("%d", i);
	}
	

	return TEST_RET::SUCCESS;
}

