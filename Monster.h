#pragma once
class Hero;
#include "Hero.h"
#include <string>

class Monster
{
    protected:
        int hp; ///< the hp of the Unit
        int dmg; ///< the damage of the Unit
        const std::string name; ///<The name of the Unit
        const double atkcooldown; ///<The atkcooldown of the Unit, which is a number, represents how many second between to attacks.
    public:
        Monster(const int& h, const int& d, const std::string& n, const double& a) : hp(h),dmg(d),name(n),atkcooldown(a){}
        //!Method that parse Monster Json files and return the generated Monster Object with the parsed data
        /*!
        \return  Monster Object with the parsed data
        \param filename json file's name that the method parses
        */
        static Monster parse(const std::string& filename);
        int getHealthPoints() const; 
        double getAttackCoolDown() const; 
        int getDamage() const;
        bool isAlive() const;
        std::string getName() const;
        void takeDamage(Hero& enemy);
};