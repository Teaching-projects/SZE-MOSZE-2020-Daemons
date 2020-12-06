#include "TextRenderer.h"

void TextRenderer::setOutputStream(const std::ostream& str){
    out_stream.copyfmt(str);
}
