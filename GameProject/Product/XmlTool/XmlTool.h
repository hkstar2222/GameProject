#ifndef _XML_TOOL_H_
#define _XML_TOOL_H_

#include "BaseDef.h"
#include "XmlNode.h"

class XmlTool
{
public:
	//����xml�ļ�	
	//�ɹ�����true		p_pNode�õ����ڵ� 
	//ʧ�ܷ���false		p_pNodeΪNULL
	DLL_API static _BOOL parseXmlFile(const std::string& p_strFileName, XmlNode& p_pobjNode);

	//DLL_API static _BOOL saveXmlFile(const XmlNode& p_pobjNode, const std::string& p_strFileName);

	////����xml��
	//DLL_API static _BOOL parseXmlString(const std::string& p_strSrcString, XmlNode& p_pobjNode);

	//DLL_API static _BOOL toXmlString(const XmlNode& p_pobjNode, const std::string& p_strXml);
	//

	////����ڵ�
	//DLL_API static _BOOL createXmlNode(const std::string& p_strName, XmlNode& p_objNode);

	//�ͷŽڵ���Դ
	DLL_API static void releaseXmlNode(XmlNode& p_objNode);
};

#endif	//_XML_TOOL_H_

