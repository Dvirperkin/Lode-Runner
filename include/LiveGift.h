#pragma once

#include "Gift.h"

class LiveGift : public Gift {
public:
    LiveGift(const sf::Vector2f & , const sf::Texture &, const sf::Vector2i &, Player &);

    virtual void activate() override;

    using SpecialObject::handleCollision;

    //---Collision Function Section---
    virtual void handleCollision(Player &, const sf::Vector2f &) override;

private:
    Player * m_player;
};