#ifndef _GAME_UNIT_H_
#define _GAME_UNIT_H_

//��Ϸ��λ������
//������Ϸ��λ��Ҫ�̳и���
//��������ɫ��������Ʒ��������Ʒ��

#include "BaseDef.h"
#include "GameUnitDef.h"


class DLL_API GameUnit
{
public:
	GameUnit(
		UnitType p_emType	= UnitType::UNKNOWN, 
		_INT p_nID			= 0
		);

	virtual ~GameUnit();
	//GameUnit(const GameUnit& p_objGameUnit);



public:
	_INT			m_nID;		//��λID	ÿ�൥λ��Ȼ��һ��Ψһ��Ӧ��ID
	UnitType		m_emType;	//��λ����

};



#endif	//_GAME_UNIT_H_

