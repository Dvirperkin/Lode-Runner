#include "LiveGift.h"

LiveGift::LiveGift(const sf::Vector2f & location, const sf::Texture & texture, const sf::Vector2i & stageSize)
 : Gift(location, texture, stageSize){}

void LiveGift::activate() {

}
//=============================================================================
void LiveGift::handleCollision(GameObject &gameObject, const sf::Vector2f &keyPressed) {

}
//=============================================================================
void LiveGift::handleCollision(Player &gameObject, const sf::Vector2f &keyPressed) {

}
//=============================================================================
void LiveGift::handleCollision(StupidEnemy &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void LiveGift::handleCollision(RandEnemy &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void LiveGift::handleCollision(SmartEnemy &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void LiveGift::handleCollision(Coin &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void LiveGift::handleCollision(Wall &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void LiveGift::handleCollision(Pole &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void LiveGift::handleCollision(Ladder &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void LiveGift::handleCollision(LiveGift &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void LiveGift::handleCollision(ScoreGift &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void LiveGift::handleCollision(TimeGift &, const sf::Vector2f &) {

}
//=============================================================================
void LiveGift::handleCollision(EnemyGift &, const sf::Vector2f &) {

}
//=============================================================================