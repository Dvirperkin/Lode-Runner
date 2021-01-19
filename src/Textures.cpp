#include "Textures.h"

Textures::Textures()
{
    m_textures.resize(NUM_OF_TEXTURES);

    m_textures[PLAYER].loadFromFile("Player.png");
    m_textures[STUPID_ENEMY_TEXT].loadFromFile("StupidEnemy.png");
    m_textures[RAND_ENEMY_TEXT].loadFromFile("RandEnemy.png");
    m_textures[SMART_ENEMY_TEXT].loadFromFile("SmartEnemy.png");
    m_textures[WALL].loadFromFile("Wall.png");
    m_textures[COIN].loadFromFile("Coin.png");
    m_textures[LADDER].loadFromFile("Ladder.png");
    m_textures[POLE].loadFromFile("Pole.png");
    m_textures[GIFT].loadFromFile("Gift.png");
    m_textures[STAGE_DETAILS].loadFromFile("StageDetails.jpg");
    m_textures[STAGE_BACKGROUND].loadFromFile("StageBackGround.png");
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