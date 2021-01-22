#pragma once

#include "StageDetails.h"
#include "SpecialObject.h"
#include "Player.h"
#include "StupidVirus.h"
#include "RandVirus.h"
#include "SmartVirus.h"

class Vaccine : public SpecialObject {

public:
    //--------------------Constructor/Destructor Section--------------------
    Vaccine(const sf::Vector2f &, const sf::Vector2i &, StageDetails &);

    //--------------------Virtual Function Section--------------------
    virtual void activate() override;
    using SpecialObject::handleCollision;
    //---Collision Function Section---
    virtual void handleCollision(Player &, const sf::Vector2f &) override;
    virtual void handleCollision(StupidVirus &, const sf::Vector2f &) override;
    virtual void handleCollision(RandVirus &, const sf::Vector2f &) override;
    virtual void handleCollision(SmartVirus &, const sf::Vector2f &) override;

private:
    StageDetails * m_stageDetails;
};