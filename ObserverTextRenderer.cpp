#include "ObserverTextRenderer.h"

void ObserverTextRenderer::render(Game& gm) {
    gm.mapPrinter(out_stream);
}