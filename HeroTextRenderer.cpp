#include "HeroTextRenderer.h"



void HeroTextRenderer::render(Game& gm) const {

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
    std::cout << gm.TOP_LEFT;
    int w = 0;
    while(w < width && w  <= gm.map.getRowWidth(0))
    {
        std::cout << gm.HORIZONTAL;
        w++;
    }
    
    std::cout << gm.TOP_RIGHT << "\n";


    int i=print_y_min; 
    while(i <= print_y_max && i < gm.map.getHeight())
    {
        std::cout << gm.VERTICAL;
        int j=print_x_min;
        while(j <= print_x_max && j < gm.map.getRowWidth(i))
        {
            if (gm.checkForHero(j,i)){
                std::cout << gm.HERO;
            }
            else if(gm.checkForMonsters(j,i) == 1) std::cout << gm.MONSTERONE;
            else if(gm.checkForMonsters(j,i) >= 2) std::cout << gm.MONSTERTWO;
            else if (gm.map.get(j,i) == Map::Free) std::cout << gm.FREE_FIELD;
            else std::cout << gm.WALL_FIELD;
            j++;
        }
        for(int m = gm.map.getRowWidth(i);m<=print_x_max;m++)
            std::cout << gm.WALL_FIELD;
        std::cout << gm.VERTICAL << "\n";
        i++;
    }

    std::cout << gm.BOTTOM_LEFT;
    
    for(int i = 0;i<w;i++)
        std::cout << gm.HORIZONTAL;
    
    std::cout << gm.BOTTOM_RIGHT << "\n";

}