#pragma once
#include "Virus.h"
#include "Player.h"

class SmartVirus : public Virus {
public:
    //--------------------Constructor/Destructor Section--------------------
    SmartVirus(const sf::Vector2f &, Stage &);

    //--------------------Virtual Function Section--------------------
    virtual sf::Vector2f move(const float &) override;
    virtual void gravity(const float & ) override;

    //---Collision Function Section---
    using MovingObject::handleCollision;
    virtual void handleCollision(GameObject &, const sf::Vector2f &) override;
    virtual void handleCollision(Player &, const sf::Vector2f &) override;

private:
    float m_timeLimit;
    bool m_firstRun;
    Stage * m_stage;
    float m_time;
    std::pair<sf::Vector2i , sf::Vector2i > m_lastPair;
    std::pair<sf::Vector2i , sf::Vector2i > m_currPair;
};