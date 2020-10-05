#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Unit
{
private:
	int hp;
	const int dmg;
	const std::string name;
	const double atkspeed;
	void takeDamage(const Unit& enemy);
public:
	int getHp() const;
	int getDmg() const;
	std::string getName() const;
	double getAs() const;
	void Fight( Unit* enemy);
	Unit(const int& h, const int& d, const std::string& n, const double& s) : hp(h), dmg(d), name(n), atkspeed(s){}
	static Unit* parseUnit(const std::string& filename);
};
