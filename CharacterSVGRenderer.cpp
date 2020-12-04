#include "CharacterSVGRenderer.h"
#include <fstream>
#include <string>
#include <iostream>

void CharacterSVGRenderer::render(Game& gm){
    
    std::string svg_output = gm.mapPrinterSVGWithLightRadius();

    std::ofstream out(file_name);
    out << svg_output;
    out.close();
}