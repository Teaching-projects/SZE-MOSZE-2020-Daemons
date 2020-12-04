#pragma once

#include "SVGRenderer.h"

class CharacterSVGRenderer : public SVGRenderer{
    public:
    private:
        CharacterSVGRenderer(std::string& fname) : SVGRenderer(fname){}

        void render(Game&);
}