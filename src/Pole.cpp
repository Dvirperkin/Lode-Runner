#include "Pole.h"

Pole::Pole(const sf::Vector2f &location, const sf::Vector2i & stageSize)
    : StaticObject(location , POLE, stageSize){

}
//=============================================================================
void Pole::handleCollision(Player & player, const sf::Vector2f & keyPressed) {
    player.handleCollision(*this, keyPressed);
}
//=============================================================================
void Pole::handleCollision(StupidEnemy & stupidEnemy, const sf::Vector2f & keyPressed) {
    stupidEnemy.handleCollision(*this, keyPressed);
}
//=============================================================================
void Pole::handleCollision(RandEnemy & randEnemy, const sf::Vector2f & keyPressed) {
    randEnemy.handleCollision(*this, keyPressed);
}
//=============================================================================
void Pole::handleCollision(SmartEnemy & smartEnemy, const sf::Vector2f & keyPressed) {

}
//=============================================================================