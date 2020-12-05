#pragma once

#include "Game.h"
#include "TextRenderer.h"
#include "Hero.h"

/*!
 * \class HeroTextRenderer
 * 
 * \brief HeroTextRenderer class
 * 
 * 
 * 
 * 
 * \author  Mesics Mátyás, Kulcsár Bence, Lázár Tamás
 * 
 * \version 5.0
 * 
 * \date 2020/12/05 16:37
 * 
 * Created on 2020/12/05 16:37
 */
class HeroTextRenderer : public TextRenderer{
    private:
    public:
        HeroTextRenderer(std::ostream& o = std::cout) : TextRenderer(o){}
        void render(Game& gm) const override;
};