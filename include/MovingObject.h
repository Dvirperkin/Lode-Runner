#pragma once
#include "GameObject.h"

class MovingObject : public GameObject {

public:
    //--------------------Constructor/Destructor Section--------------------
    MovingObject() = default;
    MovingObject(const sf::Vector2f & , enum Textures_t, const sf::Vector2i &);

    //--------------------Get Function Section--------------------
    bool getOnLadder() const;
    bool getOnPole() const;
    bool getInTheAir() const;

    //--------------------Set Function Section--------------------
    void setOnLadder(bool);
    void setOnPole(bool);
    void setInTheAir(bool);

    //--------------------Virtual Function Section--------------------
    virtual sf::Vector2f move(const float &) = 0;
    virtual void gravity(const float & ) = 0;

    //---Collision Function Section---
    virtual void handleCollision(GameObject &, const sf::Vector2f &) override;
    virtual void handleCollision(Player &, const sf::Vector2f &) override;
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
    bool m_onLadder;
    bool m_onPole;
    bool m_inTheAir;
};