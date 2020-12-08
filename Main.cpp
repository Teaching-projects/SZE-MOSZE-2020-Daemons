#include <iostream>
#include <map>
#include <string>
#include <filesystem>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <list>

#include "CharacterSVGRenderer.h"
#include "ObserverSVGRenderer.h"
#include "HeroTextRenderer.h"
#include "ObserverTextRenderer.h"

#include "JSON.h"
#include "Hero.h"
#include "Monster.h"
#include "Game.h"


const std::map<int,std::string> error_messages = {
    { 1 , "Bad number of arguments. Only a single scenario file should be provided." },
    { 2 , "The provided scenario file is not accessible." },
    { 3 , "The provided scenario file is invalid." },
    { 4 , "JSON parsing error." },
    { 5 , "Field occupied exception occured."},
    { 6 , "Already has hero exception occured."},
    { 7 , "Already has units exception occured."},
    { 8 , "Game already started exception occured."},
    { 9 , "Invalid direction exception occured."},
    { 10 , "Map already set exception occured."},
};

void bad_exit(int exitcode){
    std::cerr
        << (error_messages.count(exitcode) ? error_messages.at(exitcode) : "Unknown error")
        << std::endl;
    exit(exitcode);
}

int main(int argc, char** argv){
    if (argc != 2) bad_exit(1);
    if (!std::filesystem::exists(argv[1])) bad_exit(2);
    JSON scenario = JSON::parseFromFile(argv[1]);
    std::string hero_file;
    std::list<std::string> monster_files;
    if (scenario.count("hero")&&scenario.count("monsters")) {
            hero_file=scenario.get<std::string>("hero");
            JSON::list monster_file_list=scenario.get<JSON::list>("monsters");
            for(auto monster_file : monster_file_list)
                monster_files.push_back(std::get<std::string>(monster_file));
            Hero hero{Hero::parse(hero_file)};
             std::list<Monster> monsters;
            for (const auto& monster_file : monster_files)
                monsters.push_back(Monster::parse(monster_file));
        
        std::cout << "Give a path to the map file !\n";
        std::string mapfile;
        std::getline(std::cin,mapfile);
        Map map(mapfile);
        Game game{};
        game.setMap(map);
        for(const auto& iter : monsters)
        {
            game.mapPrinter();
            std::cout << "Give a location for the " << iter.getName() << " monster(Like: 3 5): \n";
            std::string xy,x,y;
            std::getline(std::cin,xy);
            x = xy.at(0);
            y = xy.at(2);
            int xc = std::stoi(x);
            int yc = std::stoi(y);
            game.putMonster(iter,xc,yc);
        }
        game.mapPrinter();
        std::cout << "Give a location for the " << hero.getName() << " Hero (Like: 3 5): \n";
        std::string xy,x,y;
        std::getline(std::cin,xy);
        x = xy.at(0);
        y = xy.at(2);
        int xc = std::stoi(x);
        int yc = std::stoi(y);
        game.putHero(hero,xc,yc);
        game.registerRenderer(new HeroTextRenderer());
        game.run();
        }
    else if(scenario.count("monster-1")&& scenario.count("hero")&&scenario.count("map")&&scenario.count("wall-texture"))
    {
        try
        {
        PreparedGame game(argv[1]);
        std::ofstream stream = std::ofstream("log.txt");
        std::string svgrend = "pretty.svg";
        std::string svgrend2 = "pretty_observer.svg";
        game.registerRenderer(new HeroTextRenderer());
        game.registerRenderer(new ObserverTextRenderer(stream));
        game.registerRenderer(new CharacterSVGRenderer(svgrend));
        game.registerRenderer(new ObserverSVGRenderer(svgrend2));
        game.run();
        }
     catch (const JSON::ParseException& e) {bad_exit(4);}
    catch(const Game::OccupiedException& e) {bad_exit(5);}
    catch(const Game::AlreadyHasHeroException& e) {bad_exit(6);}
    catch(const Game::AlreadyHasUnitsException& e) {bad_exit(7);}
    catch(const Game::GameAlreadyStartedException& e) {bad_exit(8);}
    catch(const Game::InvalidDirection& e) {bad_exit(9);}
    catch(const Game::MapAlreadySet& e) {bad_exit(10);}
    }

    return 0;
}
