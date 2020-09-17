#include "Unit.h"

int Unit::getHp() const
{
	return hp;
}

int Unit::getDmg() const
{
	return dmg;
}

std::string Unit::getName() const
{
	return name;
}

void Unit::takeDamage(const Unit& enemy)
{
	int damage = enemy.getDmg();
	hp -= damage;
	if (hp < 0)
	{
		hp = 0;
	}
}
