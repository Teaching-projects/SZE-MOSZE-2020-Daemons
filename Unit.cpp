#include "Unit.h"

void Unit::SetHp(int HP)
{
	hp = HP;
}

int Unit::GetHp()
{
	return hp;
}

int Unit::GetDmg()
{
	return dmg;
}

std::string Unit::GetName()
{
	return name;
}

Unit::~Unit()
{
}
