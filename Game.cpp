#include "Game.h"
#include "Map.h"

void Game::setMap(Map map)
{
    
}
void Game::putHero(Hero hero,int x,int y)
{
    if(map.get(x,y) == Map::Free)
    {
        hero_location = std::make_pair(x+1,y);
        this->hero = new Hero(hero);
    }
    else throw Game::OccupiedException("Location is not avaibile! \n");
}
void Game::putMonster(Monster monster,int x, int y)
{
    if(map.get(x,y) == Map::Free && Game::checkForMonsters(x,y) < 2)
        monster_locations.push_back(std::make_pair(monster,std::make_pair(x,y)));

    else throw Game::OccupiedException("Location is not avaibile! \n");
}
bool Game::freetoStep(int x,int y) const
{
    for(auto iter = monster_locations.begin();iter != monster_locations.end();iter++)
    {
        if(iter->second.first == x && iter->second.second == y)
            return false;
    }
    if((hero_location.first == x && hero_location.second == y) || (hero_location.first-1 == x && hero_location.second == y))
        return false;
    
    return true;
}
void Game::stepOn(int x, int y)
{
    if(map.get(x-1,y) == Map::Wall) throw Game::OccupiedException("Can't move here there is a Wall !\n");

    for(auto iter = monster_locations.begin();iter != monster_locations.end();iter++)
    {
        if(iter->second.first == x - 1 && iter->second.second == y)
        {
            this->hero->fightTilDeath(iter->first);
            if(hero->isAlive())
            {
                iter = monster_locations.erase(iter);
            }
        }
        if(iter->second.first +1 == x && iter->second.second == y)
        {
            this->hero->fightTilDeath(iter->first);
            if(hero->isAlive())
            {
                iter = monster_locations.erase(iter);
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
    Game::stepOn(hero_location.first,hero_location.second);
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
    if(hero->isAlive())
        std::cout << hero->getName() << " cleared the map !\n";
    else std::cout << "Hero died !\n";



}
unsigned int Game::checkForMonsters(int x,int y) const
{
    int i = 0;
    for(auto iter = monster_locations.begin();iter != monster_locations.end();iter++)
        if(iter->second.first == x && iter->second.second == y) i++;

    return i;
}
bool Game::checkForHero(int x,int y) const
{
    if((x == hero_location.first-1 && y == hero_location.second))
    {
        std::cout << HERO;
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
            if(checkForMonsters(x,y) == 1) std::cout << MONSTERONE;
            else if(checkForMonsters(x,y) == 2) std::cout << MONSTERTWO;
            else if (checkForHero(x,y));
            else if (map.get(x,y) == Map::Wall) std::cout << WALL_FIELD;
            else if (map.get(x,y) == Map::Free) std::cout << FREE_FIELD;
        }
        std::cout << VERTICAL << "\n";
    }
    std::cout << BOTTOM_LEFT;
    int height = map.getHeight() -1;
    for(int i = 0;i < map.getRowWidth(height);i++)
        std::cout << HORIZONTAL;
    
    std::cout << BOTTOM_RIGHT << "\n";



}