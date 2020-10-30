#pragma once
#include "Unit.h"

class Hero : public Unit
{
    private:
        unsigned int xp;
	    unsigned int level;
        unsigned int experience_per_level;
        unsigned int health_point_bonus_per_level;
        unsigned int damage_bonus_per_level;
        double cooldown_multiplier_per_level;
	    void levelUp();
        void Hero::fightTilDeath(Monster enemy);
    public:
        Hero(const int& h, const int& d, const std::string& n, const double& a,
        const unsigned int& experience_per_level, const unsigned int& health_point_bonus_per_level,
        const unsigned int& damage_bonus_per_level, const double& cooldown_multiplier_per_level) 
        : Unit(h, d, n, a), xp(0), level(1), experience_per_level(experience_per_level), health_point_bonus_per_level(health_point_bonus_per_level),
        damage_bonus_per_level(damage_bonus_per_level), cooldown_multiplier_per_level(cooldown_multiplier_per_level){}
        //!Method that parse Hero Json files and return the generated Hero Object with the parsed data
        /*!
        \return  Hero Object with the parsed data
        \param filename json file's name that the method parses
        */
        static Hero parse(const std::string& filename);
        
};