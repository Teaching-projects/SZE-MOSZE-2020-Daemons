#include "Unit.h"
#include <math.h>
#include <map>
#include <string>
#include "Hero.h"

int Unit::getHealthPoints() const
{
	return hp;
}

int Unit::getDamage() const
{
	return dmg;
}
double Unit::getAttackCoolDown() const
{
	return atkcooldown;
}

std::string Unit::getName() const
{
	return name;
}
int Unit::getMaxHealthPoints() const
{
	return maxHP;
}
bool Unit::isAlive() const
{
	if(hp == 0) return false;
	else return true;
}
// int Unit::getLevel() const
// {
// 	return level;
// }
void Unit::takeDamage(Unit& enemy)
{
	int dmg_taken = hp;
	int damage = enemy.getDamage();
	hp -= damage;
	if (hp < 0)
	{
		hp = 0;
	}
	dmg_taken = dmg_taken - hp;
	//enemy.boost_xp(dmg_taken);
	
}

