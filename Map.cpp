#include "Map.h"
#include <fstream>
#include <string>

Map::Map(std::string filename) {
    std::ifstream stream(filename);
    if(!stream.good()) throw std::runtime_error("File not found: " + filename);

    std::string currentLine;
    while(std::getline(stream, currentLine)){
        vectormap.push_back(currentLine);
    }

    stream.close();
}

Map::type Map::get(unsigned int x, unsigned int y) const {
    
    if(y >= vectormap.size() || y < 0)
        throw Map::WrongIndexException("y is out of range");
    
    if(x >= vectormap[y].length() || x < 0)
        throw Map::WrongIndexException("x is out of range");

    if(vectormap[y][x] == '#')
        return Map::type::Wall;
    else
        return Map::type::Free;
}
int Map::getHeight() const
{
    return vectormap.size();
}
int Map::getRowWidth(unsigned int row) const
{
    if(row > vectormap.size()) return 0;
    else return vectormap[row].length();
}