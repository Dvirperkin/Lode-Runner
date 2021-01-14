#pragma once

#include "Gift.h"
#include "StageDetails.h"

class TimeGift : public Gift{
public:
    TimeGift(const sf::Vector2f & , const sf::Texture &, const sf::Vector2i &, StageDetails &);

    virtual void activate() override;

    using SpecialObject::handleCollision;

    //---Collision Function Section---
    virtual void handleCollision(GameObject &, const sf::Vector2f &) override;
    virtual void handleCollision(Player &, const sf::Vector2f &) override;
    virtual void handleCollision(StupidEnemy &, const sf::Vector2f &) override;
    virtual void handleCollision(RandEnemy &, const sf::Vector2f &) override;
    virtual void handleCollision(SmartEnemy &, const sf::Vector2f &) override;
    virtual void handleCollision(Coin &, const sf::Vector2f &) override;
    virtual void handleCollision(Wall &, const sf::Vector2f &) override;
    virtual void handleCollision(Pole &, const sf::Vector2f &) override;
    virtual void handleCollision(Ladder &, const sf::Vector2f &) override;
    virtual void handleCollision(LiveGift &, const sf::Vector2f &) override;
    virtual void handleCollision(ScoreGift &, const sf::Vector2f &) override;
    virtual void handleCollision(TimeGift &, const sf::Vector2f &) override;
    virtual void handleCollision(EnemyGift &, const sf::Vector2f &) override;

private:
    StageDetails * m_stageDetails;
};
