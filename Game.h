#pragma once
#include "Map.h"
#include "Hero.h"
#include <string>


class Game{

private:
    std::vector<std::pair<int,int>> enemy_location;
    std::pair<int,int> hero_location;
    Map map;

public:
    Game();
    Game(std::string mapfilename);
    void setMap(Map map);
    void putHero(Hero hero, int x,int y);
    void putMonster(Monster monster,int x, int y);
    void run();
    void mapPrinter();


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

};