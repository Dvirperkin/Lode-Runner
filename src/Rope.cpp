#include "Rope.h"

Rope::Rope(const sf::Vector2f &location, const sf::Vector2i & stageSize)
    : StaticObject(location , POLE, stageSize){

}
//=============================================================================
void Rope::handleCollision(Player & player, const sf::Vector2f & keyPressed) {
    player.handleCollision(*this, keyPressed);
}
//=============================================================================
void Rope::handleCollision(StupidVirus & stupidEnemy, const sf::Vector2f & keyPressed) {
    stupidEnemy.handleCollision(*this, keyPressed);
}
//=============================================================================
void Rope::handleCollision(RandVirus & randEnemy, const sf::Vector2f & keyPressed) {
    randEnemy.handleCollision(*this, keyPressed);
}
//=============================================================================
void Rope::handleCollision(SmartVirus & smartEnemy, const sf::Vector2f & keyPressed) {

}
//=============================================================================