#ifndef _GAME_UNIT_H_
#define _GAME_UNIT_H_

//游戏单位基础类
//所有游戏单位需要继承该类
//包括：角色、背包物品、场景物品等

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
	_INT			m_nID;		//单位ID	每类单位必然有一个唯一对应的ID
	UnitType		m_emType;	//单位类型

};



#endif	//_GAME_UNIT_H_

