#pragma once
#include "Map.h"
#include <string>
#include <vector>
#include <fstream>
#include <list>

/*!
 * \class MarkedMap
 * 
 * \brief MarkedMap class
 * 
 * This is the MarkedMap class, we use it when the user gave us a map with monsters and Hero on it.
 * 
 * 
 * \author  Mesics Mátyás, Kulcsár Bence, Lázár Tamás
 * 
 * \version 4.0
 * 
 * \date 2020/12/03 11:48
 * 
 * Created on 2020/12/03 11:48
 */

class MarkedMap: public Map
{
    public:
    //!Simple Getter for the position of the Hero on the map
    /*!
    \return std::pair that contains the x and y coordinates
    */
    std::pair<int,int> getHeroPosition() const;
    //!Simple Getter for Monster on the Map
    /*!
    \param c a character that represents Monster types on the map
    \return a vector, containing std::pairs with x and y coordinates in them.
    */
    std::vector<std::pair<int,int>> getMonsterPositions(char c) const;
    //!Constructor of the MarkedMap
    /*!
    \param filename Text file that contains a map with Hero, and Monsters on it.
    */
    MarkedMap(std::string filename);
    MarkedMap(){};
};