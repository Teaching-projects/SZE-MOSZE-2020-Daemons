#pragma once


#include <string>
#include <vector>
#include <fstream>

class Map{

private:
 std::vector<std::string> vectormap;
 
 public:
        enum type {Free, Wall};
        Map(std::string filename);
        Map::type get(unsigned int x, unsigned int y) const;
        class WrongIndexException : public std::runtime_error{
        public:
            
         WrongIndexException(const std::string &err) : std::runtime_error( err) {}
    };
};
