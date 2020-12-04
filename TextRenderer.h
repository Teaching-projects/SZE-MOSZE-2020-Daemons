#pragma once
#include "Renderer.h"

class TextRenderer : public Renderer{
    protected:
        std::ostream& out_stream;
    public:
        TextRenderer() : out_stream(std::cout){}

        void setOutputStream(const std::ostream&);

        virtual void render(const Game&) const = 0;
};