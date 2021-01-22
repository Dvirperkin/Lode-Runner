#pragma once
#include "GameObject.h"

class StaticObject : public GameObject {

public:
    //--------------------Constructor/Destructor Section--------------------
    StaticObject(const sf::Vector2f & , enum Textures_t, const sf::Vector2i &);

    //--------------------Virtual Function Section--------------------
    //---Collision Function Section---
    virtual void handleCollision(GameObject &, const sf::Vector2f &) override;
    virtual void handleCollision(StupidVirus &, const sf::Vector2f &) override;
    virtual void handleCollision(RandVirus &, const sf::Vector2f &) override;
    virtual void handleCollision(SmartVirus &, const sf::Vector2f &) override;
    virtual void handleCollision(Vaccine &, const sf::Vector2f &) override;
    virtual void handleCollision(Curtain &, const sf::Vector2f &) override;
    virtual void handleCollision(Rope &, const sf::Vector2f &) override;
    virtual void handleCollision(Ladder &, const sf::Vector2f &) override;
    virtual void handleCollision(LiveGift &, const sf::Vector2f &) override;
    virtual void handleCollision(ScoreGift &, const sf::Vector2f &) override;
    virtual void handleCollision(TimeGift &, const sf::Vector2f &) override;
    virtual void handleCollision(VirusGift &, const sf::Vector2f &) override;

private:
};