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
    Wall(const sf::Vector2f &, const sf::Vector2i &);

    using StaticObject::handleCollision;

    virtual void isDisposed();
    void reduceTime(float);
    float getDisposedTime();

    //---Collision Function Section---
    virtual void handleCollision(Player &, const sf::Vector2f &) override;
    virtual void handleCollision(StupidEnemy &, const sf::Vector2f &) override;
    virtual void handleCollision(RandEnemy &, const sf::Vector2f &) override;
    virtual void handleCollision(SmartEnemy &, const sf::Vector2f &) override;

private:
    sf::Time m_disposedTimer;
};