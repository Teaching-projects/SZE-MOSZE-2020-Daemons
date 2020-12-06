#include "CharacterSVGRenderer.h"
#include "Game.h"
#include <fstream>
#include <string>
#include <iostream>
#include <filesystem>

void CharacterSVGRenderer::render(Game& gm) const{

    std::string heroSVG = gm.hero->getHeroSVG();
    if(!std::filesystem::exists(heroSVG)){
        heroSVG = "not_found.svg";
    }
    std::string wall_field_svg = gm.GetWall();
    if(!std::filesystem::exists(wall_field_svg)){
        wall_field_svg = "not_found.svg";
    }
    std::string free_field_svg = gm.GetFree();
    if(!std::filesystem::exists(free_field_svg)){
        free_field_svg = "not_found.svg";
    }

    std::string o_str;
    int maxwidth = 0;
    int maxheight=gm.map.getHeight();
    int hero_x=gm.hero_location.first;
    int hero_y=gm.hero_location.second;
    int print_x_min=hero_x-gm.hero->getLightRadius();
    int print_x_max=hero_x+gm.hero->getLightRadius();
    int print_y_min=hero_y-gm.hero->getLightRadius();
    int print_y_max=hero_y+gm.hero->getLightRadius();
    int width;
    for(int i = 0;i < gm.map.getHeight();i++)
        if(maxwidth < gm.map.getRowWidth(i)) maxwidth = gm.map.getRowWidth(i);
    if(print_x_min<0)
    {
        print_x_min=0;
        width=hero_x+gm.hero->getLightRadius()+1;
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

     o_str = "<svg version=\"1.1\" baseProfile=\"full\" width=\""+std::to_string((width+1)*10)+"\" height=\""+std::to_string((print_y_max+1)*10)+"\" xmlns=\"http://www.w3.org/2000/svg\">";

    int i=print_y_min;
    while(i <= print_y_max && i < gm.map.getHeight())
    {
        int j=print_x_min;
        while(j <= print_x_max && j < gm.map.getRowWidth(i))
        {
            if (gm.checkForHero(j,i)){
                o_str += "<image href=\""+heroSVG+"\" width=\"10\" height=\"10\" x=\""+std::to_string(j*10)+"\" "+
                "y=\""+std::to_string(i*10)+"\" />";
            }
            else if(gm.checkForMonsters(j,i) == 1){
                o_str += "<image href=\""+gm.getMonsterSVG(std::make_pair(j,i))+
                "\" width=\"10\" height=\"10\" x=\""+std::to_string(j*10)+"\""+
                " y=\""+std::to_string(i*10)+"\" />";
            }
            else if (gm.map.get(j,i) == Map::Free) o_str += "<image href=\""+free_field_svg+"\" width=\"10\" height=\"10\" x=\""+std::to_string(j*10)+"\" "+
                "y=\""+std::to_string(i*10)+"\" />";
            else o_str += "<image href=\""+wall_field_svg+"\" width=\"10\" height=\"10\" x=\""+std::to_string(j*10)+"\" "+
                "y=\""+std::to_string(i*10)+"\" />";
            j++;
        }
        int w = gm.map.getRowWidth(i);
        for(int g = 0;g<=(maxwidth - gm.map.getRowWidth(i)-1);g++)
        {
            o_str += "<image href=\""+wall_field_svg+"\" width=\"10\" height=\"10\" x=\""+std::to_string(w*10)+"\" "+
                "y=\""+std::to_string(i*10)+"\" />";
            w++;
        }
        i++;
    }
    o_str += "</svg>";
    std::ofstream out(file_name);
    out << o_str;
    out.close();
}
