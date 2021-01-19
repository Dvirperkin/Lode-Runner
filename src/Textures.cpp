#include "Textures.h"

Textures::Textures()
{
    m_textures.resize(NUM_OF_TEXTURES);

    m_textures[PLAYER].loadFromFile("Player.png");
    m_textures[ENEMY].loadFromFile("Enemy.png");
    m_textures[WALL].loadFromFile("Wall.png");
    m_textures[COIN].loadFromFile("Coin.png");
    m_textures[LADDER].loadFromFile("Ladder.png");
    m_textures[POLE].loadFromFile("Pole.png");
    m_textures[GIFT].loadFromFile("Gift.png");
    m_textures[STAGE_DETAILS].loadFromFile("StageDetails.jpg");

}
//=======================================================================
Textures & Textures::texturesObject(){
    static Textures texturesObject;

    return texturesObject;
}
//=======================================================================
const sf::Sprite Textures::getSprite(enum Textures_t image) {
    return sf::Sprite(m_textures[image]);
}
//=======================================================================