#include "Game.h"
#include "Map.h"
#include <filesystem>

void Game::setMap(Map map)
{
    if(!mapset)
    {
        this->map = map;
        mapset = true;
    }
    else Game::MapAlreadySet("Map already set!");

}
void Game::putHero(Hero hero,int x,int y)
{
    if(map.get(x,y) == Map::Free && !heroset && mapset)
    {
        hero_location = std::make_pair(x,y);
        this->hero = new Hero(hero);
        heroset = true;
    }
    else throw Game::OccupiedException("Location is not avaibile! \n");
}
void Game::putMonster(Monster monster,int x, int y)
{
    if(map.get(x,y) == Map::Free && mapset)
        monster_locations.push_back(std::make_pair(monster,std::make_pair(x,y)));

    else throw Game::OccupiedException("Location is not avaibile! \n");
}
void Game::stepOn(int x, int y)
{
    if(map.get(x,y) == Map::Wall) throw Game::OccupiedException("Can't move here there is a Wall !\n");

    auto iter = monster_locations.begin();
    while (iter != monster_locations.end() && !monster_locations.empty())
    {
        if(iter->second.first == x && iter->second.second == y)
        {
            this->hero->fightTilDeath(iter->first);

            if(hero->isAlive())
                iter = monster_locations.erase(iter);
            else break;
        }
        else iter++;
    }
    hero_location = std::make_pair(x,y);
}
void Game::run()
{

    if(game_running && mapset && heroset) Game::GameAlreadyStartedException("Game is alredy running !\n");
    game_running = true;
    if(oldmode)
    {
        mapPrinter();
    }
    for(auto &&renderer: renderers){
        renderer->render(*this);
    }
    Game::stepOn(hero_location.first,hero_location.second);
    while(hero->isAlive() && !monster_locations.empty())
    {
        std::cout << "Enter a heading to move ! (north, east, south, west)\n";
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
        else throw Game::InvalidDirection("Input contains invalid heading !\n");
        Game::mapPrinter();
        for(auto &&renderer: renderers){
            renderer->render(*this);
    }

    }
    if(hero->isAlive())
        std::cout << hero->getName() << " cleared the map !\n";
    else std::cout << "Hero died !\n";
    game_running = false;



}
unsigned int Game::checkForMonsters(int x,int y)
{
    int i = 0;
    for(auto iter = monster_locations.begin();iter != monster_locations.end();iter++)
        if(iter->second.first == x && iter->second.second == y) i++;

    return i;
}
std::string Game::getMonsterSVG(std::pair<int,int> loc) const
{
    for(auto iter = monster_locations.begin();iter != monster_locations.end();iter++)
        if(iter->second.first == loc.first && iter->second.second == loc.second)
            return iter->first.getSVG();
    return "";
}
bool Game::checkForHero(int x,int y)
{
    if((x == hero_location.first && y == hero_location.second && this->hero != nullptr))
    {
        if(oldmode)
        {
        std::cout << HERO;
        }
        return true;
    }
    return false;
}
std::string Game::GetWall() 
 {
     return wall;
 }
std::string Game::GetFree() 
 {
     return freeplace;
 }


void PreparedGame::registerRenderer(Renderer* r){
    this->renderers.push_back(r);
}
void Game::mapPrinter()
{
    int maxwidth = 0;
    for(int i = 0;i < map.getHeight();i++)
        if(maxwidth < map.getRowWidth(i)) maxwidth = map.getRowWidth(i);


    std::cout << TOP_LEFT;
    for(int i = 0;i < maxwidth;i++)
        std::cout << HORIZONTAL;
    
    std::cout << TOP_RIGHT << "\n";

    for(int y = 0;y < map.getHeight();y++)
    {
        std::cout << VERTICAL;
        for(int x = 0;x < map.getRowWidth(y);x++)
        {
            if (checkForHero(x,y));
            else if(checkForMonsters(x,y) == 1) std::cout << MONSTERONE;
            else if(checkForMonsters(x,y) >= 2) std::cout << MONSTERTWO;
            else if (map.get(x,y) == Map::Free) std::cout << FREE_FIELD;
            else std::cout << WALL_FIELD;
        }
        for(int i = 0;i<(maxwidth - map.getRowWidth(y));i++)
            std::cout << WALL_FIELD;
        std::cout << VERTICAL << "\n";
    }
    std::cout << BOTTOM_LEFT;
    for(int i = 0;i < maxwidth;i++)
        std::cout << HORIZONTAL;
    
    std::cout << BOTTOM_RIGHT << "\n";



}
void Game::SetOldMode(bool b)
{
    oldmode=b;
}
PreparedGame::PreparedGame(std::string markedmap)
{
    JSON remakredmap = JSON::parseFromFile(markedmap);
    std::string mapfile = remakredmap.get<std::string>("map");
    std::string herof = remakredmap.get<std::string>("hero");
    wall=remakredmap.get<std::string>("wall-texture");
    freeplace=remakredmap.get<std::string>("free-texture");
    std::vector<std::string> monsters_of;

    int mc = 1;
    while(true)
    {
        std::string search = "monster-" + std::to_string(mc);
        if(remakredmap.count(search))
            monsters_of.push_back(remakredmap.get<std::string>(search));
        else break;
        mc++;
    }

    MarkedMap map(mapfile);
    std::pair<int,int> hero_pos = map.getHeroPosition();
    Hero hero{Hero::parse(herof)};
    setMap(map);
    putHero(hero,hero_pos.second,hero_pos.first);

    for(int i = 0;i < (int) monsters_of.size();i++)
    {
        char c = '0' + (i+1);
        std::vector<std::pair<int,int>> monster = map.getMonsterPositions(c);
        Monster monsterone {Monster::parse(monsters_of[i])};
        for(std::vector<std::pair<int,int>>::const_iterator it = monster.begin();it != monster.end();it++)
        {
            putMonster(monsterone,it->second,it->first);
        }
    }

}
 