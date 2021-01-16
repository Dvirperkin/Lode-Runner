#pragma once
#include "GameObject.h"
#include "Macros.h"

class MovingObject : public GameObject {

public:
    MovingObject() = default;
    MovingObject(const sf::Vector2f & , const sf::Texture &, const sf::Vector2i &);
    virtual sf::Vector2f move(const float &) = 0;
    virtual void gravity(const float & ) = 0;

    bool getOnLadder() const;
    bool getOnPole() const;
    bool getInTheAir() const;

    void setOnLadder(bool);
    void setOnPole(bool);
    void setInTheAir(bool);

    //---Collision Function Section---
    virtual void handleCollision(GameObject &, const sf::Vector2f &) override;
    virtual void handleCollision(Player &, const sf::Vector2f &) override;
    virtual void handleCollision(StupidEnemy &, const sf::Vector2f &) override;
    virtual void handleCollision(RandEnemy &, const sf::Vector2f &) override;
    virtual void handleCollision(SmartEnemy &, const sf::Vector2f &) override;
    virtual void handleCollision(Coin &, const sf::Vector2f &) override;
    virtual void handleCollision(Wall &, const sf::Vector2f &) override;
    virtual void handleCollision(Pole &, const sf::Vector2f &) override;
    virtual void handleCollision(Ladder &, const sf::Vector2f &) override;
    virtual void handleCollision(LiveGift &, const sf::Vector2f &) override;
    virtual void handleCollision(ScoreGift &, const sf::Vector2f &) override;
    virtual void handleCollision(TimeGift &, const sf::Vector2f &) override;
    virtual void handleCollision(EnemyGift &, const sf::Vector2f &) override;

private:
    bool m_onLadder;
    bool m_onPole;
    bool m_inTheAir;
};