#include "Coin.h"

Coin::Coin(const sf::Vector2f &location, const sf::Texture &texture, const sf::Vector2i & stageSize)
    : SpecialObject(location, texture, stageSize)
{
}
//=============================================================================
void Coin::activate() {
    isDisposed();
}
//=============================================================================
void Coin::handleCollision(Player & player, const sf::Vector2f & keyPressed) {
    activate();
    player.handleCollision(*this, keyPressed);
}
//=============================================================================
void Coin::handleCollision(StupidEnemy & stupidEnemy, const sf::Vector2f & keyPressed) {
    stupidEnemy.handleCollision(*this, keyPressed);
}
//=============================================================================
void Coin::handleCollision(RandEnemy & randEnemy, const sf::Vector2f & keyPressed) {
    randEnemy.handleCollision(*this, keyPressed);
}
//=============================================================================
void Coin::handleCollision(SmartEnemy & smartEnemy, const sf::Vector2f & keyPressed) {
    smartEnemy.handleCollision(*this, keyPressed);
}
//=============================================================================