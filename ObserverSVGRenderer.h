#pragma once

#include "SVGRenderer.h"

class ObserverSVGRenderer : public SVGRenderer{
    private:
    public:
        ObserverSVGRenderer(std::string& fname) : SVGRenderer(fname){}

        void render(Game&) const override;

        //virtual ~ObserverSVGRenderer(){};
};