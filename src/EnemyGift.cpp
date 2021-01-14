#include "EnemyGift.h"
#include "Stage.h"
#include "Player.h"

EnemyGift::EnemyGift(const sf::Vector2f & location, const sf::Texture & texture, const sf::Vector2i & stageSize , Stage & stage)
 : Gift(location, texture, stageSize){

    m_stage = &stage;
}
//=============================================================================
void EnemyGift::activate() {
    m_stage->addEnemy();
}
//=============================================================================
void EnemyGift::handleCollision(GameObject &gameObject, const sf::Vector2f &keyPressed) {
}
//=============================================================================
void EnemyGift::handleCollision(Player &gameObject, const sf::Vector2f &keyPressed) {
    activate();
    isDisposed();
    gameObject.handleCollision(*this, keyPressed);
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