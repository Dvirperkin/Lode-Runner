#pragma once

#include "Gift.h"
#include "StageDetails.h"

class TimeGift : public Gift{
public:
    TimeGift(const sf::Vector2f & , const sf::Vector2i &, StageDetails &);

    virtual void activate() override;

    using SpecialObject::handleCollision;

    //---Collision Function Section---
    virtual void handleCollision(Player &, const sf::Vector2f &) override;

private:
    StageDetails * m_stageDetails;
};
