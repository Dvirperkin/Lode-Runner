#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"

class MenuButton {
public:
    MenuButton(int);

    void draw(sf::RenderWindow &);
    bool checkPressed(const sf::Vector2f &);
    void setOutlineThickness(int);

private:
    sf::RectangleShape m_frame;
};