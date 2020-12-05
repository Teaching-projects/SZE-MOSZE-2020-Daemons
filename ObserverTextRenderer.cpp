#include "ObserverTextRenderer.h"
#include "Game.h"

void ObserverTextRenderer::render(Game& gm) const{
    
    int maxwidth = 0;
    for(int i = 0;i < gm.map.getHeight();i++)
        if(maxwidth < gm.map.getRowWidth(i)) maxwidth = gm.map.getRowWidth(i);


    out_stream << gm.TOP_LEFT;
    for(int i = 0;i < maxwidth;i++)
        out_stream << gm.HORIZONTAL;
    
    out_stream << gm.TOP_RIGHT << "\n";

    for(int y = 0;y < gm.map.getHeight();y++)
    {
        out_stream << gm.VERTICAL;
        for(int x = 0;x < gm.map.getRowWidth(y);x++)
        {
            if (gm.checkForHero(x,y)){
                out_stream << gm.HERO;
            }
            else if(gm.checkForMonsters(x,y) == 1) out_stream << gm.MONSTERONE;
            else if(gm.checkForMonsters(x,y) >= 2) out_stream << gm.MONSTERTWO;
            else if (gm.map.get(x,y) == Map::Free) out_stream << gm.FREE_FIELD;
            else out_stream << gm.WALL_FIELD;
        }
        for(int i = 0;i<=(maxwidth - gm.map.getRowWidth(y)-1);i++)
            out_stream << gm.WALL_FIELD;
        out_stream << gm.VERTICAL << "\n";
    }
    out_stream << gm.BOTTOM_LEFT;
    for(int i = 0;i < maxwidth;i++)
        out_stream << gm.HORIZONTAL;
    
    out_stream << gm.BOTTOM_RIGHT << "\n";
}