#include "Ladder.h"

Ladder::Ladder(const sf::Vector2f &location, const sf::Texture &texture, const sf::Vector2i & stageSize)
    : StaticObject(location , texture, stageSize)
{

}
//=============================================================================
void Ladder::handleCollision(GameObject &gameObject, const sf::Vector2f &keyPressed) {

}
//=============================================================================
void Ladder::handleCollision(Player &gameObject, const sf::Vector2f &keyPressed) {
    gameObject.handleCollision(*this, keyPressed);
}
//=============================================================================
void Ladder::handleCollision(StupidEnemy &gameObject, const sf::Vector2f & keyPressed) {
    //gameObject.handleCollision(*this, keyPressed);
}
//=============================================================================
void Ladder::handleCollision(RandEnemy &gameObject, const sf::Vector2f & keyPressed) {
    gameObject.handleCollision(*this, keyPressed);
}
//=============================================================================
void Ladder::handleCollision(SmartEnemy &gameObject, const sf::Vector2f & keyPressed) {
    //gameObject.handleCollision(*this, keyPressed);
}
//=============================================================================
void Ladder::handleCollision(Coin &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void Ladder::handleCollision(Wall &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void Ladder::handleCollision(Pole &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void Ladder::handleCollision(Ladder &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void Ladder::handleCollision(LiveGift &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void Ladder::handleCollision(ScoreGift &gameObject, const sf::Vector2f &) {

}
//=============================================================================
void Ladder::handleCollision(TimeGift &, const sf::Vector2f &) {

}
//=============================================================================
void Ladder::handleCollision(EnemyGift &, const sf::Vector2f &) {

}
//=============================================================================