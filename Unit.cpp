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
	current_xp += dmg;
	float level_xp = current_xp/100.0;
	if(level_xp >= level){levelUp();}
}
void Unit::levelUp()
{
	std::cout << "Level up for: " << this->getName() << "\n";
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
		Unit* hi = new Unit(hp,dmg,name);
		return hi;
	}else{
		throw std::runtime_error("File not found: "+filename);
	}
}