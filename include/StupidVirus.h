#pragma once
#include "Virus.h"
#include "Player.h"
#include "Curtain.h"


class StupidVirus : public Virus {
public:

    //--------------------Constructor/Destructor Section--------------------
    StupidVirus(const sf::Vector2f &, const sf::Vector2i &);


    //--------------------Virtual Function Section--------------------
    virtual sf::Vector2f move(const float &) override;
    virtual void gravity(const float & ) override;

    //---Collision Function Section---
    using MovingObject::handleCollision;
    virtual void handleCollision(GameObject &, const sf::Vector2f &) override;
    virtual void handleCollision(Player &, const sf::Vector2f &) override;
    virtual void handleCollision(Curtain &, const sf::Vector2f &) override;

private:
    bool m_direction;
};
