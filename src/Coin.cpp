#include "Coin.h"
#include "StageDetails.h"

Coin::Coin(const sf::Vector2f &location, const sf::Vector2i & stageSize, StageDetails & stageDetails)
    : SpecialObject(location, COIN, stageSize)
{
    m_stageDetails = &stageDetails;
}
//=============================================================================
void Coin::activate() {
    isDisposed();
    m_stageDetails->decCoin();
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