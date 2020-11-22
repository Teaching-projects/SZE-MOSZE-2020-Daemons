#pragma once

#include <map>
#include <string>
#include <vector>

class Map{

private:
 std::vector<std::string> vectormap;
 
 public:
        enum type {Free, Wall};
        Map(std::string filename);
        Map::type get(unsigned int x, unsigned int y) const;
        unsigned int getHeight() const;
        unsigned int getRowWidth(unsigned int row) const;

    
    class WrongIndexException : virtual public std::runtime_error {
        public:
            
         WrongIndexException(const std::string &err) : std::runtime_error( err) {}
    };
};
