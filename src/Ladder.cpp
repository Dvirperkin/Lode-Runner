#include "Ladder.h"

Ladder::Ladder(const sf::Vector2f &location, const sf::Texture &texture, const sf::Vector2i & stageSize)
    : StaticObject(location , texture, stageSize)
{

}
//=============================================================================
void Ladder::handleCollision(Player & player, const sf::Vector2f & keyPressed) {
    player.handleCollision(*this, keyPressed);
}
//=============================================================================
void Ladder::handleCollision(StupidEnemy & stupidEnemy, const sf::Vector2f & keyPressed) {
    stupidEnemy.handleCollision(*this, keyPressed);
}
//=============================================================================
void Ladder::handleCollision(RandEnemy & randEnemy, const sf::Vector2f & keyPressed) {
    randEnemy.handleCollision(*this, keyPressed);
}
//=============================================================================
void Ladder::handleCollision(SmartEnemy & smartEnemy, const sf::Vector2f & keyPressed) {
    smartEnemy.handleCollision(*this, keyPressed);
}
//=============================================================================