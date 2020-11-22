#include "Game.h"
#include "Map.h"

Game::Game(std::string mapfilename) : map(mapfilename) {};

void Game::setMap(Map map)
{
    
}
void Game::putHero(Hero hero,int x,int y)
{
    if(map.get(x,y) == Map::Free)
    {
        hero_location = std::make_pair(x,y);
        this->hero = new Hero(hero);
    }
    else throw Game::OccupiedException("Location is not avaibile! \n");
}
void Game::putMonster(Monster monster,int x, int y)
{
    if(map.get(x,y) == Map::Free)
    {
        monster_locations.push_back(std::make_pair(monster,std::make_pair(x,y)));
    }
    else throw Game::OccupiedException("Location is not avaibile! \n");
}
void Game::stepOn(int x, int y)
{
    if(map.get(x,y) == Map::Wall) throw Game::OccupiedException("Can't move here there is a Wall !\n");

    for(std::vector<std::pair<Monster,std::pair<int,int>>>::iterator iter = monster_locations.begin();iter != monster_locations.end();iter++)
    {
        if(iter->second.first == x && iter->second.second == y)
            this->hero->fightTilDeath(iter->first);
    }
    if(this->hero->isAlive())
        hero_location = std::make_pair(x,y);
    else
        std::cout << "The hero died.\n";
}
void Game::run()
{
    std::string move_direction;
    if(game_running) Game::GameAlreadyStartedException("Game is alredy running !\n");
    game_running = true;
    while(hero->isAlive() && !monster_locations.empty())
    {
        std::cin >> move_direction;
        if(move_direction == "north")
        {
            Game::stepOn(hero_location.first+1,hero_location.second);
        }
        else if(move_direction == "east")
        {
            Game::stepOn(hero_location.first,hero_location.second+1);
        }
        else if(move_direction == "south")
        {
            Game::stepOn(hero_location.first-1,hero_location.second);
        }
        else if(move_direction == "west")
        {
            Game::stepOn(hero_location.first,hero_location.second-1);
        }
    }


}
void Game::mapPrinter()
{

}