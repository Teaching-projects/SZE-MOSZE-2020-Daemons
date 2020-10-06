/**
 * \class Unit
 * 
 * \brief  Unit Class
 * 
 * This class stores a Unit hp, damage, name, atkcooldown in private, getters in public and an Attack method 
 * which implement 2 Unit type Object fight with each other
 *
 * 
 * 
 * \author  mesmatyi, kulcsarbence, Lazar-Source
 * 
 * \version 1.0
 * 
 * \date 2020/10/06 14:18
 * 
 * Created on 2020/10/06 14:18
 */
#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Unit
{
private:
	int hp; ///< the hp of the Unit
	const int dmg; ///< the damage of the Unit
	const std::string name; ///<The name of the Unit
	const double atkcooldown; ///<The atkcooldown of the Unit, which is a number, represents how many second between to attacks.
	void takeDamage(const Unit& enemy); ///< private Method for takeDamage if the enemy attacked the Unit 
public:
	int getHp() const; ///<Simple Getter for hp
	int getDmg() const;///<Simple Getter for damage
	std::string getName() const; ///<Simple Getter for name
	double getAs() const; ///<Simple Getter for attackcooldown
	void Fight( Unit* enemy);  ///<Method that implements the Fight between two Unit object
	Unit(const int& h, const int& d, const std::string& n, const double& a) : hp(h), dmg(d), name(n), atkcooldown(a){}
	static Unit* parseUnit(const std::string& filename);///<Method that parse Units Json files and return the generated Unit Object with the parsed data
};
