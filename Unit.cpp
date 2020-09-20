#include "Unit.h"

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

void Unit::takeDamage(const Unit& enemy)
{
	int damage = enemy.getDmg();
	hp -= damage;
	if (hp < 0)
	{
		hp = 0;
	}
}

Unit* Unit::parseUnit(const std::string& filename){
	std::ifstream file(filename);
	if(file.good()){
		std::string line;
		std::getline(file, line);
		//Read in the name
		std::getline(file, line);
		std::string name = line.substr(line.find(":")+1);
		name = name.substr(name.find('"')+1, name.find_last_of('"')-2);
		//Read in the hp value
		std::getline(file, line);
		std::string substring = line.substr(line.find(":")+1);
		int hp = std::stoi(substring.substr(substring.find('"')+1, substring.find_last_of('"')-2));
		//Read in the dmg value
		std::getline(file, line);
		substring = line.substr(line.find(":")+1);
		int dmg = std::stoi(substring.substr(substring.find('"')+1));
		Unit* hi = new Unit(hp,dmg,name);
		return hi;
	}else{
		throw std::runtime_error("File not found!");
	}
}