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
	const double dmg;
	const std::string name;
public:
	double getHp() const;
	double getDmg() const;
	std::string getName() const;
	void takeDamage(const Unit& enemy);
	Unit(const double& h, const double& d, const std::string& n) : hp(h), dmg(d), name(n){}
	static Unit* parseUnit(const std::string& data);
};
