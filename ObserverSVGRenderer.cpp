#include "ObserverSVGRenderer.h"
#include <fstream>
#include <string>
#include <iostream>

void ObserverSVGRenderer::render(Game& gm){
    
    std::string svg_output = gm.mapPrinterSVG();

    std::ofstream out(file_name);
    out << svg_output;
    out.close();
}