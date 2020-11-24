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
    std::list<std::pair<Monster,std::pair<int,int>>> monster_locations;
    bool game_running;

    const std::string TOP_LEFT = "\u2554";
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
    Game();
    Game(std::string mapfilename);
    void setMap(Map map);
    virtual void putHero(Hero hero,int x,int y);
    void putMonster(Monster monster,int x, int y);
    void run();
    void mapPrinter();
    void stepOn(int x,int y);
    unsigned int checkForMonsters(int x,int y) const;
    bool checkForHero(int x,int y) const;
    bool freetoStep(int x,int y) const;

    virtual ~Game()
    {
        delete this->hero;
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