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
    //mapPrinter();
    //Game::mapPrinter();
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

        //mapPrinterWithLightRadius();
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
        return true;
    }
    return false;
}

void Game::mapPrinterWithLightRadius(std::ostream& o_str)
{
    int maxwidth = 0;             
    int maxheight=map.getHeight();                                     
    int hero_x=hero_location.first;
    int hero_y=hero_location.second; 
    int print_x_min=hero_x-hero->getLightRadius();
    int print_x_max=hero_x+hero->getLightRadius();
    int print_y_min=hero_y-hero->getLightRadius();
    int print_y_max=hero_y+hero->getLightRadius();
    int width;
    for(int i = 0;i < map.getHeight();i++)
        if(maxwidth < map.getRowWidth(i)) maxwidth = map.getRowWidth(i);
    if(print_x_min<0)
    {
        print_x_min=0;
        width=hero_x+hero->getLightRadius()+1;
    }
    else
    {
        width=print_x_max-print_x_min+1;
    }
    if(print_x_max>maxwidth) print_x_max=maxwidth;
    if(print_y_min<0)
    {
        print_y_min=0;
    }
    if(print_y_max>maxheight) print_y_max=maxheight;
    o_str << TOP_LEFT;
    int w = 0;
    while(w < width && w  <= map.getRowWidth(0))
    {
        o_str << HORIZONTAL;
        w++;
    }
    
    o_str << TOP_RIGHT << "\n";


    int i=print_y_min; 
    while(i <= print_y_max && i < map.getHeight())
    {
        o_str << VERTICAL;
        int j=print_x_min;
        while(j <= print_x_max && j < map.getRowWidth(i))
        {
            if (checkForHero(j,i)){
                o_str << HERO;
            }
            else if(checkForMonsters(j,i) == 1) o_str << MONSTERONE;
            else if(checkForMonsters(j,i) >= 2) o_str << MONSTERTWO;
            else if (map.get(j,i) == Map::Free) o_str << FREE_FIELD;
            else o_str << WALL_FIELD;
            j++;
        }
        for(int m = map.getRowWidth(i);m<=print_x_max;m++)
            o_str << WALL_FIELD;
        o_str << VERTICAL << "\n";
        i++;
    }

    o_str << BOTTOM_LEFT;
    
    for(int i = 0;i<w;i++)
        o_str << HORIZONTAL;
    
    o_str << BOTTOM_RIGHT << "\n";

}

std::string Game::mapPrinterSVG(){

    std::string o_str;


    std::string heroSVG = hero->getHeroSVG();
    if(!std::filesystem::exists(heroSVG)){
        heroSVG = "textures/not_found.svg";
    }
    std::string wall_field_svg = "textures/wall_field.svg";
    if(!std::filesystem::exists(wall_field_svg)){
        wall_field_svg = "textures/not_found.svg";
    }
    std::string free_field_svg = "textures/free_field.svg";
    if(!std::filesystem::exists(free_field_svg)){
        free_field_svg = "textures/not_found.svg";
    }

    int maxwidth = 0;
    for(int i = 0;i < map.getHeight();i++)
        if(maxwidth < map.getRowWidth(i)) maxwidth = map.getRowWidth(i);

    int maxheight = map.getHeight();
    o_str = "<svg version=\"1.1\" baseProfile=\"full\" width=\""+
    std::to_string(maxwidth*10)+"\" height=\""+
    std::to_string(maxheight*10)+
    "\" xmlns=\"http://www.w3.org/2000/svg\">";
    for(int y = 0;y < map.getHeight();y++)
    {
        for(int x = 0;x < map.getRowWidth(y);x++)
        {
            if (checkForHero(x,y)){
                o_str += "<image href=\""+heroSVG+"\" width=\"10\" height=\"10\" x=\""+std::to_string(x*10)+"\" "+
                "y=\""+std::to_string(y*10)+"\" />";
            }
            else if(checkForMonsters(x,y) == 1){
                
                o_str += "<image href=\""+getMonsterSVG(std::make_pair(x,y))+
                "\" width=\"10\" height=\"10\" x=\""+std::to_string(x*10)+"\""+
                " y=\""+std::to_string(y*10)+"\" />";
            } 
            else if (map.get(x,y) == Map::Free) o_str += "<image href=\""+free_field_svg+"\" width=\"10\" height=\"10\" x=\""+std::to_string(x*10)+"\" "+
                "y=\""+std::to_string(y*10)+"\" />";
            else o_str += "<image href=\""+wall_field_svg+"\" width=\"10\" height=\"10\" x=\""+std::to_string(x*10)+"\" "+
                "y=\""+std::to_string(y*10)+"\" />";
        }
        for(int i = 0;i<=(maxwidth - map.getRowWidth(y)-1);i++)
            o_str += "<image href=\""+wall_field_svg+"\" width=\"10\" height=\"10\" x=\""+std::to_string(i*10)+"\" "+
                "y=\""+std::to_string(y*10)+"\" />";
    }

    return o_str;


}

