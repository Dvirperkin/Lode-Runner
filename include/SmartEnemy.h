#pragma once
#include "Enemy.h"
#include "Player.h"
#include "StupidEnemy.h"
#include "RandEnemy.h"
#include "Wall.h"
#include "Pole.h"
#include "Ladder.h"
#include "LiveGift.h"
#include "ScoreGift.h"
#include "TimeGift.h"
#include "EnemyGift.h"

class SmartEnemy : public Enemy {
public:

    SmartEnemy(const sf::Vector2f & , const sf::Texture &, const sf::Vector2i &);
    virtual sf::Vector2f move(const float &) override;
    virtual void gravity(const float & ) override;

    using MovingObject::handleCollision;

    //---Collision Function Section---
    virtual void handleCollision(GameObject &, const sf::Vector2f &) override;
    virtual void handleCollision(Player &, const sf::Vector2f &) override;

private:
};