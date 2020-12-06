#pragma once

#include "TextRenderer.h"
/*!
 * \class ObserverTextRenderer
 *
 * \brief ObserverTextRenderer class
 *
 * This is the ObserverTextRenderer class, that controls the entire map print out with Text.
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
class ObserverTextRenderer : public TextRenderer{
    public:
        ObserverTextRenderer(std::ostream& o = std::cout) : TextRenderer(o) {}
        void render(Game& gm) const override;
};
