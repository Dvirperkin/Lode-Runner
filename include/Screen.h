#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Macros.h"
#include "Textures.h"
#include "Sound.h"
#include "Font.h"

class Screen {
public:
    //--------------------Constructor/Destructor Section--------------------
    Screen();

    //--------------------Virtual Function Section--------------------
    virtual enum ScreenType_t display(sf::RenderWindow &) = 0;
    virtual void draw(sf::RenderWindow &) = 0;


private:
};