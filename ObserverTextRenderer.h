#pragma once

#include "TextRenderer.h"

class ObserverTextRenderer : public TextRenderer{
    private:
    public:
        ObserverTextRenderer(std::ostream& o = std::cout) : TextRenderer(o) {}
        void render(Game& gm) const;
};