#pragma once
#include "MovingObject.h"

class Virus : public MovingObject {

public:
    //--------------------Constructor/Destructor Section--------------------
    Virus(const sf::Vector2f & , enum Textures_t, const sf::Vector2i &);

    //--------------------Get Function Section--------------------
    bool getAddedFromGift() const;
    bool getLocked() const;

    //--------------------Set Function Section--------------------
    void setLock();
    void setAddedFromGift();

    //--------------------Virtual Function Section--------------------
    virtual void handleCollision(Curtain &, const sf::Vector2f &) override;

private:
    bool m_addedFromGift;
    bool m_locked;
};

