#pragma once
#include "Unit.h"

class Hero : public Unit
{
    public:
        Hero(const int& h, const int& d, const std::string& n, const double& a) : Unit(h, d, n, a){}
        //!Method that parse Hero Json files and return the generated Hero Object with the parsed data
        /*!
        \return  Hero Object with the parsed data
        \param filename json file's name that the method parses
        */
        static Hero parse(const std::string& filename);
};