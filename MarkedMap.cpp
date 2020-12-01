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
    for(int y=0;y<vectormap.size();y++)
    {
        for(int x = 0;x < vectormap[y].length();x++)
        {
            if(vectormap[y][x] == '1')
            {
                std::pair<int,int> coordinates;
                coordinates=std::make_pair(x,y);
                monsters.push_back(std::make_pair("Zombie",coordinates));
               
            }
            if(vectormap[y][x] == '2')
            {
                std::pair<int,int> coordinates;
                coordinates=std::make_pair(x,y);
                monsters.push_back(std::make_pair("Fallen",coordinates));
               
            }
            if(vectormap[y][x] == '3')
            {
                std::pair<int,int> coordinates;
                coordinates=std::make_pair(x,y);
                monsters.push_back(std::make_pair("Blood Raven",coordinates));
               
            }
        }
    }
    stream.close();
}
std::list<std::pair<std::string,std::pair<int,int>>> MarkedMap::getMonsterPositions(char c) const 
{
    return monsters;


}