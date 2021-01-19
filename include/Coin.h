#pragma once

#include "StageDetails.h"
#include "SpecialObject.h"
#include "Player.h"
#include "StupidEnemy.h"
#include "RandEnemy.h"
#include "SmartEnemy.h"
#include "Wall.h"
#include "Pole.h"
#include "Ladder.h"
#include "LiveGift.h"
#include "ScoreGift.h"
#include "TimeGift.h"
#include "EnemyGift.h"

class Coin : public SpecialObject {

public:
    Coin(const sf::Vector2f &, const sf::Vector2i &, StageDetails &);
    virtual void activate() override;

    using SpecialObject::handleCollision;

    //---Collision Function Section---
    virtual void handleCollision(Player &, const sf::Vector2f &) override;
    virtual void handleCollision(StupidEnemy &, const sf::Vector2f &) override;
    virtual void handleCollision(RandEnemy &, const sf::Vector2f &) override;
    virtual void handleCollision(SmartEnemy &, const sf::Vector2f &) override;
private:
    StageDetails * m_stageDetails;
};