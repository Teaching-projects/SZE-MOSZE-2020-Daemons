#pragma once

#include "SVGRenderer.h"

/*!
 * \class CharacterSVGRenderer
 * 
 * \brief CharacterSVGRenderer class
 * 
 * This is the CharacterSVGRenderer class, it controls the ligth radius map print out.  
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
class CharacterSVGRenderer : public SVGRenderer{
    private:
    public:
        CharacterSVGRenderer(std::string& fname) : SVGRenderer(fname){}

        void render(Game&) const override;
};