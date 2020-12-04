#include "HeroTextRenderer.h"



void HeroTextRenderer::render(Game& gm) {
    
    int maxwidth = 0;             
    int maxheight=gm.getMap().getHeight();                                     
    int hero_x=gm.getHeroLocation().first;
    int hero_y=gm.getHeroLocation().second; 
    Map map = gm.getMap();
    Hero* hero = gm.getHero();
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
    std::cout << TOP_LEFT;
    int w = 0;
    while(w < width && w  <= map.getRowWidth(0))
    {
        std::cout << HORIZONTAL;
        w++;
    }
    
    std::cout << TOP_RIGHT << "\n";


    int i=print_y_min; 
    while(i <= print_y_max && i < map.getHeight())
    {
        std::cout << VERTICAL;
        int j=print_x_min;
        while(j <= print_x_max && j < map.getRowWidth(i))
        {
            if (gm.checkForHero(j,i));
            else if(gm.checkForMonsters(j,i) == 1) std::cout << MONSTERONE;
            else if(checkForMonsters(j,i) >= 2) std::cout << MONSTERTWO;
            else if (map.get(j,i) == Map::Free) std::cout << FREE_FIELD;
            else std::cout << WALL_FIELD;
            j++;
        }
        for(int m = map.getRowWidth(i);m<=print_x_max;m++)
            std::cout << WALL_FIELD;
        std::cout << VERTICAL << "\n";
        i++;
    }

    std::cout << BOTTOM_LEFT;
    
    for(int i = 0;i<w;i++)
        std::cout << HORIZONTAL;
    
    std::cout << BOTTOM_RIGHT << "\n";

}