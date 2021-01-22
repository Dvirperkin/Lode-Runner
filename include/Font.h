#pragma once
#include <memory>
#include <SFML/Graphics.hpp>

class Font {
public:
    //--------------------Constructor/Destructor Section--------------------
    static Font& FontObject();

    //--------------------Get Function Section--------------------
    const sf::Font & getFont () const;

private:
    sf::Font m_font;

    //--------------------Constructor/Destructor Section--------------------
    Font();
    Font(const Font &) = default;
    Font& operator=(const Font &) = default;
};