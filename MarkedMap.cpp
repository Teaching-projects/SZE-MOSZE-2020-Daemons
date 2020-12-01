#include "MarkedMap.h"

std::pair<int,int> MarkedMap::getHeroPosition() const
{
    
    return hero;

}
MarkedMap::MarkedMap(std::string filename) {
    std::ifstream stream(filename);
    if(!stream.good()) throw std::runtime_error("File not found: " + filename);

    std::string currentLine;
    while(std::getline(stream, currentLine)){
        vectormap.push_back(currentLine);
    }
    for(unsigned int y=0;y<vectormap.size();y++)
    {
        for(unsigned int  x = 0;x < vectormap[y].length();x++)
        {
            if(vectormap[y][x] == 'H')
                hero = std::make_pair(x,y);

            else if(vectormap[y][x] == '1')
            {
                std::pair<int,int> coordinates;
                coordinates=std::make_pair(x,y);
                monsters.push_back(std::make_pair("Zombie",coordinates));
               
            }
            else if(vectormap[y][x] == '2')
            {
                std::pair<int,int> coordinates;
                coordinates=std::make_pair(x,y);
                monsters.push_back(std::make_pair("Fallen",coordinates));
               
            }
            else if(vectormap[y][x] == '3')
            {
                std::pair<int,int> coordinates;
                coordinates=std::make_pair(x,y);
                monsters.push_back(std::make_pair("Blood Raven",coordinates));
               
            }
        }
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