#include "StaticObject.h"

StaticObject::StaticObject(const sf::Vector2f &location, const sf::Texture &texture, const sf::Vector2i & stageSize)
    : GameObject(location , texture, stageSize)
{

}

void StaticObject::handleCollision(Player &gameObject, const sf::Vector2f &keyPressed) {

}

void StaticObject::handleCollision(StupidEnemy &gameObject, const sf::Vector2f &) {

}

void StaticObject::handleCollision(RandEnemy &gameObject, const sf::Vector2f &) {

}

void StaticObject::handleCollision(SmartEnemy &gameObject, const sf::Vector2f &) {

}

void StaticObject::handleCollision(Coin &gameObject, const sf::Vector2f &) {

}

void StaticObject::handleCollision(Wall &gameObject, const sf::Vector2f &) {

}

void StaticObject::handleCollision(Pole &gameObject, const sf::Vector2f &) {

}

void StaticObject::handleCollision(Ladder &gameObject, const sf::Vector2f &) {

}

void StaticObject::handleCollision(LiveGift &gameObject, const sf::Vector2f &) {

}

void StaticObject::handleCollision(ScoreGift &gameObject, const sf::Vector2f &) {

}

void StaticObject::handleCollision(TimeGift &, const sf::Vector2f &) {

}

void StaticObject::handleCollision(EnemyGift &, const sf::Vector2f &) {

}
