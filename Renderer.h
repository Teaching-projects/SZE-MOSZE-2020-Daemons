#pragma once
class Game;
#include "Game.h"
/*!
 * \class Renderer
 *
 * \brief Renderer class
 *
 * This is an abstract class and the derived classes controls the print out with SVG and text.
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

class Renderer{
    public:
        //!virtual method for class render
        virtual void render(Game& gm) const = 0;
        //!Virtual destructor for class Renderer
        virtual ~Renderer(){};
};
