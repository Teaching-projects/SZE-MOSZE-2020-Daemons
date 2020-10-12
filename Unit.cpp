#include "Unit.h"

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

void Unit::takeDamage(const Unit& enemy)
{
	int damage = enemy.getDmg();
	hp -= damage;
	if (hp < 0)
	{
		hp = 0;
	}
}
std::string extractName(const std::string line)
{
	std::string name = line.substr(line.find(":"));
	name.erase(name.find_last_of('"'),name.length()-1);
	return name.substr(name.find_first_of('"')+1);
}

Unit* Unit::parseUnit(const std::string& filename){
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

		Unit* hi = new Unit(hp,dmg,name,atkspeed);
		return hi;
	}else{
		throw std::runtime_error("File not found: "+filename);
	}
	
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