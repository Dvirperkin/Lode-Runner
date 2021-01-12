#pragma once
#include <memory>
#include <SFML/Graphics.hpp>

class Font {
public:
    Font();
    const sf::Font & getFont () const;

private:
    sf::Font m_font;

};