#include "Monster.h"
#include "Hero.h"
#include "JSON.h"
#include <map>

Monster Monster::parse(const std::string& data){
	JSON returnedMap = JSON::parseJSON(data);
	return Monster(std::stod(returnedMap.get<std::string>("health_points")),std::stod(returnedMap.get<std::string>("damage")),returnedMap.get<std::string>("name"),std::stod(returnedMap.get<std::string>("attack_cooldown")));
	
}
void Monster::takeDamage(Hero& enemy)
{
	int dmg_taken = hp;
	int damage = enemy.getDamage();
	hp -= damage;
	if (hp < 0)
	{
		hp = 0;
	}
	dmg_taken = dmg_taken - hp;
	// std::cout << enemy.getName() << ": LVL" << enemy.getLevel() << std::endl
	// 	<< "   HP: "<<enemy.getHealthPoints()<<"/"<<enemy.getMaxHealthPoints()<<std::endl
	// 	<< "  DMG: "<<enemy.getDamage()<<std::endl
	// 	<< "  ACD: "<<enemy.getAttackCoolDown()<<std::endl
	// 	<< "  XP: " <<enemy.getXP() << std::endl
	// 	<< "  MONSXP: " <<getHealthPoints() << std::endl
	// 	;
}
int Monster::getHealthPoints() const
{
	return hp;
}
double Monster::getAttackCoolDown() const
{
	return atkcooldown;
}
int Monster::getDamage() const
{
	return dmg;
}
bool Monster::isAlive() const
{
	if(hp == 0) return false;
	else return true;
}
std::string Monster::getName() const
{
	return name;
}