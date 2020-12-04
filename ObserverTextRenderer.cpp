#include "ObserverTextRenderer.h"

void ObserverTextRenderer::render(Game& gm) const{
    gm.mapPrinter(out_stream);
}