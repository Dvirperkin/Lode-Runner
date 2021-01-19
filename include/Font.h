#pragma once
#include <memory>
#include <SFML/Graphics.hpp>

class Font {
public:
    static Font& FontObject();
    const sf::Font & getFont () const;

private:
    sf::Font m_font;

    Font();
    Font(const Font &) = default;
    Font& operator=(const Font &) = default;
};