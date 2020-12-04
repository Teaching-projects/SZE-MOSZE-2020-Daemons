#include "HeroTextRenderer.h"



void HeroTextRenderer::render(Game& gm) const {
    gm.mapPrinterWithLightRadius(out_stream);
}