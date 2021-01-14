#include "Coin.h"

Coin::Coin(const sf::Vector2f &location, const sf::Texture &texture, const sf::Vector2i & stageSize)
    : SpecialObject(location, texture, stageSize)
{
}
//=============================================================================
void Coin::activate() {
    isDisposed();
}
//=============================================================================
void Coin::handleCollision(GameObject &gameObject, const sf::Vector2f &keyPressed) {
}
//=============================================================================
void Coin::handleCollision(Player &gameObject, const sf::Vector2f &keyPressed) {
    activate();
    gameObject.handleCollision(*this, keyPressed);
}
//=============================================================================
void Coin::handleCollision(StupidEnemy &gameObject, const sf::Vector2f & keyPressed) {
    gameObject.handleCollision(*this, keyPressed);
}
//=============================================================================
void Coin::handleCollision(RandEnemy &gameObject, const sf::Vector2f & keyPressed) {
    gameObject.handleCollision(*this, keyPressed);
}
//=============================================================================
void Coin::handleCollision(SmartEnemy &gameObject, const sf::Vector2f & keyPressed) {
    gameObject.handleCollision(*this, keyPressed);
}
//=============================================================================
void Coin::handleCollision(Coin &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void Coin::handleCollision(Wall &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void Coin::handleCollision(Pole &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void Coin::handleCollision(Ladder &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void Coin::handleCollision(LiveGift &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void Coin::handleCollision(ScoreGift &gameObject, const sf::Vector2f &) {
}
//=============================================================================
void Coin::handleCollision(TimeGift &, const sf::Vector2f &) {

}
//=============================================================================
void Coin::handleCollision(EnemyGift &, const sf::Vector2f &) {

}
//=============================================================================