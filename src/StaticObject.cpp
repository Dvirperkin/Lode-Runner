#include "StaticObject.h"

StaticObject::StaticObject(const sf::Vector2f &location, enum Textures_t staticObject, const sf::Vector2i & stageSize)
    : GameObject(location , staticObject, stageSize)
{
}
//=============================================================================
void StaticObject::handleCollision(GameObject & gameObject, const sf::Vector2f & keyPressed) {
    /*ignore*/
}
//=============================================================================
void StaticObject::handleCollision(StupidVirus & stupidEnemy, const sf::Vector2f &keyPressed) {
    /*ignore*/
}
//=============================================================================
void StaticObject::handleCollision(RandVirus & randEnemy, const sf::Vector2f & keyPressed) {
    /*ignore*/
}
//=============================================================================
void StaticObject::handleCollision(SmartVirus & smartEnemy, const sf::Vector2f & keyPressed) {
    /*ignore*/
}
//=============================================================================
void StaticObject::handleCollision(Vaccine & coin, const sf::Vector2f & keyPressed) {
    /*ignore*/
}
//=============================================================================
void StaticObject::handleCollision(Curtain & wall, const sf::Vector2f & keyPressed) {
    /*ignore*/
}
//=============================================================================
void StaticObject::handleCollision(Rope & pole, const sf::Vector2f & keyPressed) {
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
void StaticObject::handleCollision(VirusGift & enemyGift, const sf::Vector2f & keyPressed) {
    /*ignore*/
}
//=============================================================================