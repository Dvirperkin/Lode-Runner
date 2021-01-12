#include "Pole.h"

Pole::Pole(const sf::Vector2f &location, const sf::Texture &texture, const sf::Vector2i & stageSize)
    : StaticObject(location , texture, stageSize)
{

}
//=============================================================================
void Pole::handleCollision(GameObject &gameObject, const sf::Vector2f &keyPressed) {

}
//=============================================================================
void Pole::handleCollision(Player &gameObject, const sf::Vector2f &keyPressed) {
    gameObject.handleCollision(*this, keyPressed);
}
//=============================================================================
void Pole::handleCollision(StupidEnemy &gameObject, const sf::Vector2f &keyPressed) {
    gameObject.handleCollision(*this, keyPressed);
}
//=============================================================================
void Pole::handleCollision(RandEnemy &gameObject, const sf::Vector2f & keyPressed) {
    gameObject.handleCollision(*this, keyPressed);
}
//=============================================================================
void Pole::handleCollision(SmartEnemy &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void Pole::handleCollision(Coin &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void Pole::handleCollision(Wall &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void Pole::handleCollision(Pole &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void Pole::handleCollision(Ladder &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void Pole::handleCollision(LiveGift &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void Pole::handleCollision(ScoreGift &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void Pole::handleCollision(TimeGift &, const sf::Vector2f &) {

}
//=============================================================================
void Pole::handleCollision(EnemyGift &, const sf::Vector2f &) {

}
//=============================================================================