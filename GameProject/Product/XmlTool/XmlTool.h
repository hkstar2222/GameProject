#ifndef _XML_TOOL_H_
#define _XML_TOOL_H_

#include "BaseDef.h"
#include "XmlNode.h"

class XmlTool
{
public:
	//解析xml文件	
	//成功返回true		p_pNode得到根节点 
	//失败返回false		p_pNode为NULL
	DLL_API static _BOOL parseXmlFile(const std::string& p_strFileName, XmlNode& p_pobjNode);

	//DLL_API static _BOOL saveXmlFile(const XmlNode& p_pobjNode, const std::string& p_strFileName);

	////解析xml串
	//DLL_API static _BOOL parseXmlString(const std::string& p_strSrcString, XmlNode& p_pobjNode);

	//DLL_API static _BOOL toXmlString(const XmlNode& p_pobjNode, const std::string& p_strXml);
	//

	////创造节点
	//DLL_API static _BOOL createXmlNode(const std::string& p_strName, XmlNode& p_objNode);

	//释放节点资源
	DLL_API static void releaseXmlNode(XmlNode& p_objNode);
};

#endif	//_XML_TOOL_H_

