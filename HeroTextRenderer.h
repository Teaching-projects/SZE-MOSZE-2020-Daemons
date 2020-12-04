#pragma once

#include "Game.h"
#include "TextRenderer.h"
#include "Hero.h"

class HeroTextRenderer : public TextRenderer{
    private:
    public:
        HeroTextRenderer() : TextRenderer(){}
        void render(Game& gm);
};