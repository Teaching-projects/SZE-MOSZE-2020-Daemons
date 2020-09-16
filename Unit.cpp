#include "Unit.h"

void Unit::SetHp(int HP)
{
	if (HP < 0)
	{
		*p_hp = 0;
	}
	else
	{
		*p_hp = HP;
	}
}

const int Unit::GetHp()
{
	return hp;
}

const int Unit::GetDmg()
{
	return dmg;
}

const std::string Unit::GetName()
{
	return name;
}

const void Unit::TakeDamage(const int & damage)
{

	*p_hp -= damage;
	if (*p_hp < 0)
	{
		*p_hp = 0;
	}
}


