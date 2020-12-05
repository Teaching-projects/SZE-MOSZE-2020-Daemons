#pragma once
#include "Renderer.h"
#include <map>
#include "Game.h"

/*!
 * \class SVGRenderer
 * 
 * \brief SVGRenderer class
 * 
 * This is the SVGRenderer abstract class derived classes controls the SVG print out.  
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
class SVGRenderer : public Renderer{
    protected:
        std::string file_name;
    public:
        SVGRenderer(std::string& fname) : file_name(fname){}

        virtual void render(Game& gm) const = 0;
};