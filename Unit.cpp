#include "Unit.h"
#include <math.h>

double Unit::getHp() const
{
	return hp;
}

double Unit::getDmg() const
{
	return dmg;
}

std::string Unit::getName() const
{
	return name;
}

void Unit::takeDamage(Unit& enemy)
{
	double dmg_taken = hp;
	double damage = enemy.getDmg();
	hp -= damage;
	if (hp < 0)
	{
		hp = 0;
	}
	dmg_taken = dmg_taken - hp;
	enemy.boost_xp(dmg_taken);
	
}
void Unit::boost_xp(const double& dmg)
{
	xp += dmg;
	double level_xp = xp/100.0;
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


Unit Unit::parseUnit(const std::string& data){
	std::map<std::string, std::string> returnedMap = JsonParser::parseJSON(data);
	return Unit(std::stod(returnedMap["hp"]),std::stod(returnedMap["dmg"]),returnedMap["name"]);
}
