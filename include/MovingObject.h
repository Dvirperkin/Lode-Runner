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
    virtual void handleCollision(GameObject &gameObject, const sf::Vector2f &keyPressed) override;
    virtual void handleCollision(Player &gameObject, const sf::Vector2f &keyPressed) override;
    virtual void handleCollision(StupidEnemy &gameObject, const sf::Vector2f &) override;
    virtual void handleCollision(RandEnemy &gameObject, const sf::Vector2f &) override;
    virtual void handleCollision(SmartEnemy &gameObject, const sf::Vector2f &) override;
    virtual void handleCollision(Coin &gameObject, const sf::Vector2f &) override;
    virtual void handleCollision(Wall &gameObject, const sf::Vector2f &) override;
    virtual void handleCollision(Pole &gameObject, const sf::Vector2f &) override;
    virtual void handleCollision(Ladder &gameObject, const sf::Vector2f &) override;
    virtual void handleCollision(LiveGift &gameObject, const sf::Vector2f &) override;
    virtual void handleCollision(ScoreGift &gameObject, const sf::Vector2f &) override;
    virtual void handleCollision(TimeGift &, const sf::Vector2f &) override;
    virtual void handleCollision(EnemyGift &, const sf::Vector2f &) override;

private:
    bool m_onLadder;
    bool m_onPole;
    bool m_inTheAir;
};