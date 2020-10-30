#include "Unit.h"
#include <math.h>
#include <map>
#include <string>

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
int Unit::getLevel() const
{
	return level;
}
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
	enemy.boost_xp(dmg_taken);
	
}
void Unit::boost_xp(const int& dmg)
{
	xp += dmg;
	float level_xp = xp/100.0;
	if(level_xp >= level)
	{
		int level_step = std::trunc(level_xp - level);
		for(int i = 0;i<=level_step;i++){levelUp();}
	}
}
void Unit::levelUp()
{
	level++;
	maxHP = round(maxHP * 1.1);
	hp = maxHP;
	dmg = round(dmg * 1.1);
}
void Unit::fightTilDeath(Unit* enemy)
{
		int i1=1;
		int i2=1;
		double NextAttackTimerFirstPlayer=i1*this->getAttackCoolDown();
		double NextAttackTimerSecondPlayer=i2*enemy->getAttackCoolDown();
		if(enemy->getHealthPoints())>0&&this->hp>0)
		{
			enemy->takeDamage(* this );
		}
		if(enemy->getHealthPoints())>0&&this->hp>0)
		{
			this->takeDamage( * enemy);
		}
		while(this->hp>0&&(enemy->getHealthPoints())>0))
		{

			
			if(NextAttackTimerFirstPlayer<NextAttackTimerSecondPlayer)
			{
				
				enemy->takeDamage(*this);
				i1++;


			}
			
			else if(NextAttackTimerFirstPlayer==NextAttackTimerSecondPlayer)
			{
				
				enemy->takeDamage(*this);
				this->takeDamage( * enemy);
				i1++;
				i2++;
			}
			else
			{
				
				this->takeDamage( * enemy);
				i2++;
			}
			
			NextAttackTimerFirstPlayer=i1*this->getAttackCoolDown();
			NextAttackTimerSecondPlayer=i2*enemy->getAttackCoolDown();

		}
}
