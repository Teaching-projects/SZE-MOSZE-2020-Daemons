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
    int dmg; ///< the damage of the Unit
	const std::string name; ///<The name of the Unit
	const double atkcooldown; ///<The atkcooldown of the Unit, which is a number, represents how many second between to attacks.
	void takeDamage(Unit& enemy); ///< private Method for takeDamage if the enemy attacked the Unit 
	int maxHP;
	unsigned int xp;
	unsigned int level;
	void boost_xp(const int& dmg);
	void levelUp();
public:
    //! Simple Getter for hp
    /*!
      \return  const integer hp value
     
    */
	int getHp() const; 
	//! Simple Getter for damage
    /*!
	 \return  const integer damage value
	*/
	int getDmg() const;
	//! Simple Getter for name
    /*!
	 \return const  string name  value
	*/
	std::string getName() const;
	//! Simple Getter for atkcooldown
    /*!
	 \return   const double atkcooldown value
	*/
	double getAs() const; 
	//! Method that implements the Fight between two Unit object
    /*!
	 \return  double atkcooldown value
	 \param enemy Unit Objects pointer
	*/
	void Fight( Unit* enemy);  
	
	Unit(const int& h, const int& d, const std::string& n, const double& a) : hp(h), dmg(d), name(n), atkcooldown(a),maxHP(hp),xp(0),level(1){} ///<Constructor
	//!Method that parse Units Json files and return the generated Unit Object with the parsed data
	/*!
	 \return  Unit Object with the parsed data
	 \param filename json file's name that the method parses
	*/
	static Unit parseUnit(const std::string& filename);
	
};
