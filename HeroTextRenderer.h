#pragma once

#include "Game.h"
#include "TextRenderer.h"
#include "Hero.h"

class HeroTextRenderer : public TextRenderer{
    private:
    public:
        HeroTextRenderer(std::ostream& o = std::cout) : TextRenderer(o){}
        void render(Game& gm) const override;
        virtual ~HeroTextRenderer(){};
};