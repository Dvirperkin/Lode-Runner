#include "EnemyGift.h"

EnemyGift::EnemyGift(const sf::Vector2f & location, const sf::Texture & texture, const sf::Vector2i & stageSize)
 : Gift(location, texture, stageSize)
{}
//=============================================================================
void EnemyGift::activate() {

}
//=============================================================================
void EnemyGift::handleCollision(GameObject &gameObject, const sf::Vector2f &keyPressed) {

}
//=============================================================================
void EnemyGift::handleCollision(Player &gameObject, const sf::Vector2f &keyPressed) {

}
//=============================================================================
void EnemyGift::handleCollision(StupidEnemy &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void EnemyGift::handleCollision(RandEnemy &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void EnemyGift::handleCollision(SmartEnemy &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void EnemyGift::handleCollision(Coin &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void EnemyGift::handleCollision(Wall &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void EnemyGift::handleCollision(Pole &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void EnemyGift::handleCollision(Ladder &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void EnemyGift::handleCollision(LiveGift &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void EnemyGift::handleCollision(ScoreGift &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void EnemyGift::handleCollision(TimeGift &, const sf::Vector2f &) {

}
//=============================================================================
void EnemyGift::handleCollision(EnemyGift &, const sf::Vector2f &) {

}
//=============================================================================