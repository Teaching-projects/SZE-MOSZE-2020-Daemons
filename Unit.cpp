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
	std::stringstream buffer;
	buffer << file.rdbuf();
	std::string data = buffer.str();
	std::string name = data.substr(data.find("name"), data.find(","));
	name = name.substr(name.find('"'), name.find_last_of('"'));
	std::cout << name << std::endl;
	Unit* aha = new Unit(150,150,"semmi");
	return aha;
}