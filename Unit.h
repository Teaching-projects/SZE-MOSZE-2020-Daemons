#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Unit
{
private:
	int hp;
	int dmg;
	const std::string name;
	int maxHP;
	unsigned int current_xp;
	unsigned int level;
public:
	int getHp() const;
	int getDmg() const;
	std::string getName() const;
	void boost_xp(const int& dmg);
	void levelUp(const int lvl_step);
	void takeDamage(Unit& enemy);
	Unit(const int& h, const int& d, const std::string& n) : hp(h), dmg(d), name(n),maxHP(hp),current_xp(0),level(1){}
	static Unit parseUnit(const std::string& filename);
};
