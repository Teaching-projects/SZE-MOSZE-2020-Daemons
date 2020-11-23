#pragma once
class Hero;
#include "Hero.h"
#include "Damage.h"
#include <string>

class Monster
{
    protected:
       
       
        int hp; ///< the hp of the Unit
        const std::string name; ///<The name of the Unit
        const double atkcooldown; ///<The atkcooldown of the Unit, which is a number, represents how many second between to attacks.
        double defense;
        Damage damage;
    public:
        Monster(const int& h, const std::string& n, const double& a,const double& def,Damage dmg) : hp(h),name(n),atkcooldown(a),defense(def),damage(dmg){}
        //!Method that parse Monster Json files and return the generated Monster Object with the parsed data
        /*!
        \return  Monster Object with the parsed data
        \param filename json file's name that the method parses
        */
        static Monster parse(const std::string& filename);
         //! Simple Getter for hp
        /*!
        \return  integer hp value
        */
        int getHealthPoints() const;
         //! Simple Getter for atkcooldown
        /*!
        \return   const double atkcooldown value
        */
        double getAttackCoolDown() const;
        //! Simple Getter for damage
        /*!
        \return  const integer damage value
        */
        int getphysDamage() const;
        int getmagicDamage() const;
        //! Simple method that represents if the Hero is Alive or Not
        /*!
        \return  1 if hp>0 and 0 if else.
        */
        bool isAlive() const;
        //! Simple Getter for name
        /*!
        \return const  string name  value
        */
        std::string getName() const;
         //! Method that represents the takeDamage logic from an enemy.
          /*!
        \param filename Hero Object Reference
        */
        void takeDamage(Hero& enemy);
        double getDefense() const;
        
};
