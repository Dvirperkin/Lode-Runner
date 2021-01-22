#include "Ladder.h"

Ladder::Ladder(const sf::Vector2f &location, const sf::Vector2i & stageSize)
    : StaticObject(location , LADDER, stageSize)
{

}
//=============================================================================
void Ladder::handleCollision(Player & player, const sf::Vector2f & keyPressed) {
    player.handleCollision(*this, keyPressed);
}
//=============================================================================
void Ladder::handleCollision(StupidVirus & stupidEnemy, const sf::Vector2f & keyPressed) {
    stupidEnemy.handleCollision(*this, keyPressed);
}
//=============================================================================
void Ladder::handleCollision(RandVirus & randEnemy, const sf::Vector2f & keyPressed) {
    randEnemy.handleCollision(*this, keyPressed);
}
//=============================================================================
void Ladder::handleCollision(SmartVirus & smartEnemy, const sf::Vector2f & keyPressed) {
    smartEnemy.handleCollision(*this, keyPressed);
}
//=============================================================================