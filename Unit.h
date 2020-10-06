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
	int hp;
	const int dmg;
	const std::string name;
public:
	int getHp() const;
	int getDmg() const;
	std::string getName() const;
	void takeDamage(const Unit& enemy);
	Unit(const int& h, const int& d, const std::string& n) : hp(h), dmg(d), name(n){}
	static Unit* parseUnit(const std::string& data);
};
