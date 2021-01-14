#include "ScoreGift.h"
#include "Player.h"

ScoreGift::ScoreGift(const sf::Vector2f & location, const sf::Texture & texture, const sf::Vector2i & stageSize, Player & player)
 : Gift(location, texture, stageSize){
    m_player = &player;
 }
//=============================================================================
void ScoreGift::activate() {
    isDisposed();
    m_player->addScore(GIFT_SCORE);
}
//=============================================================================
void ScoreGift::handleCollision(GameObject &gameObject, const sf::Vector2f &keyPressed) {

}
//=============================================================================
void ScoreGift::handleCollision(Player &gameObject, const sf::Vector2f &keyPressed) {
    activate();
    gameObject.handleCollision(*this, keyPressed);
}
//=============================================================================
void ScoreGift::handleCollision(StupidEnemy &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void ScoreGift::handleCollision(RandEnemy &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void ScoreGift::handleCollision(SmartEnemy &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void ScoreGift::handleCollision(Coin &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void ScoreGift::handleCollision(Wall &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void ScoreGift::handleCollision(Pole &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void ScoreGift::handleCollision(Ladder &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void ScoreGift::handleCollision(LiveGift &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void ScoreGift::handleCollision(ScoreGift &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void ScoreGift::handleCollision(TimeGift &, const sf::Vector2f &) {

}
//=============================================================================
void ScoreGift::handleCollision(EnemyGift &, const sf::Vector2f &) {

}
//=============================================================================