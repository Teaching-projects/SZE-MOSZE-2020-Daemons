#pragma once

#include "SVGRenderer.h"

class ObserverSVGRenderer : public SVGRenderer{
    public:
    private:
        ObserverSVGRenderer(std::string& fname) : SVGRenderer(fname){}

        void render(Game&);
};