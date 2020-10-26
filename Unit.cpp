#include "Unit.h"
#include <math.h>
#include <map>
#include <string>
#include "JsonParser.h"

int Unit::getHp() const
{
	return hp;
}

int Unit::getDmg() const
{
	return dmg;
}
double Unit::getAs() const
{
	return atkcooldown;
}

std::string Unit::getName() const
{
	return name;
}

void Unit::takeDamage(Unit& enemy)
{
	int dmg_taken = hp;
	int damage = enemy.getDmg();
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

Unit Unit::parseUnit(const std::string& data){
	std::map<std::string, std::string> returnedMap = JsonParser::parseJSON(data);
	return Unit(std::stod(returnedMap["hp"]),std::stod(returnedMap["dmg"]),returnedMap["name"],std::stod(returnedMap["attackcooldown"]));
}

void Unit::Fight(Unit* enemy)
{
		int i1=1;
		int i2=1;
		double NextAttackTimerFirstPlayer=i1*this->getAs();
		double NextAttackTimerSecondPlayer=i2*enemy->getAs();
		if(enemy->getHp()>0&&this->hp>0)
		{
			enemy->takeDamage(* this );
		}
		if(enemy->getHp()>0&&this->hp>0)
		{
			this->takeDamage( * enemy);
		}
		while(this->hp>0&&(enemy->getHp()>0))
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
			
			NextAttackTimerFirstPlayer=i1*this->getAs();
			NextAttackTimerSecondPlayer=i2*enemy->getAs();

		}
}
