#pragma once
#include "MovingObject.h"

class Enemy : public MovingObject {

public:
    Enemy(const sf::Vector2f & , enum Textures_t, const sf::Vector2i &);

    void setLock();
    void setAddedFromGift();
    bool getAddedFromGift() const;
    bool getLocked() const;
    virtual void handleCollision(Wall &, const sf::Vector2f &) override;

private:
    bool m_addedFromGift;
    bool m_locked;
};

