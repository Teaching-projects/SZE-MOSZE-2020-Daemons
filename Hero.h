#pragma once
class Monster;
#include "Monster.h"
#include "Damage.h"
#include <string>

class Hero
{
    private:
        
        int hp; ///< the hp of the Hero
        const std::string name; ///<The name of the Hero
        double atkcooldown; ///<The atkcooldown of the Hero, which is a number, represents how many second between to attacks.
        unsigned int experience_per_level; ///< How many experience need the Hero to level up.
        unsigned int health_point_bonus_per_level;///< How many bonus health he has per levelup.
        unsigned int damage_bonus_per_level;///< How many bonus damage he has per levelup.
        double cooldown_multiplier_per_level;///< A Number which you multiply with cooldown.
        double defense;
        double defbonus_per_level;
        Damage damage;
        unsigned int magical_damage_bonus_per_level;
        int maxHP; ///< the max HP of the Hero
        unsigned int xp;///< the Experience of the Hero
	    unsigned int level;///< the level of the Hero
        unsigned int light_radius;
        unsigned int light_radius_bonus_per_level;
        
    public:
        Hero(
        const int& h, 
        const std::string& n, 
        double a,
        const unsigned int& experience_per_level,
        const unsigned int& health_point_bonus_per_level,
        const unsigned int& damage_bonus_per_level, 
        const double& cooldown_multiplier_per_level,
        const int& def ,
        const unsigned int& defbonus,
        Damage dmg,
        const unsigned int& magic_damage_bonus,
        const unsigned int& light_radius,
        const unsigned int& light_radius_bonus_per_level
        )
        : hp(h),
        name(n),
        atkcooldown(a),
        experience_per_level(experience_per_level), 
        health_point_bonus_per_level(health_point_bonus_per_level),
        damage_bonus_per_level(damage_bonus_per_level),
        cooldown_multiplier_per_level(cooldown_multiplier_per_level),
        defense(def),
        defbonus_per_level(defbonus),
        damage(dmg) ,
        magical_damage_bonus_per_level(magic_damage_bonus),
        light_radius(light_radius),
        light_radius_bonus_per_level(light_radius_bonus_per_level)
        {
        maxHP=h;
        xp=0; 
        level=1;
        }
        virtual ~Hero(){};
        //!Method that parse Hero Json files and return the generated Hero Object with the parsed data
        /*!
        \return  Hero Object with the parsed data
        \param filename json file's name that the method parses
        */
        static Hero parse(const std::string& filename);
        //!Method that represents the level up logic, and make the hero to max HP.
	    virtual void levelUp();
        //! Simple Getter for level
        /*!
        \return  integer level value
        */
        int getLevel() const;
        //! Method that represents the takeDamage logic from an enemy.
        void takeDamage(const Monster& enemy);
         //! Simple Getter for hp
        /*!
        \return  integer hp value
        */
        int getHealthPoints() const;
        //! Simple Getter for damage
        /*!
        \return  const integer damage value
        */
        int getphysDamage() const;
        int getmagicDamage() const;
         //! Simple Getter for XP
        /*!
        \return const  int XP  value
        */
        int getXP() const;
        //! Simple Getter for name
        /*!
        \return const  string name  value
        */
        std::string getName() const;
        //! Simple Getter for atkcooldown
        /*!
        \return   const double atkcooldown value
        */
        double getAttackCoolDown() const;
        //! Method that implements the Fight between two Unit object
        /*!
        \param enemy Monster Object
        */
        void fightTilDeath(Monster& enemy);
        // Getter only needed for unit tests
        int getMaxHealthPoints() const;
        //! Simple method that represents if the Hero is Alive or Not
        /*!
        \return  1 if hp>0 and 0 if else.
        */
        bool isAlive() const;
        void boostxp(const int dmg);
        int getDefense() const;
        Damage getDamage() const { return damage; }
        
        


};