#include "Hero.h"
#include "JSON.h"
#include <map>
#include <math.h>

Hero Hero::parse(const std::string& data){
	JSON returnedMap = JSON::parseJSON(data);
	return Hero(std::stod(returnedMap.get<std::string>("base_health_points")),
	std::stod(returnedMap.get<std::string>("base_damage")),
	returnedMap.get<std::string>("name"),
	std::stod(returnedMap.get<std::string>("base_attack_cooldown")),
	std::stod(returnedMap.get<std::string>("experience_per_level")),
	std::stod(returnedMap.get<std::string>("health_point_bonus_per_level")),
	std::stod(returnedMap.get<std::string>("damage_bonus_per_level")),
	std::stod(returnedMap.get<std::string>("cooldown_multiplier_per_level"))
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
	dmg += damage_bonus_per_level;
	atkcooldown *= cooldown_multiplier_per_level;
	hp = maxHP;
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
	int damage = enemy.getDamage();
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
		if(hp != 0) hp -= enemy.getDamage();
}
int Hero::getHealthPoints() const
{
	return hp;
}
double Hero::getAttackCoolDown() const
{
	return atkcooldown;
}
int Hero::getDamage() const
{
	return dmg;
}

int Hero::getMaxHealthPoints() const
{
	return maxHP;
}

std::string Hero::getName() const
{
	return name;
}