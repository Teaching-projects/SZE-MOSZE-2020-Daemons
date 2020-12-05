#pragma once
#include "Renderer.h"
#include "Game.h"

class TextRenderer : public Renderer
{
    protected:
        std::ostream& out_stream;
    public:
        TextRenderer(std::ostream& o = std::cout) : out_stream(o){}

        void setOutputStream(const std::ostream&);

        virtual void render(Game& gm) const = 0;
};