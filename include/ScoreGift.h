#pragma once

#include "Gift.h"
#include "Player.h"

class ScoreGift : public Gift {
public:
    //--------------------Constructor/Destructor Section--------------------
    ScoreGift(const sf::Vector2f &, const sf::Vector2i &, Player &);

    //--------------------Virtual Function Section--------------------
    virtual void activate() override;

    //---Collision Function Section---
    using SpecialObject::handleCollision;
    virtual void handleCollision(Player &, const sf::Vector2f &) override;

private:
    Player * m_player;
};