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

}
//=======================================================================
const sf::Texture &Textures::getPlayerTexture() const
{
    return m_textures[PLAYER];
}
//=======================================================================
const sf::Texture &Textures::getEnemyTexture() const
{
    return m_textures[ENEMY];
}
//=======================================================================
const sf::Texture &Textures::getWallTexture() const
{
    return m_textures[WALL];
}
//=======================================================================
const sf::Texture &Textures::getCoinTexture() const {
    return m_textures[COIN];
}
//=======================================================================
const sf::Texture &Textures::getLadderTexture() const {
    return m_textures[LADDER];
}
//=======================================================================
const sf::Texture &Textures::getPoleTexture() const {
    return m_textures[POLE];
}
//=======================================================================
const sf::Texture &Textures::getGiftTexture() const {
    return m_textures[GIFT];
}
//=======================================================================