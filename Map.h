#pragma once


#include <string>
#include <vector>
#include <fstream>

/*!
 * \class Map
 * 
 * \brief Map class
 * 
 * 
 * 
 * 
 * \author  Mesics Mátyás, Kulcsár Bence, Lázár Tamás
 * 
 * \version 4.0
 * 
 * \date 2020/12/03 11:30
 * 
 * Created on 2020/12/03 11:30
 */

class Map{

protected:
 std::vector<std::string> vectormap;///<vector that stores the map of the game
 
 public:
        enum type {Free, Wall};///<enum types of the map
        //!Constructor of the map
        /*!
        \param filename Valid txt file that contains a map
        */
        Map(std::string filename);
        //!Simple Constructor of the map
        Map(){};
        //!Simple getter for an exact spot of the map
        /*!
        \param x X coordinate of the map exact spot
        \param y Y coordinate of the maps exact spot
        \return Free or Wall, that stored in enum type
        */
        Map::type get(unsigned int x, unsigned int y) const;
        //!Simple getter for the Height of the map
        /*!
        \return const integer value
        */
        int getHeight() const;
        //!Simple getter for the Width of a line
        /*!
        \return const integer value
        */
        int getRowWidth(unsigned int row) const;

    
 
        class WrongIndexException : public std::runtime_error{
        public:
        WrongIndexException(const std::string &err) : std::runtime_error( err) {}
    };
};
