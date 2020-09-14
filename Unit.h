#pragma once
#include <string>
class Unit
{
private:
	int hp;
	int dmg;
	std::string name;
public:
	void SetHp(int HP);
	int GetHp();
	int GetDmg();
	std::string GetName();
	Unit(int h, int d, std::string n) : hp(h), dmg(d), name(n) {}
	~Unit();
};

