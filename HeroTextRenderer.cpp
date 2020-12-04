#include "HeroTextRenderer.h"



void HeroTextRenderer::render(Game& gm) {
    gm.mapPrinterWithLightRadius(out_stream);
}