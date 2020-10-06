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
std::string extractName(const std::string line)
{
	std::string name = line.substr(line.find(":"));
	name.erase(name.find_last_of('"'),name.length()-1);
	return name.substr(name.find_first_of('"')+1);
}

Unit* Unit::parseUnit(const std::string& data){
	std::map<std::string, std::string> returnedMap = JsonParser::parseJSON(data);
	std::cout << returnedMap["hp"] << std::endl;
	std::cout << returnedMap["dmg"] << std::endl;
	std::cout << returnedMap["name"] << std::endl;
	Unit* hi = new Unit(std::stoi(returnedMap["hp"]),std::stoi(returnedMap["dmg"]),returnedMap["name"]);
	return hi;
}
