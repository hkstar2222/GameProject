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

void XmlNode::cleanNode()
{
	if (m_pobjXmlNode == NULL)
	{
		return;
	}

	TiXmlNode* p = (TiXmlNode*)m_pobjXmlNode;
	delete p;
	m_pobjXmlNode = NULL;
}

_BOOL XmlNode::getChildNode(const std::string& p_strNodeName, XmlNode& p_pobjChild)
{
	TiXmlHandle objTiXmlHandle((TiXmlNode*)m_pobjXmlNode);
	TiXmlHandle objChildHandle = objTiXmlHandle.ChildElement(p_strNodeName, 0);

	void* p = objChildHandle.ToElement();
	if (p == NULL)
	{
		return false;
	}

	p_pobjChild.setNode(p);
	return true;
}

_BOOL XmlNode::getAllChildNode(std::vector<XmlNode>& p_objChildList)
{
	TiXmlElement* p = (TiXmlElement*)m_pobjXmlNode;
	if (p == NULL) 
	{
		return false;
	}

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

_BOOL XmlNode::getAttribute(const std::string& p_strName, std::string& p_strValue)
{
	TiXmlElement* p = (TiXmlElement*)m_pobjXmlNode;
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

_BOOL XmlNode::getAttribute(const std::string& p_strName, _INT& p_nValue)
{
	return false;
}

_BOOL XmlNode::getAttribute(const std::string& p_strName, _BOOL& p_bValue)
{
	return false;
}

_BOOL XmlNode::getDoubleAttribute(const std::string& p_strName, _DOUBLE& p_nValue)
{
	return false;
}
