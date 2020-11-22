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

public:
    Game();
    Game(std::string mapfilename);
    void setMap(Map map);
    void putHero(Hero hero,int x,int y);
    void putMonster(Monster monster,int x, int y);
    void run();
    void mapPrinter();
    void stepOn(int x,int y);
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

};