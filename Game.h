#pragma once
#include "Map.h"
#include "Hero.h"
#include "Monster.h"
#include <string>
#include <list>
#include <iostream>


class Game{

private:
    Map map;
    Hero *hero;
    std::pair<int,int> hero_location;
    std::vector<std::pair<Monster,std::pair<int,int>>> monster_locations;
    bool game_running;

    const std::string TOP_LEFT = "\u2554";
	const std::string TOP_RIGHT = "\u2557";
	const std::string BOTTOM_LEFT = "\u255A";
	const std::string BOTTOM_RIGHT = "\u255D";
	const std::string HORIZONTAL = "\u2550\u2550";
	const std::string VERTICAL = "\u2551";
	const std::string HALF_FREE_FIELD = "\u2592";
	const std::string FREE_FIELD = HALF_FREE_FIELD + HALF_FREE_FIELD;
	const std::string WALL_FIELD = "\u2598\u2598";
	const std::string HEROLEFT = "\u2523";
	const std::string HERORIGHT = "\u252B";
	const std::string MONSTER = "\u004D";

public:
    Game();
    Game(std::string mapfilename);
    void setMap(Map map);
    void putHero(Hero hero,int x,int y);
    void putMonster(Monster monster,int x, int y);
    void run();
    void mapPrinter();
    void stepOn(int x,int y);
    bool checkForMonsters(int x,int y) const;
    bool checkForHero(int x,int y) const;
    ~Game()
    {
        if(this->hero != nullptr) delete this->hero;
    }

    class OccupiedException : virtual public std::runtime_error {
        public:
            
        OccupiedException(const std::string &err) : std::runtime_error( err) {}
    };
    class AlreadyHasHeroException : virtual public std::runtime_error {
        public:
            
        AlreadyHasHeroException(const std::string &err) : std::runtime_error( err) {}
    };
    class AlreadyHasUnitsException : virtual public std::runtime_error {
        public:
            
        AlreadyHasUnitsException(const std::string &err) : std::runtime_error( err) {}
    };
    class GameAlreadyStartedException : virtual public std::runtime_error {
        public:
            
        GameAlreadyStartedException(const std::string &err) : std::runtime_error( err) {}
    };
    class InvalidDirection : virtual public std::runtime_error {
        public:
            
        InvalidDirection(const std::string &err) : std::runtime_error( err) {}
    };

};