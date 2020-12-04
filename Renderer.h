#pragma once
#include "Game.h"
class Game;

class Renderer{
    private:
    public:
        virtual void render(Game&) const = 0;
};