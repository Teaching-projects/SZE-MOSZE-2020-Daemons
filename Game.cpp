#include "Game.h"
#include "Map.h"
#include <string>


Game::Game(std::string mapfilename) : map(mapfilename) {};

void Game::setMap(Map map)
{
    
}
void Game::putHero(Hero hero,int x,int y)
{
    if(map.get(x,y) == Map::Free)
    {
        hero_location.push_back(std::make_pair(hero,std::make_pair(x,y)));
    }
}
void Game::putMonster(Monster monster,int x, int y)
{
    if(map.get(x,y) == Map::Free)
    {
        monster_locations.push_back(std::make_pair(monster,std::make_pair(x,y)));
    }
}
void Game::run()
{

}
void Game::mapPrinter()
{

}