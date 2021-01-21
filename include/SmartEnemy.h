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
    SmartEnemy(const sf::Vector2f &, Stage &);
    virtual sf::Vector2f move(const float &) override;
    virtual void gravity(const float & ) override;

    using MovingObject::handleCollision;

    //---Collision Function Section---
    virtual void handleCollision(GameObject &, const sf::Vector2f &) override;
    virtual void handleCollision(Player &, const sf::Vector2f &) override;

private:
    float m_timeLimit;
    bool m_firstRun;
    Stage * m_stage;
    float m_time;
    std::pair<sf::Vector2i , sf::Vector2i > m_lastPair;
    std::pair<sf::Vector2i , sf::Vector2i > m_currPair;
};