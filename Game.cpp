#include "Game.h"
#include "Map.h"

Game::Game(std::string mapfilename) : map(mapfilename) {}

void Game::setMap(Map map)
{
    
}
void Game::putHero(Hero hero,int x,int y)
{
    if(map.get(x,y) == Map::Free && map.get(x,y-1) == Map::Free)
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
        std::cout << "Monster recieved!";
    }
    else throw Game::OccupiedException("Location is not avaibile! \n");
}
void Game::stepOn(int x, int y)
{
    if(map.get(x-1,y) == Map::Wall) throw Game::OccupiedException("Can't move here there is a Wall !\n");

    for(auto iter = monster_locations.begin();iter != monster_locations.end();iter++)
    {
        if(iter->second.first == x-1 && iter->second.second == y)
        {
            this->hero->fightTilDeath(iter->first);
            if(hero->isAlive())
            {
                monster_locations.erase(iter);
            }
            else
            {
                std::cout << "The hero died.\n";
                break;
            }
        }
    }
    hero_location = std::make_pair(x,y);
}
void Game::run()
{
    
    if(game_running) Game::GameAlreadyStartedException("Game is alredy running !\n");
    game_running = true;
    Game::mapPrinter();
    while(hero->isAlive() && !monster_locations.empty())
    {
        std::string move_direction;
        std::cin >> move_direction;
        if(move_direction == "east")
        {
            Game::stepOn(hero_location.first+1,hero_location.second);
        }
        else if(move_direction == "south")
        {
            Game::stepOn(hero_location.first,hero_location.second+1);
        }
        else if(move_direction == "west")
        {
            Game::stepOn(hero_location.first-1,hero_location.second);
        }
        else if(move_direction == "north")
        {
            Game::stepOn(hero_location.first,hero_location.second-1);
        }
        else throw Game::InvalidDirection("Input contains invalid direction !\n");
        Game::mapPrinter();
    }
    std::cout << (hero->isAlive() ? "The hero won." : "The hero died.") << std::endl;


}
bool Game::checkForMonsters(int x,int y) const
{
    for(auto iter = monster_locations.begin();iter != monster_locations.end();iter++)
        if(iter->second.first == x && iter->second.second == y) return true;

    return false;
}
bool Game::checkForHero(int x,int y) const
{
    if((x == hero_location.first-1 && y == hero_location.second))
    {
        std::cout << "┣┫";
        return true;
    }
    return false;
}

void Game::mapPrinter()
{
    std::cout << TOP_LEFT;
    for(int i = 0;i < map.getRowWidth(0);i++)
        std::cout << HORIZONTAL;
    
    std::cout << TOP_RIGHT << "\n";

    for(int y = 0;y < map.getHeight();y++)
    {
        std::cout << VERTICAL;
        for(int x = 0;x < map.getRowWidth(y);x++)
        {
            if(checkForMonsters(x,y)) std::cout << "M░";
            else if (checkForHero(x,y));
            else if (map.get(x,y) == Map::Wall) std::cout << "██";
            else if (map.get(x,y) == Map::Free) std::cout << "░░";
        }
        std::cout << VERTICAL << "\n";
    }
    std::cout << BOTTOM_LEFT;
    int height = map.getHeight() -1;
    for(int i = 0;i < map.getRowWidth(height);i++)
        std::cout << HORIZONTAL;
    
    std::cout << BOTTOM_RIGHT << "\n";



}