#include "Unit.h"

const int Unit::getHp()
{
	return hp;
}

const int Unit::getDmg()
{
	return dmg;
}

const std::string Unit::getName()
{
	return name;
}

void Unit::takeDamage(const int & damage)
{

	hp -= damage;
	if (hp < 0)
	{
		hp = 0;
	}
}


