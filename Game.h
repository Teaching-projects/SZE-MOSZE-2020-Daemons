#pragma once
class Renderer;
#include "Map.h"
#include "Hero.h"
#include "Monster.h"
#include "JSON.h"
#include "MarkedMap.h"
#include "Renderer.h"
#include <string>
#include <list>
#include <iostream>
/*!
 * \class Game
 *
 * \brief Game class
 *
 * This is the Game Class that controls the game when you are running it.
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



protected:
    std::list<Renderer*> renderers;
public:

    const std::string TOP_LEFT = "\u2554";///<String value that stores a unicode character to print the map correctly
	const std::string TOP_RIGHT = "\u2557";///<String value that stores a unicode character to print the map correctly
	const std::string VERTICAL = "\u2551";///<String value that stores a unicode character to print the map correctly
	const std::string BOTTOM_LEFT = "\u255A";///<String value that stores a unicode character to print the map correctly
	const std::string BOTTOM_RIGHT = "\u255D";///<String value that stores a unicode character to print the map correctly
	const std::string HORIZONTAL = "\u2550\u2550";///<String value that stores a unicode character to print the map correctly
	const std::string FREE_FIELD = "\u2591\u2591";///<String value that stores a unicode character to print the map correctly
	const std::string WALL_FIELD = "\u2588\u2588";///<String value that stores a unicode character to print the map correctly
	const std::string HERO = "\u2523\u252B";///<String value that stores a unicode character to print the map correctly
	const std::string MONSTERONE = "\u004D\u2591";///<String value that stores a unicode character to print the map correctly
    const std::string MONSTERTWO = "\u004D\u004D";///<String value that stores a unicode character to print the map correctly
    bool checkForHeroSVG(int x, int y);
    std::string getMonsterSVG(std::pair<int,int> loc) const;
    std::pair<int,int> hero_location;///< Hero location on the map
    Map map;///<Map object
    Hero *hero;///<Hero object
    unsigned int checkForMonsters(int x,int y);
    //! Method that send the HERO string to the cout if the hero is on an exact spot
    /*!
    \return  true if the hero is there, and false if not
    */

    bool checkForHero(int x,int y);

    //!Method that prints the entire map of the game
    //void mapPrinter(std::ostream&);
    //!Method that prints an exact range of the map around Hero.
    //void mapPrinterWithLightRadius(std::ostream&);

    //std::string mapPrinterSVG();

    //std::string mapPrinterSVGWithLightRadius();

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
    ///! Constructor of the Game class it sets all boolean member to false, and create an object of Map
    Game() : map(Map()),hero{nullptr},mapset(false),game_running(false),heroset(false){};
    ///! Another Constructor of the Game class, it sets all boolean member to false and read in the map from a file
    explicit Game(std::string &mapfilename) : map(mapfilename),hero{nullptr},mapset(false),game_running(false),heroset(false) {};
    //!Method that read in the map from the file and store it
    void setMap(Map map);

    template<class T> inline void checked_delete(T * x)
    {
        typedef char type_must_be_complete[ sizeof(T)? 1: -1 ];
        (void) sizeof(type_must_be_complete);
        delete x;
    }

    virtual ~Game()
    {
        delete this->hero;
        for (auto r : renderers){
          checked_delete(r);
        }
    }
private:
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

public:
    //! Method that starts after the map, hero and monsters initialized, and control the rest of the game.
    void run();

};


/*!
 * \class PreparedGame
 *
 * \brief PreparedGame class
 *
 * This is the PreparedGame class, it uses the Game::run method, and in its constructor it waits for a file name that contains map, hero and monsters.
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
class PreparedGame : public Game
{
    public:
        //! Constructor for PreparedGame class
        PreparedGame(std::string markedmap);
        using Game::run;
        void registerRenderer(Renderer* r);
};
