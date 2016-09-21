#include "XmlNode.h"
#include "tinyxml.h"



XmlNode::XmlNode()
:m_pobjXmlNode(NULL)
{
	
}

XmlNode::~XmlNode()
{
	
}

void XmlNode::setNode(void* p_pNode)
{
	m_pobjXmlNode = p_pNode;
}

void* XmlNode::getNode() const
{
	return m_pobjXmlNode;
}

std::string XmlNode::getName() const
{
	if (m_pobjXmlNode == NULL) {
		return "";
	}
	TiXmlNode* p = (TiXmlNode*)m_pobjXmlNode;
	return p->ValueStr();
}

void XmlNode::cleanNode()
{
	if (m_pobjXmlNode == NULL) {
		return;
	}

	TiXmlNode* p = (TiXmlNode*)m_pobjXmlNode;
	delete p;
	m_pobjXmlNode = NULL;
}

_BOOL XmlNode::getChildNode(const std::string& p_strNodeName, XmlNode& p_objChild) const
{
	TiXmlHandle objTiXmlHandle((TiXmlNode*)m_pobjXmlNode);
	TiXmlHandle objChildHandle = objTiXmlHandle.ChildElement(p_strNodeName, 0);

	void* p = objChildHandle.ToElement();
	if (p == NULL)
	{
		return false;
	}

	p_objChild.setNode(p);
	return true;
}

_BOOL XmlNode::getAllChildNode(std::vector<XmlNode>& p_objChildList) const
{
	p_objChildList.clear();

	if (m_pobjXmlNode == NULL) {
		return false;
	}

	TiXmlNode* p = (TiXmlNode*)m_pobjXmlNode;
	TiXmlNode* pChild = NULL;
	while (pChild = p->IterateChildren(pChild))
	{
		if (pChild->ToElement() == NULL)
		{
			continue;
		}

		XmlNode tmp;
		tmp.setNode((void*)pChild);
		p_objChildList.push_back(tmp);
	}

	return true;
}

_BOOL XmlNode::getAttribute(const std::string& p_strName, std::string& p_strValue) const
{
	if (m_pobjXmlNode == NULL) {
		return false;
	}

	TiXmlElement* p = ((TiXmlNode*)m_pobjXmlNode)->ToElement();
	if (p == NULL)
	{
		return false;
	}

	const char* szTmp = p->Attribute(p_strName.c_str());
	if (szTmp == NULL)
	{
		return false;
	}

	p_strValue = szTmp;
	return true;
}

_BOOL XmlNode::getAttribute(const std::string& p_strName, _INT& p_nValue) const
{
	std::string strValue;
	if (!getAttribute(p_strName, strValue))
	{
		return false;
	}

	p_nValue = atoi(strValue.c_str());
	return true;
}

_BOOL XmlNode::getAttribute(const std::string& p_strName, _BOOL& p_bValue) const
{
	std::string strValue;
	if (!getAttribute(p_strName, strValue))
	{
		return false;
	}

	if (strValue == "true"
		//|| strValue == "1"
		//|| strValue == "yes"
		)
	{
		p_bValue = true;
	} 
	else if (strValue == "false"
		//|| strValue == "0"
		//|| strValue == "no"
		)
	{
		p_bValue = false;
	}
	else
	{
		return false;
	}

	return true;
}

_BOOL XmlNode::getDoubleAttribute(const std::string& p_strName, _DOUBLE& p_nValue) const
{
	std::string strValue;
	if (!getAttribute(p_strName, strValue))
	{
		return false;
	}

	p_nValue = atof(strValue.c_str());
	return true;
}

//
//_BOOL XmlNode::addChildNode(const XmlNode& p_objChild)
//{
//	if (m_pobjXmlNode == NULL 
//		|| p_objChild.getNode() == NULL)
//	{
//		return false;
//	}
//
//	TiXmlNode* p = (TiXmlNode*)m_pobjXmlNode;
//	TiXmlNode* pobjChild = (TiXmlNode*)p_objChild.getNode();
//
//	TiXmlNode* pRet = p->InsertEndChild(*pobjChild);
//	if (pRet == NULL)
//	{
//		return false;
//	}
//	return true;
//}
//
//_BOOL XmlNode::setAttribute(const std::string& p_strName, const std::string& p_strValue)
//{
//	if (m_pobjXmlNode == NULL)
//	{
//		return false;
//	}
//
//	TiXmlElement* p = ((TiXmlNode*)m_pobjXmlNode)->ToElement();
//	if (p == NULL) {
//		return false;
//	}
//
//	p->SetAttribute(p_strName, p_strValue);
//	return true;
//}
//
//_BOOL XmlNode::setAttribute(const std::string& p_strName, const _INT& p_nValue)
//{
//	char szTmp[64] = {'0'};
//	sprintf(szTmp, "%d", p_nValue);
//
//	return setAttribute(p_strName, std::string(szTmp));
//}
//
//_BOOL XmlNode::setAttribute(const std::string& p_strName, const _BOOL& p_bValue)
//{
//	std::string strBool;
//	if (p_bValue) {
//		strBool = "true";
//	}
//	else {
//		strBool = "false";
//	}
//
//	return setAttribute(p_strName, strBool);
//}
//
//_BOOL XmlNode::setDoubleAttribute(const std::string& p_strName, const _DOUBLE& p_nValue)
//{
//	char szTmp[64] = { '0' };
//	sprintf(szTmp, "%f", p_nValue);
//
//	return setAttribute(p_strName, std::string(szTmp));
//}

