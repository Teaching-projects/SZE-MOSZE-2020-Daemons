#include "Monster.h"
#include "Hero.h"
#include "JSON.h"
#include <map>

Monster Monster::parse(const std::string& data){
	JSON returnedMap = JSON::parseFromFile(data);
	return Monster(returnedMap.get<int>("health_points"),
	returnedMap.get<std::string>("name"),
	returnedMap.get<double>("attack_cooldown"),
	returnedMap.get<double>("defense"),
	returnedMap.get<int>("damage"),
	returnedMap.get<int>("magical-damage")
	);

}
void Monster::takeDamage(Hero& enemy)
{
	int dmg_taken = hp;
	int damage = enemy.getphysDamage()-defense;
	if(damage<0)
	{
		 damage=0;
	}
	damage+=enemy.getmagicDamage();
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
int Monster::getphysDamage() const
{
	return damage.physical;
}
int Monster::getphysDamage() const
{
	return damage.magical;
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
double Monster::getDefense() const
{
	return defense;
}