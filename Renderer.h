#pragma once
#include "Game.h"

class Renderer{
    private:
    public:
        virtual void render(const Game&) const = 0;
}