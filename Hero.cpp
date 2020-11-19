#include "Hero.h"
#include "JSON.h"
#include <map>
#include <math.h>

Hero Hero::parse(const std::string& data){
	JSON returnedMap = JSON::parseFromFile(data);
	return Hero(returnedMap.get<int>("base_health_points"),
	returnedMap.get<std::string>("name"),
	returnedMap.get<double>("base_attack_cooldown"),
	returnedMap.get<int>("experience_per_level"),
	returnedMap.get<int>("health_point_bonus_per_level"),
	returnedMap.get<int>("damage_bonus_per_level"),
	returnedMap.get<double>("cooldown_multiplier_per_level"),
	returnedMap.get<double>("defense"),
	returnedMap.get<double>("defense_bonus_per_level"),
	returnedMap.get<int>("damage"),
	returnedMap.get<int>("magical-damage")
	
	);
	
}
void Hero::boostxp(const int xp_to_boost)
{
	xp += xp_to_boost;
	if((xp/experience_per_level) >= level)
	{
		levelUp();
	}
}
void Hero::levelUp()
{
	level++;
	maxHP += health_point_bonus_per_level;
	damage.physical += damage_bonus_per_level;
	atkcooldown *= cooldown_multiplier_per_level;
	hp = maxHP;
	defense +=defense_bonus_per_level;
}
bool Hero::isAlive() const
{
	if(hp == 0) return false;
	else return true;
}
int Hero::getLevel() const
{
	
	return level;
}
int Hero::getXP() const
{
	return xp;
}
void Hero::takeDamage(Monster& enemy)
{
	int dmg_taken = hp;
	int damage = enemy.getphysDamage()-defense;
	if(damage<0)
	{
		 damage=0;
	}
	hp -= damage;
	if (hp < 0)
	{
		hp = 0;
	}
	dmg_taken = dmg_taken - hp;
}
void Hero::fightTilDeath(Monster& enemy)
{
		int i1=1;
		int i2=1;
		double NextAttackTimerFirstPlayer=i1*getAttackCoolDown();
		double NextAttackTimerSecondPlayer=i2*enemy.getAttackCoolDown();

		while(hp>0&&(enemy.getHealthPoints()>0))
		{

			if(NextAttackTimerFirstPlayer<NextAttackTimerSecondPlayer)
			{

				enemy.takeDamage(*this);
				i1++;

			}

			else if(NextAttackTimerFirstPlayer==NextAttackTimerSecondPlayer)
			{
				enemy.takeDamage(*this);
				takeDamage(enemy);

				i1++;
				i2++;
			}
			else
			{
				takeDamage(enemy);
				i2++;
			}
			NextAttackTimerFirstPlayer=i1*getAttackCoolDown();
			NextAttackTimerSecondPlayer=i2*enemy.getAttackCoolDown();

		}
		if(hp != 0) hp -= enemy.getphysDamage();
}
int Hero::getHealthPoints() const
{
	return hp;
}
double Hero::getAttackCoolDown() const
{
	return atkcooldown;
}
int Hero::getphysDamage() const
{
	return damage.physical ;
}
int Hero::getmagicDamage() const
{
	return damage.magical ;
}

int Hero::getMaxHealthPoints() const
{
	return maxHP;
}

std::string Hero::getName() const
{
	return name;
}
double Hero::getDefense() const
{
	return defense;
}