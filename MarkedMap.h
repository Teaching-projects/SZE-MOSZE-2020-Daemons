#pragma once
#include "Map.h"
#include <string>
#include <vector>
#include <fstream>
#include <list>

class MarkedMap: Map
{
    private:
     std::list<std::pair<std::string,std::pair<int,int>>> monsters;
     std::pair<int,int> hero;
    public:
    
    std::pair<int,int> getHeroPosition() const;
    std::list<std::pair<std::string,std::pair<int,int>>> getMonsterPositions(char c) const;
    MarkedMap(std::string filename);
    MarkedMap(){};
};