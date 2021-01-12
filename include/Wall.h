#pragma once
#include "StaticObject.h"
#include "Player.h"
#include "StupidEnemy.h"
#include "RandEnemy.h"
#include "SmartEnemy.h"
#include "Coin.h"
#include "Pole.h"
#include "Ladder.h"
#include "LiveGift.h"
#include "ScoreGift.h"
#include "TimeGift.h"
#include "EnemyGift.h"

class Wall : public StaticObject {

public:
    Wall() = default;
    Wall(const sf::Vector2f & , const sf::Texture &, const sf::Vector2i &);

    using StaticObject::handleCollision;

    //---Collision Function Section---
    virtual void handleCollision(GameObject &gameObject, const sf::Vector2f &keyPressed) override;
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