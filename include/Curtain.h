#pragma once

#include "StaticObject.h"
#include "Player.h"
#include "StupidVirus.h"
#include "RandVirus.h"
#include "SmartVirus.h"

class Curtain : public StaticObject {

public:
    //--------------------Constructor/Destructor Section--------------------
    Curtain(const sf::Vector2f &, const sf::Vector2i &);

    //--------------------Action Function Section--------------------
    void reduceTime(float);

    //--------------------Get Function Section--------------------
    float getDisposedTime();

    //--------------------Virtual Function Section--------------------
    virtual void isDisposed();

    //---Collision Function Section---
    using StaticObject::handleCollision;
    virtual void handleCollision(Player &, const sf::Vector2f &) override;
    virtual void handleCollision(StupidVirus &, const sf::Vector2f &) override;
    virtual void handleCollision(RandVirus &, const sf::Vector2f &) override;
    virtual void handleCollision(SmartVirus &, const sf::Vector2f &) override;

private:
    sf::Time m_disposedTimer;
};