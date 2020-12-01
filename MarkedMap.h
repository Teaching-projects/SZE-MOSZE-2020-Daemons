#pragma once
#include "Map.h"
#include <string>
#include <vector>
#include <fstream>
#include <list>

class MarkedMap: Map
{
    public:
    
    std::pair<int,int> getHeroPosition() const;
    std::vector<std::pair<int,int>> getMonsterPositions(char c) const;
    MarkedMap(std::string filename);
    MarkedMap(){};
};