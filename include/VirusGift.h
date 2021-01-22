#pragma once

#include "Gift.h"
#include "Stage.h"
#include "Player.h"

class VirusGift : public Gift{
public:
    //--------------------Constructor/Destructor Section--------------------
    VirusGift(const sf::Vector2f &, const sf::Vector2i &, Stage &);


    //--------------------Virtual Function Section--------------------
    virtual void activate() override;

    //---Collision Function Section---
    using SpecialObject::handleCollision;
    virtual void handleCollision(Player &, const sf::Vector2f &) override;

private:
    Stage * m_stage;
};
