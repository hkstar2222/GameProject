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

	//��ȡ�ӽڵ�  
	//�ɹ�����true   p_objChildListΪ�ӽڵ�
	//ʧ�ܷ���false  p_objChildListΪNULL
	DLL_API _BOOL getChildNode(const std::string& p_strNodeName, XmlNode& p_pobjChild);

	//��ȡ�����ӽڵ�  �ɹ�����true
	DLL_API _BOOL getAllChildNode(std::vector<XmlNode>& p_objChildList);

	//��ȡָ�����Ƶ�����ֵ  �ɹ�����true
	//�Ҳ��� ���� �������Ͳ����򷵻�false
	DLL_API _BOOL getAttribute(const std::string& p_strName, std::string& p_strValue);
	DLL_API _BOOL getAttribute(const std::string& p_strName, _INT& p_strValue);
	DLL_API _BOOL getAttribute(const std::string& p_strName, _BOOL& p_strValue);
	DLL_API _BOOL getDoubleAttribute(const std::string& p_strName, _DOUBLE& p_strValue);

private:
	void*	m_pobjXmlNode;
};

#endif	//_XML_NODE_H_

