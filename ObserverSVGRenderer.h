#pragma once

#include "SVGRenderer.h"

/*!
 * \class ObserverSVGRenderer
 * 
 * \brief ObserverSVGRenderer class
 * 
 * This is the ObserverSVGRenderer class, that controls the entire map print out with SVG.  
 * 
 *  
 * 
 * \author  Mesics Mátyás, Kulcsár Bence, Lázár Tamás
 * 
 * \version 5.0
 * 
 * \date 2020/12/05 16:34
 * 
 * Created on 2020/12/05 16:34
 */
class ObserverSVGRenderer : public SVGRenderer{
    private:
    public:
        ObserverSVGRenderer(std::string& fname) : SVGRenderer(fname){}

        void render(Game&) const override;
};