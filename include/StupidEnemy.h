#pragma once
#include "Enemy.h"
#include "Player.h"
#include "RandEnemy.h"
#include "SmartEnemy.h"
#include "Wall.h"
#include "Pole.h"
#include "Ladder.h"
#include "LiveGift.h"
#include "ScoreGift.h"
#include "TimeGift.h"
#include "EnemyGift.h"

class StupidEnemy : public Enemy {
public:

    StupidEnemy(const sf::Vector2f & , const sf::Texture &, const sf::Vector2i &);
    virtual sf::Vector2f move(const float &) override;
    virtual void gravity(const float & ) override;

    using MovingObject::handleCollision;

    //---Collision Function Section---
    virtual void handleCollision(GameObject &gameObject, const sf::Vector2f &keyPressed) override;
    virtual void handleCollision(Player &gameObject, const sf::Vector2f &keyPressed) override;
    virtual void handleCollision(Wall &gameObject, const sf::Vector2f &keyPressed) override;

private:
    bool m_direction;
};
