#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Macros.h"

class Textures {
public:

    static Textures & texturesObject();

    //--------------------Get Function Section--------------------
    const sf::Sprite getSprite(enum Textures_t);

private:
    std::vector<sf::Texture> m_textures;

    //--------------------Constructor/Destructor Section--------------------
    Textures();
    Textures(const Textures &) = default;
    Textures& operator=(const Textures &) = default;
};






