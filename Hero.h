#pragma once
class Monster;
#include "Monster.h"
#include <string>

class Hero
{
    private:
        int hp; ///< the hp of the Unit
        int dmg; ///< the damage of the Unit
        const std::string name; ///<The name of the Unit
        double atkcooldown; ///<The atkcooldown of the Unit, which is a number, represents how many second between to attacks.
        int maxHP;
        unsigned int xp;
	    unsigned int level;
        unsigned int experience_per_level;
        unsigned int health_point_bonus_per_level;
        unsigned int damage_bonus_per_level;
        double cooldown_multiplier_per_level;
    public:
        Hero(const int& h, const int& d, const std::string& n, const double& a,
        const unsigned int& experience_per_level, const unsigned int& health_point_bonus_per_level,
        const unsigned int& damage_bonus_per_level, const double& cooldown_multiplier_per_level) 
        : hp(h),dmg(d),name(n),atkcooldown(a),maxHP(h), xp(0), level(1), experience_per_level(experience_per_level), health_point_bonus_per_level(health_point_bonus_per_level),
        damage_bonus_per_level(damage_bonus_per_level), cooldown_multiplier_per_level(cooldown_multiplier_per_level){}
        //!Method that parse Hero Json files and return the generated Hero Object with the parsed data
        /*!
        \return  Hero Object with the parsed data
        \param filename json file's name that the method parses
        */
        static Hero parse(const std::string& filename);
	    virtual void levelUp();
        int getLevel() const;

        void takeDamage(Monster& enemy);

        void fightTilDeath(Monster& enemy);
        int getHealthPoints() const; 
        //! Simple Getter for damage
        /*!
        \return  const integer damage value
        */
        int getDamage() const;
        //! Simple Getter for name
        /*!
        \return const  string name  value
        */
        int getXP() const;
        std::string getName() const;
        //! Simple Getter for atkcooldown
        /*!
        \return   const double atkcooldown value
        */
        double getAttackCoolDown() const; 
        //! Method that implements the Fight between two Unit object
        /*!
        \return  double atkcooldown value
        \param enemy Unit Objects pointer
        */
        // Getter only needed for unit tests
        int getMaxHealthPoints() const;

        bool isAlive() const;

        
};