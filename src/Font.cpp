#include "Font.h"

Font::Font()
{
    if(!m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf"))
        exit(EXIT_FAILURE);
}
//=============================================================================
Font & Font::FontObject() {
    static Font fontObject;
    return fontObject;
}
//=============================================================================
const sf::Font & Font::getFont() const {
    return m_font;
}
//=============================================================================