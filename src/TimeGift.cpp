#include "TimeGift.h"
#include "Player.h"
TimeGift::TimeGift(const sf::Vector2f & location, const sf::Texture & texture, const sf::Vector2i & stageSize, StageDetails & stageDetails)
 : Gift(location, texture, stageSize){
    m_stageDetails = &stageDetails;
 }
//=============================================================================
void TimeGift::activate() {
    m_stageDetails->addTime();
}
//=============================================================================
void TimeGift::handleCollision(GameObject &gameObject, const sf::Vector2f &keyPressed) {

}
//=============================================================================
void TimeGift::handleCollision(Player &gameObject, const sf::Vector2f &keyPressed) {
    activate();
    isDisposed();
    gameObject.handleCollision(*this, keyPressed);
}
//=============================================================================
void TimeGift::handleCollision(StupidEnemy &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void TimeGift::handleCollision(RandEnemy &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void TimeGift::handleCollision(SmartEnemy &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void TimeGift::handleCollision(Coin &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void TimeGift::handleCollision(Wall &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void TimeGift::handleCollision(Pole &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void TimeGift::handleCollision(Ladder &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void TimeGift::handleCollision(LiveGift &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void TimeGift::handleCollision(ScoreGift &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void TimeGift::handleCollision(TimeGift &, const sf::Vector2f &) {

}
//=============================================================================
void TimeGift::handleCollision(EnemyGift &, const sf::Vector2f &) {

}
//=============================================================================