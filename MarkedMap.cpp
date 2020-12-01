#include "MarkedMap.h"

std::pair<int,int> MarkedMap::getHeroPosition() const
{
    std::pair<int,int> hero;
    for(int i = 0;i < (int) vectormap.size();i++)
    {
        for(int j = 0; j < (int) vectormap[i].length();j++)
        {
            if(vectormap[i][j] == 'H')
                hero = std::make_pair(i,j);
        }
    }
    return hero;
}
MarkedMap::MarkedMap(std::string filename) {
    std::ifstream stream(filename);
    if(!stream.good()) throw std::runtime_error("File not found: " + filename);

    std::string currentLine;
    while(std::getline(stream, currentLine)){
        vectormap.push_back(currentLine);
    }
    stream.close();
}
std::vector<std::pair<int,int>> MarkedMap::getMonsterPositions(char c) const 
{

    std::vector<std::pair<int,int>> monster_loc;
    std::pair<int,int> coordinates;
    for(int i = 0;i < (int) vectormap.size();i++)
    {
        for(int j = 0; j < (int) vectormap[i].length();j++)
        {
            if(vectormap[i][j] == c)
                monster_loc.push_back(std::make_pair(i,j));
        }
    }
    
    return monster_loc;
}