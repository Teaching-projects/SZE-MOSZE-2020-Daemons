#pragma once
#include "Map.h"
#include "Hero.h"
#include "Monster.h"
#include "JSON.h"
#include "MarkedMap.h"
#include <string>
#include <list>
#include <iostream>
/*!
 * \class Game
 * 
 * \brief Game class
 * 
 * 
 * 
 * 
 * \author  Mesics Mátyás, Kulcsár Bence, Lázár Tamás
 * 
 * \version 4.0
 * 
 * \date 2020/12/03 10:49
 * 
 * Created on 2020/12/03 10:49
 */


class Game{

private:
    Map map;///<Map object
    Hero *hero;///<Hero object
    std::pair<int,int> hero_location;///< Hero location on the map
    std::list<std::pair<Monster,std::pair<int,int>>> monster_locations;///<Monsters locations of the map
    bool mapset;///<The map was set or not
    bool game_running;///<The game is running or not
    bool heroset;///<The hero was set or not
    //!Method that move the hero, and if he is stepping on a Monster, they fight till death
    void stepOn(int x,int y);
    //! Method that sees if a Monster is on an exact spot of the map or not.
    /*!
    \return  the index of which Monster is on the spot of the monster_locations list.
    */
    unsigned int checkForMonsters(int x,int y) const;
    //! Method that send the HERO string to the cout if the hero is on an exact spot
    /*!
    \return  true if the hero is there, and false if not
    */
    bool checkForHero(int x,int y) const;
    //!Method that prints the entire map of the game
    void mapPrinter();
    //!Method that prints an exact range of the map around Hero.
    void mapPrinterWithLightRadius();
    //!
    /*!
    \return
    */

    const std::string TOP_LEFT = "\u2554";///<String value to print the map correctly
	const std::string TOP_RIGHT = "\u2557";
	const std::string VERTICAL = "\u2551";
	const std::string BOTTOM_LEFT = "\u255A";
	const std::string BOTTOM_RIGHT = "\u255D";
	const std::string HORIZONTAL = "\u2550\u2550";
	const std::string FREE_FIELD = "\u2591\u2591";
	const std::string WALL_FIELD = "\u2588\u2588";
	const std::string HERO = "\u2523\u252B";
	const std::string MONSTERONE = "\u004D\u2591";
    const std::string MONSTERTWO = "\u004D\u004D";
    
public:

    class OccupiedException : virtual public std::runtime_error{
        public:
        OccupiedException(const std::string &err) : std::runtime_error( err) {}
    };
    class AlreadyHasHeroException : virtual public std::runtime_error{
        public:
        AlreadyHasHeroException(const std::string &err) : std::runtime_error( err) {}
    };
    class AlreadyHasUnitsException : virtual public std::runtime_error{
        public:
        AlreadyHasUnitsException(const std::string &err) : std::runtime_error( err) {}
    };
    class GameAlreadyStartedException : virtual public std::runtime_error{
        public:
        GameAlreadyStartedException(const std::string &err) : std::runtime_error( err) {}
    };
    class InvalidDirection : virtual public std::runtime_error{
        public:
        InvalidDirection(const std::string &err) : std::runtime_error( err) {}
    };
    class MapAlreadySet : virtual public std::runtime_error{
        public:
        MapAlreadySet(const std::string &err) : std::runtime_error( err) {}
    };

    
    //!Method that puts the Hero on the map at the start of the game
    virtual void putHero(Hero hero,int x,int y);
    //!Method that puts Monsters on the map at the start of the game
    void putMonster(Monster monster,int x, int y);
    Game() : map(Map()),hero{nullptr},mapset(false),game_running(false),heroset(false){};
    explicit Game(std::string &mapfilename) : map(mapfilename),hero{nullptr},mapset(false),game_running(false),heroset(false) {};
    //!Method that read in the map from the file and store it
    void setMap(Map map);

    virtual ~Game()
    {
        delete this->hero;
    }

public:
    //! Method that starts after the map, hero and monsters initialized, and control the rest of the game.
    void run();

};


/*!
 * \class PreparedGame
 * 
 * \brief PreparedGame class
 * 
 * 
 * 
 * 
 * \author  Mesics Mátyás, Kulcsár Bence, Lázár Tamás
 * 
 * \version 4.0
 * 
 * \date 2020/12/03 10:49
 * 
 * Created on 2020/12/03 10:49
 */
class PreparedGame : private Game
{
    public:
        PreparedGame(std::string markedmap);
        using Game::run;
};