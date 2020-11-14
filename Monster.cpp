#include "Monster.h"
#include "Hero.h"
#include "JSON.h"
#include <map>

Monster Monster::parse(std::string& data){
	JSON returnedMap = JSON::parseJSON(data);
	return Monster(returnedMap.get<int>("health_points"),
	returnedMap.get<int>("damage"),
	returnedMap.get<std::string>("name"),
	returnedMap.get<double>("attack_cooldown"));

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
	enemy.boostxp(dmg_taken);
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
