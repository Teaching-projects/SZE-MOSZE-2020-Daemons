#pragma once
#include "Renderer.h"
#include <map>
#include "Game.h"

class SVGRenderer : public Renderer{
    protected:
        std::string file_name;
    public:
        SVGRenderer(std::string& fname) : file_name(fname){}

        virtual void render(Game& gm) const = 0;
};