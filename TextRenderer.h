#pragma once
class Renderer;
#include "Renderer.h"
#include "Game.h"

class TextRenderer : public Renderer
{
    protected:
        std::ostream& out_stream;
    public:
        TextRenderer() : out_stream(std::cout){}

        void setOutputStream(const std::ostream&);

        virtual void render(Game&) const = 0;
};