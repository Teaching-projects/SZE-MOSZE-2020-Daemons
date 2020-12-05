#pragma once
#include "Renderer.h"
#include "Game.h"

/*!
 * \class TextRenderer
 * 
 * \brief TextRenderer class
 * 
 * This is an abstract class and the derived classes controls the print out with text.
 * 
 * 
 * \author  Mesics Mátyás, Kulcsár Bence, Lázár Tamás
 * 
 * \version 5.0
 * 
 * \date 2020/12/05 16:38
 * 
 * Created on 2020/12/05 16:38
 */
class TextRenderer : public Renderer
{
    protected:
        std::ostream& out_stream;
    public:
        TextRenderer(std::ostream& o = std::cout) : out_stream(o){}

        void setOutputStream(const std::ostream&);

        virtual void render(Game& gm) const = 0;
};