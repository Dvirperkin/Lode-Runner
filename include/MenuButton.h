#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Macros.h"
#include "Font.h"

class MenuButton {
public:
    //--------------------Constructor/Destructor Section--------------------
    MenuButton(int, std::string);

    //--------------------Action Function Section--------------------
    void draw(sf::RenderWindow &);
    bool checkPressed(const sf::Vector2f &);

    //--------------------Get Function Section--------------------
    sf::Vector2f getPosition() const;
    sf::FloatRect getGlobalBound() const;

    //--------------------Set Function Section--------------------
    void setOutlineThickness(int);

private:
    sf::RectangleShape m_frame;
    sf::Text m_buttonText;
};