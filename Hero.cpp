#include "Hero.h"
#include "JSON.h"
#include "Monster.h"
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

void Hero::levelUp()
{
	level++;
	maxHP = round(maxHP * 1.1);
	hp = maxHP;
	dmg = round(dmg * 1.1);
}

void Hero::fightTilDeath(Monster enemy)
{
		int i1=1;
		int i2=1;
		double NextAttackTimerFirstPlayer=i1*getAttackCoolDown();
		double NextAttackTimerSecondPlayer=i2*enemy.getAttackCoolDown();
		
		if(enemy.getHealthPoints()>0&&hp>0)
		{
			enemy.takeDamage(*this);
		}
		if(enemy.getHealthPoints()>0&&hp>0)
		{
			takeDamage(enemy);
		}
		while(hp>0&&(enemy.getHealthPoints()>0))
		{

			
			if(NextAttackTimerFirstPlayer<NextAttackTimerSecondPlayer)
			{
				int enemy_before_fight_hp = enemy.getHealthPoints();
				enemy.takeDamage(*this);
				
				if(enemy.getHealthPoints() == 0)
				{
					this->xp += enemy_before_fight_hp;
				}
				this->xp += this->dmg;
				i1++;


			}
			
			else if(NextAttackTimerFirstPlayer==NextAttackTimerSecondPlayer)
			{
				
				enemy.takeDamage(*this);
				if(dynamic_cast<Hero*>(this)!=nullptr){

				}
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
}
