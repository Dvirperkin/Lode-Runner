#pragma once

#include "StaticObject.h"
#include "Player.h"
#include "StupidVirus.h"
#include "RandVirus.h"
#include "SmartVirus.h"

class Rope : public StaticObject {

public:
    //--------------------Constructor/Destructor Section--------------------
    Rope(const sf::Vector2f &, const sf::Vector2i &);


    //--------------------Virtual Function Section--------------------
    //---Collision Function Section---
    using StaticObject::handleCollision;
    virtual void handleCollision(Player &, const sf::Vector2f &) override;
    virtual void handleCollision(StupidVirus &, const sf::Vector2f &) override;
    virtual void handleCollision(RandVirus &, const sf::Vector2f &) override;
    virtual void handleCollision(SmartVirus &, const sf::Vector2f &) override;

private:
};