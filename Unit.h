#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include "JsonParser.h"

class Unit
{
private:
	double hp;
	double dmg;
	const std::string name;
	double maxHP;
	unsigned int xp;
	unsigned int level;
	void boost_xp(const double& dmg);
	void levelUp();
public:
	double getHp() const;
	double getDmg() const;
	std::string getName() const;
	void takeDamage(Unit& enemy);
	Unit(const double& h, const double& d, const std::string& n) : hp(h), dmg(d), name(n),maxHP(hp),xp(0),level(1){}
	static Unit parseUnit(const std::string& filename);
};
