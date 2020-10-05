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
	return atkspeed;
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
		int i=1;
		if(enemy-hp>0)
		{
			enemy->hp-=this->getDmg();
		}
		if(hp>0)
		{
			hp-=enemy->getDmg();
		}
		while(hp>0&&(enemy->hp>0))
		{
			if(atkspeed*i>(enemy->atkspeed*i))
			{
				enemy->hp-=this->getDmg();
				

			}
			else if(atkspeed*i==(enemy->atkspeed*i))
			{
				enemy->hp-=this->getDmg();
				hp-=enemy->getDmg();
			}
			else
			{
				hp-=enemy->getDmg();
			}
			
			
			i++;

		}

	}