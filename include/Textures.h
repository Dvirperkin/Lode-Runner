#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Macros.h"



class Textures {
public:
    Textures();
    const sf::Texture& getPlayerTexture() const;
    const sf::Texture& getEnemyTexture() const;
    const sf::Texture& getWallTexture() const;
    const sf::Texture& getCoinTexture() const;
    const sf::Texture& getLadderTexture() const;
    const sf::Texture& getPoleTexture() const;
    const sf::Texture& getGiftTexture() const;

private:
    std::vector<sf::Texture> m_textures;
};






