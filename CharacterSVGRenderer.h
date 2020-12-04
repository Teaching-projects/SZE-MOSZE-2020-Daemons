#pragma once

#include "SVGRenderer.h"

class CharacterSVGRenderer : public SVGRenderer{
    private:
    public:
        CharacterSVGRenderer(std::string& fname) : SVGRenderer(fname){}

        void render(Game&) const;
};