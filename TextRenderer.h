#pragma once
#include "Renderer.h"

class TextRenderer : public Renderer{
    protected:
        std::ostream& out_stream;
        const std::string TOP_LEFT = "\u2554";///<String value that stores a unicode character to print the map correctly
        const std::string TOP_RIGHT = "\u2557";///<String value that stores a unicode character to print the map correctly
        const std::string VERTICAL = "\u2551";///<String value that stores a unicode character to print the map correctly
        const std::string BOTTOM_LEFT = "\u255A";///<String value that stores a unicode character to print the map correctly
        const std::string BOTTOM_RIGHT = "\u255D";///<String value that stores a unicode character to print the map correctly
        const std::string HORIZONTAL = "\u2550\u2550";///<String value that stores a unicode character to print the map correctly
        const std::string FREE_FIELD = "\u2591\u2591";///<String value that stores a unicode character to print the map correctly
        const std::string WALL_FIELD = "\u2588\u2588";///<String value that stores a unicode character to print the map correctly
        const std::string HERO = "\u2523\u252B";///<String value that stores a unicode character to print the map correctly
        const std::string MONSTERONE = "\u004D\u2591";///<String value that stores a unicode character to print the map correctly
        const std::string MONSTERTWO = "\u004D\u004D";///<String value that stores a unicode character to print the map correctly
  
    public:
        TextRenderer() : out_stream(std::cout){}

        void setOutputStream(const std::ostream&);

        virtual void render(const Game&) const = 0;
};