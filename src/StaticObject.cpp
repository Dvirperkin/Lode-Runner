#include "StaticObject.h"

StaticObject::StaticObject(const sf::Vector2f &location, const sf::Texture &texture, const sf::Vector2i & stageSize)
    : GameObject(location , texture, stageSize)
{
}
//=============================================================================
void StaticObject::handleCollision(GameObject & gameObject, const sf::Vector2f & keyPressed) {
    /*ignore*/
}
//=============================================================================
void StaticObject::handleCollision(Player & player, const sf::Vector2f &keyPressed) {
    /*ignore*/
}
//=============================================================================
void StaticObject::handleCollision(StupidEnemy & stupidEnemy, const sf::Vector2f &keyPressed) {
    /*ignore*/
}
//=============================================================================
void StaticObject::handleCollision(RandEnemy & randEnemy, const sf::Vector2f & keyPressed) {
    /*ignore*/
}
//=============================================================================
void StaticObject::handleCollision(SmartEnemy & smartEnemy, const sf::Vector2f & keyPressed) {
    /*ignore*/
}
//=============================================================================
void StaticObject::handleCollision(Coin & coin, const sf::Vector2f & keyPressed) {
    /*ignore*/
}
//=============================================================================
void StaticObject::handleCollision(Wall & wall, const sf::Vector2f & keyPressed) {
    /*ignore*/
}
//=============================================================================
void StaticObject::handleCollision(Pole & pole, const sf::Vector2f & keyPressed) {
    /*ignore*/
}
//=============================================================================
void StaticObject::handleCollision(Ladder & ladder, const sf::Vector2f & keyPressed) {
    /*ignore*/
}
//=============================================================================
void StaticObject::handleCollision(LiveGift & liveGift, const sf::Vector2f & keyPressed) {
    /*ignore*/
}
//=============================================================================
void StaticObject::handleCollision(ScoreGift & scoreGift, const sf::Vector2f & keyPressed) {
    /*ignore*/
}
//=============================================================================
void StaticObject::handleCollision(TimeGift & timeGift, const sf::Vector2f & keyPressed) {
    /*ignore*/
}
//=============================================================================
void StaticObject::handleCollision(EnemyGift & enemyGift, const sf::Vector2f & keyPressed) {
    /*ignore*/
}
//=============================================================================