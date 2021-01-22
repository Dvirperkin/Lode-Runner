#pragma once

#include "Gift.h"
#include "StageDetails.h"
#include "Player.h"

class TimeGift : public Gift{
public:
    //--------------------Constructor/Destructor Section--------------------
    TimeGift(const sf::Vector2f & , const sf::Vector2i &, StageDetails &);

    //--------------------Virtual Function Section--------------------
    virtual void activate() override;

    //---Collision Function Section---
    using SpecialObject::handleCollision;
    virtual void handleCollision(Player &, const sf::Vector2f &) override;

private:
    StageDetails * m_stageDetails;
};