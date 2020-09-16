#pragma once
#include <string>
class Unit
{
private:
	const int hp;
	const int dmg;
	const std::string name;
	int * p_hp;
public:
	void SetHp(int HP);
	const int GetHp();
	const int GetDmg();
	const std::string GetName();
	const void TakeDamage(const int& damage);
	Unit(int h, int d, std::string n) : hp(h), dmg(d), name(n) 
	{
		p_hp = (int*)(&hp);
	}
	
};

