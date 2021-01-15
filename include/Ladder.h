#pragma once

#include "StaticObject.h"
#include "StaticObject.h"
#include "Player.h"
#include "StupidEnemy.h"
#include "RandEnemy.h"
#include "SmartEnemy.h"
#include "Coin.h"
#include "Wall.h"
#include "Pole.h"
#include "LiveGift.h"
#include "ScoreGift.h"
#include "TimeGift.h"
#include "EnemyGift.h"

class Ladder : public StaticObject {

public:
    Ladder(const sf::Vector2f & , const sf::Texture &, const sf::Vector2i &);

    using StaticObject::handleCollision;

    //---Collision Function Section---
    virtual void handleCollision(Player &, const sf::Vector2f &) override;
    virtual void handleCollision(StupidEnemy &, const sf::Vector2f &) override;
    virtual void handleCollision(RandEnemy &, const sf::Vector2f &) override;
    virtual void handleCollision(SmartEnemy &, const sf::Vector2f &) override;

private:

};