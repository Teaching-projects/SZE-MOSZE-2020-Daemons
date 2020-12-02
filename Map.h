#pragma once


#include <string>
#include <vector>
#include <fstream>



class Map{

protected:
 std::vector<std::string> vectormap;
 
 public:
        enum type {Free, Wall};
        Map(std::string filename);
        Map(){};
        Map::type get(unsigned int x, unsigned int y) const;
        int getHeight() const;
        int getRowWidth(unsigned int row) const;

    
 
        class WrongIndexException : public std::runtime_error{
        public:
        WrongIndexException(const std::string &err) : std::runtime_error( err) {}
    };
};
