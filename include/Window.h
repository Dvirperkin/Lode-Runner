#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Macros.h"

class Window {
public:
    Window();
    virtual enum ScreenType_t display(sf::RenderWindow &) = 0;
    virtual void draw(sf::RenderWindow &) = 0;
    virtual void Music() = 0;

private:
};