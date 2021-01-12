#include "Wall.h"

Wall::Wall(const sf::Vector2f &location, const sf::Texture &texture, const sf::Vector2i & stageSize)
    : StaticObject(location , texture, stageSize)
{

}
//=============================================================================
void Wall::handleCollision(GameObject &gameObject, const sf::Vector2f &keyPressed) {
    /*ignore*/
}
//=============================================================================
void Wall::handleCollision(Player &gameObject, const sf::Vector2f &keyPressed) {
    gameObject.handleCollision(*this, keyPressed);
}
//=============================================================================
void Wall::handleCollision(StupidEnemy &gameObject, const sf::Vector2f & keyPressed) {
    gameObject.handleCollision(*this, keyPressed);
}
//=============================================================================
void Wall::handleCollision(RandEnemy &gameObject, const sf::Vector2f & keyPressed) {
    gameObject.handleCollision(*this, keyPressed);
}
//=============================================================================
void Wall::handleCollision(SmartEnemy &gameObject, const sf::Vector2f &) {
    /*ignore*/
}
//=============================================================================
void Wall::handleCollision(Coin &gameObject, const sf::Vector2f &) {
    /*ignore*/
}
//=============================================================================
void Wall::handleCollision(Wall &gameObject, const sf::Vector2f &) {
    /*ignore*/
}
//=============================================================================
void Wall::handleCollision(Pole &gameObject, const sf::Vector2f &) {
    /*ignore*/
}
//=============================================================================
void Wall::handleCollision(Ladder &gameObject, const sf::Vector2f &) {
    /*ignore*/
}
//=============================================================================
void Wall::handleCollision(LiveGift &gameObject, const sf::Vector2f &) {
    /*ignore*/
}
//=============================================================================
void Wall::handleCollision(ScoreGift &gameObject, const sf::Vector2f &) {
    /*ignore*/
}
//=============================================================================
void Wall::handleCollision(TimeGift &, const sf::Vector2f &) {
    /*ignore*/
}
//=============================================================================
void Wall::handleCollision(EnemyGift &, const sf::Vector2f &) {
    /*ignore*/
}
//=============================================================================