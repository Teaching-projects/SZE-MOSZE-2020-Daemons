#pragma once

#include "TextRenderer.h"

class ObserverTextRenderer : public TextRenderer{
    private:
    public:
        ObserverTextRenderer() : TextRenderer() {}
        void render(Game& gm);
}