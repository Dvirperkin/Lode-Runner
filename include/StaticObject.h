#pragma once
#include "GameObject.h"

class StaticObject : public GameObject {

public:
    StaticObject() = default;
    StaticObject(const sf::Vector2f & , const sf::Texture &, const sf::Vector2i &);

    //---Collision Function Section---
    virtual void handleCollision(Player &gameObject, const sf::Vector2f &keyPressed) override;
    virtual void handleCollision(StupidEnemy &gameObject, const sf::Vector2f &) override;
    virtual void handleCollision(RandEnemy &gameObject, const sf::Vector2f &) override;
    virtual void handleCollision(SmartEnemy &gameObject, const sf::Vector2f &) override;
    virtual void handleCollision(Coin &gameObject, const sf::Vector2f &) override;
    virtual void handleCollision(Wall &gameObject, const sf::Vector2f &) override;
    virtual void handleCollision(Pole &gameObject, const sf::Vector2f &) override;
    virtual void handleCollision(Ladder &gameObject, const sf::Vector2f &) override;
    virtual void handleCollision(LiveGift &gameObject, const sf::Vector2f &) override;
    virtual void handleCollision(ScoreGift &gameObject, const sf::Vector2f &) override;
    virtual void handleCollision(TimeGift &, const sf::Vector2f &) override;
    virtual void handleCollision(EnemyGift &, const sf::Vector2f &) override;

private:
};