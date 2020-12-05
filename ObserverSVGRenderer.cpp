#include "ObserverSVGRenderer.h"
#include "Game.h"
#include <fstream>
#include <string>
#include <iostream>
#include <filesystem>

void ObserverSVGRenderer::render(Game& gm) const{
    
    //std::string svg_output = gm.mapPrinterSVG();
    std::string o_str;


    std::string heroSVG = gm.hero->getHeroSVG();
    if(!std::filesystem::exists(heroSVG)){
        heroSVG = "not_found.svg";
    }
    std::string wall_field_svg = "wall_field.svg";
    if(!std::filesystem::exists(wall_field_svg)){
        wall_field_svg = "not_found.svg";
    }
    std::string free_field_svg = "free_field.svg";
    if(!std::filesystem::exists(free_field_svg)){
        free_field_svg = "not_found.svg";
    }

    int maxwidth = 0;
    for(int i = 0;i < gm.map.getHeight();i++)
        if(maxwidth < gm.map.getRowWidth(i)) maxwidth = gm.map.getRowWidth(i);

    int maxheight = gm.map.getHeight();
    o_str = "<svg version=\"1.1\" baseProfile=\"full\" width=\""+
    std::to_string(maxwidth*10)+"\" height=\""+
    std::to_string(maxheight*10)+
    "\" xmlns=\"http://www.w3.org/2000/svg\">";
    for(int y = 0;y < gm.map.getHeight();y++)
    {
        for(int x = 0;x < gm.map.getRowWidth(y);x++)
        {
            if (gm.checkForHero(x,y)){
                o_str += "<image href=\""+heroSVG+"\" width=\"10\" height=\"10\" x=\""+std::to_string(x*10)+"\" "+
                "y=\""+std::to_string(y*10)+"\" />";
            }
            else if(gm.checkForMonsters(x,y) == 1){
                
                o_str += "<image href=\""+gm.getMonsterSVG(std::make_pair(x,y))+
                "\" width=\"10\" height=\"10\" x=\""+std::to_string(x*10)+"\""+
                " y=\""+std::to_string(y*10)+"\" />";
            } 
            else if (gm.map.get(x,y) == Map::Free) o_str += "<image href=\""+free_field_svg+"\" width=\"10\" height=\"10\" x=\""+std::to_string(x*10)+"\" "+
                "y=\""+std::to_string(y*10)+"\" />";
            else o_str += "<image href=\""+wall_field_svg+"\" width=\"10\" height=\"10\" x=\""+std::to_string(x*10)+"\" "+
                "y=\""+std::to_string(y*10)+"\" />";
        }
        int w = gm.map.getRowWidth(y);
        for(int i = 0;i<=(maxwidth - gm.map.getRowWidth(y)-1);i++)
        {
            o_str += "<image href=\""+wall_field_svg+"\" width=\"10\" height=\"10\" x=\""+std::to_string(w*10)+"\" "+
                "y=\""+std::to_string(y*10)+"\" />";
            w++;
        }
    }
    o_str += "</svg>";

    std::ofstream out(file_name);
    out << o_str;
    out.close();
}