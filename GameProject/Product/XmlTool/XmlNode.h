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
	void* getNode() const;

	//释放节点资源
	//注意 XmlNode析构时不会主动释放
	void cleanNode();

	//当前节点名称
	DLL_API std::string getName() const;

public:

	//获取子节点  
	//成功返回true   p_objChildList为子节点
	//失败返回false  p_objChildList为NULL
	DLL_API _BOOL getChildNode(const std::string& p_strNodeName, XmlNode& p_objChild) const;

	//获取所有子节点  成功返回true
	DLL_API _BOOL getAllChildNode(std::vector<XmlNode>& p_objChildList) const;

	//获取指定名称的属性值  成功返回true
	//找不到 或者 属性类型不符则返回false
	DLL_API _BOOL getAttribute(const std::string& p_strName, std::string& p_strValue) const;

	//属性类型不符时返回true p_nValue=0
	DLL_API _BOOL getAttribute(const std::string& p_strName, _INT& p_nValue) const;		

	//支持的bool表示方法： true false
	DLL_API _BOOL getAttribute(const std::string& p_strName, _BOOL& p_bValue) const;	

	//属性类型不符时返回true p_nValue=0.0
	DLL_API _BOOL getDoubleAttribute(const std::string& p_strName, _DOUBLE& p_nValue) const; 

public:

	//DLL_API _BOOL addChildNode(const XmlNode& p_objChild);

	//DLL_API _BOOL setAttribute(const std::string& p_strName, const std::string& p_strValue);
	//DLL_API _BOOL setAttribute(const std::string& p_strName, const _INT& p_nValue);
	//DLL_API _BOOL setAttribute(const std::string& p_strName, const _BOOL& p_bValue);
	//DLL_API _BOOL setDoubleAttribute(const std::string& p_strName, const _DOUBLE& p_nValue);

private:
	void*	m_pobjXmlNode;
};

#endif	//_XML_NODE_H_

