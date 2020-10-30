#pragma once
#include "Unit.h"
#include "Hero.h"

class Monster : public Unit
{
    private:
    public:
        Monster(const int& h, const int& d, const std::string& n, const double& a) : Unit(h, d, n, a){}
        //!Method that parse Monster Json files and return the generated Monster Object with the parsed data
        /*!
        \return  Monster Object with the parsed data
        \param filename json file's name that the method parses
        */
        static Monster parse(const std::string& filename);
        
};