void Game::registerRenderer(Renderer* r){
    this->renderers.push_back(r);
}

std::string Game::mapPrinterSVGWithLightRadius(){

    std::string heroSVG = hero->getHeroSVG();
    if(!std::filesystem::exists(heroSVG)){
        heroSVG = "textures/not_found.svg";
    }
    std::string wall_field_svg = "textures/wall_field.svg";
    if(!std::filesystem::exists(wall_field_svg)){
        wall_field_svg = "textures/not_found.svg";
    }
    std::string free_field_svg = "textures/free_field.svg";
    if(!std::filesystem::exists(free_field_svg)){
        free_field_svg = "textures/not_found.svg";
    }

    std::string o_str;
    int maxwidth = 0;             
    int maxheight=map.getHeight();                                     
    int hero_x=hero_location.first;
    int hero_y=hero_location.second; 
    int print_x_min=hero_x-hero->getLightRadius();
    int print_x_max=hero_x+hero->getLightRadius();
    int print_y_min=hero_y-hero->getLightRadius();
    int print_y_max=hero_y+hero->getLightRadius();
    for(int i = 0;i < map.getHeight();i++)
        if(maxwidth < map.getRowWidth(i)) maxwidth = map.getRowWidth(i);
    if(print_x_min<0)
    {
        print_x_min=0;
        width=hero_x+hero->getLightRadius()+1;
    }
    else
    {
        width=print_x_max-print_x_min+1;
    }
    if(print_x_max>maxwidth) print_x_max=maxwidth;
    if(print_y_min<0)
    {
        print_y_min=0;
    }
    if(print_y_max>maxheight) print_y_max=maxheight;

     o_str = "<svg version=\"1.1\" baseProfile=\"full\" width=\""+std::to_string(maxwidth*10)+"\" height=\""+std::to_string(maxheight*10)+"\" xmlns=\"http://www.w3.org/2000/svg\">";

    int i=print_y_min; 
    while(i <= print_y_max && i < map.getHeight())
    {
        int j=print_x_min;
        while(j <= print_x_max && j < map.getRowWidth(i))
        {
            if (checkForHero(j,i)){
                o_str += "<image href=\""+heroSVG+"\" width=\"10\" height=\"10\" x=\""+std::to_string(j*10)+"\" "+
                "y=\""+std::to_string(i*10)+"\" />";
            }
            else if(checkForMonsters(j,i) == 1){
                o_str += "<image href=\""+getMonsterSVG(std::make_pair(j,i))+
                "\" width=\"10\" height=\"10\" x=\""+std::to_string(j*10)+"\""+
                " y=\""+std::to_string(i*10)+"\" />";
            }
            else if (map.get(j,i) == Map::Free) o_str += "<image href=\""+free_field_svg+"\" width=\"10\" height=\"10\" x=\""+std::to_string(j*10)+"\" "+
                "y=\""+std::to_string(i*10)+"\" />";
            else o_str += "<image href=\""+wall_field_svg+"\" width=\"10\" height=\"10\" x=\""+std::to_string(j*10)+"\" "+
                "y=\""+std::to_string(i*10)+"\" />";
            j++;
        }
        for(int m = map.getRowWidth(i);m<=print_x_max;m++)
            o_str += "<image href=\""+wall_field_svg+"\" width=\"10\" height=\"10\" x=\""+std::to_string(j*10)+"\" "+
                "y=\""+std::to_string(i*10)+"\" />";
        i++;
    }
    return o_str;

}

void Game::mapPrinter(std::ostream& o_str)
{
    int maxwidth = 0;
    for(int i = 0;i < map.getHeight();i++)
        if(maxwidth < map.getRowWidth(i)) maxwidth = map.getRowWidth(i);


    o_str << TOP_LEFT;
    for(int i = 0;i < maxwidth;i++)
        o_str << HORIZONTAL;
    
    o_str << TOP_RIGHT << "\n";

    for(int y = 0;y < map.getHeight();y++)
    {
        o_str << VERTICAL;
        for(int x = 0;x < map.getRowWidth(y);x++)
        {
            if (checkForHero(x,y)){
                o_str << HERO;
            }
            else if(checkForMonsters(x,y) == 1) o_str << MONSTERONE;
            else if(checkForMonsters(x,y) >= 2) o_str << MONSTERTWO;
            else if (map.get(x,y) == Map::Free) o_str << FREE_FIELD;
            else o_str << WALL_FIELD;
        }
        for(int i = 0;i<=(maxwidth - map.getRowWidth(y)-1);i++)
            o_str << WALL_FIELD;
        o_str << VERTICAL << "\n";
    }
    o_str << BOTTOM_LEFT;
    for(int i = 0;i < maxwidth;i++)
        o_str << HORIZONTAL;
    
    o_str << BOTTOM_RIGHT << "\n";



}
PreparedGame::PreparedGame(std::string markedmap)
{
    JSON remakredmap = JSON::parseFromFile(markedmap);
    std::string mapfile = remakredmap.get<std::string>("map");
    std::string herof = remakredmap.get<std::string>("hero");
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