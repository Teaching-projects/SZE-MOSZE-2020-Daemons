#pragma once
class Hero;
#include "Hero.h"
#include "Damage.h"
#include <string>
/*!
 * \class Monster
 * 
 * \brief Monster class
 * 
 * 
 * 
 * 
 * \author  Mesics Mátyás, Kulcsár Bence, Lázár Tamás
 * 
 * \version 4.0
 * 
 * \date 2020/12/03 10:25
 * 
 * Created on 2020/12/03 10:25
 */


class Monster
{
    protected:
       
       
        int hp; ///< the hp of the Monster
        const std::string name; ///<The name of the Monster
        const double atkcooldown; ///<The atkcooldown of the Monster, which is a number, represents how many second between to attacks.
        int defense;///< The defense of the Monster it lowers the physical attack of the hero when it attack it
        Damage damage;///< Struct that contains the physical attack damage, and magic attack damage of the Monster
    public:
        Monster(const int& h, const std::string& n, const double& a,const int& def,Damage dmg) : hp(h),name(n),atkcooldown(a),defense(def),damage(dmg){}
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
        //! Simple Getter for physical damage
        /*!
        \return  const integer  physical damage value
        */
        int getphysDamage() const;
        //! Simple Getter for magical damage
        /*!
        \return  const integer magical damage value
        */
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
        //!Simple Getter for Defense
        /*!
        \return const integer defense value
        */
        int getDefense() const;
        
};
