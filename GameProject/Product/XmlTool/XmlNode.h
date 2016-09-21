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

	//�ͷŽڵ���Դ
	//ע�� XmlNode����ʱ���������ͷ�
	void cleanNode();

	//��ǰ�ڵ�����
	DLL_API std::string getName() const;

public:

	//��ȡ�ӽڵ�  
	//�ɹ�����true   p_objChildListΪ�ӽڵ�
	//ʧ�ܷ���false  p_objChildListΪNULL
	DLL_API _BOOL getChildNode(const std::string& p_strNodeName, XmlNode& p_objChild) const;

	//��ȡ�����ӽڵ�  �ɹ�����true
	DLL_API _BOOL getAllChildNode(std::vector<XmlNode>& p_objChildList) const;

	//��ȡָ�����Ƶ�����ֵ  �ɹ�����true
	//�Ҳ��� ���� �������Ͳ����򷵻�false
	DLL_API _BOOL getAttribute(const std::string& p_strName, std::string& p_strValue) const;

	//�������Ͳ���ʱ����true p_nValue=0
	DLL_API _BOOL getAttribute(const std::string& p_strName, _INT& p_nValue) const;		

	//֧�ֵ�bool��ʾ������ true false
	DLL_API _BOOL getAttribute(const std::string& p_strName, _BOOL& p_bValue) const;	

	//�������Ͳ���ʱ����true p_nValue=0.0
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

