#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Macros.h"

class Textures {
public:

    static Textures & texturesObject();
    const sf::Sprite getSprite(enum Textures_t);

private:
    std::vector<sf::Texture> m_textures;

    Textures();
    Textures(const Textures &) = default;
    Textures& operator=(const Textures &) = default;
};






