#ifndef _XML_NODE_H_
#define _XML_NODE_H_
#include "BaseDef.h"
#include <string>
#include <vector>


class XmlNode
{
public:
	DLL_API XmlNode();
	DLL_API ~XmlNode();

	void setNode(void* p_pNode);

	DLL_API void cleanNode();

public:

	//获取子节点  
	//成功返回true   p_objChildList为子节点
	//失败返回false  p_objChildList为NULL
	DLL_API _BOOL getChildNode(const std::string& p_strNodeName, XmlNode& p_pobjChild);

	//获取所有子节点  成功返回true
	DLL_API _BOOL getAllChildNode(std::vector<XmlNode>& p_objChildList);

	//获取指定名称的属性值  成功返回true
	//找不到 或者 属性类型不符则返回false
	DLL_API _BOOL getAttribute(const std::string& p_strName, std::string& p_strValue);
	DLL_API _BOOL getAttribute(const std::string& p_strName, _INT& p_strValue);
	DLL_API _BOOL getAttribute(const std::string& p_strName, _BOOL& p_strValue);
	DLL_API _BOOL getDoubleAttribute(const std::string& p_strName, _DOUBLE& p_strValue);

private:
	void*	m_pobjXmlNode;
};

#endif	//_XML_NODE_H_

