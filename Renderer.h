#pragma once
class Game;
#include "Game.h"


class Renderer{
    private:
    public:
        virtual void render(Game& gm) const = 0;
        virtual ~Renderer(){delete this;};
};