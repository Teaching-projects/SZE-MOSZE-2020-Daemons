#include "Unit.h"
#include <math.h>

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
std::string extractName(const std::string line)
{
	std::string name = line.substr(line.find(":"));
	name.erase(name.find_last_of('"'),name.length()-1);
	return name.substr(name.find_first_of('"')+1);
}

Unit Unit::parseUnit(const std::string& filename){
	std::ifstream file(filename);
	if(file.good()){
		std::string line;

		std::getline(file, line);
		std::getline(file, line);
		std::string name = extractName(line);
		
		std::getline(file, line);
		std::string substring = line.substr(line.find(":")+1);
		int hp = std::stoi(substring);
		std::getline(file, line);
		substring = line.substr(line.find(":")+1);
		int dmg = std::stoi(substring);

		std::getline(file, line);
		substring = line.substr(line.find(":")+1);
		double atkspeed = std::stod(substring);

		return Unit(hp,dmg,name,atkspeed);
	}else{
		throw std::runtime_error("File not found: "+filename);
	}
	
}
void Unit::Fight(Unit* enemy)
	{
		int i1=1;
		int i2=1;
		double TmpNextAttack1=i1*this->getAs();
		double TmpNextAttack2=i2*enemy->getAs();
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

			if(TmpNextAttack1<TmpNextAttack2)
			{
				enemy->hp-=this->getDmg();
				i1++;
				

			}
			else if(TmpNextAttack1==TmpNextAttack2)
			{
				enemy->hp-=this->getDmg();
				hp-=enemy->getDmg();
				i1++;
				i2++;
			}
			else
			{
				hp-=enemy->getDmg();
				i2++;
			}
			TmpNextAttack1=i1*this->getAs();
			TmpNextAttack2=i2*enemy->getAs();

		}

	}