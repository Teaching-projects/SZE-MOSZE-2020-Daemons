#pragma once
#include <string>
class Unit
{
private:
	int hp;
	const int dmg;
	const std::string name;
public:
	const int getHp();
	const int getDmg();
	const std::string getName();
	void takeDamage(const int& damage);
	Unit(const int& h, const int& d, const std::string& n) : hp(h), dmg(d), name(n){}
	
};

