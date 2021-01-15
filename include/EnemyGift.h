#pragma once

#include "Gift.h"

class Stage;

class EnemyGift : public Gift{
public:
    EnemyGift(const sf::Vector2f & , const sf::Texture &, const sf::Vector2i &, Stage &);

    virtual void activate() override;

    using SpecialObject::handleCollision;

    //---Collision Function Section---
    virtual void handleCollision(Player &, const sf::Vector2f &) override;

private:
    Stage * m_stage;
};
