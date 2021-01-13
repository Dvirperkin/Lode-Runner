#pragma once
#include "MovingObject.h"
#include "StupidEnemy.h"
#include "RandEnemy.h"
#include "SmartEnemy.h"
#include "Coin.h"
#include "Pole.h"
#include "Ladder.h"
#include "LiveGift.h"
#include "ScoreGift.h"
#include "TimeGift.h"
#include "EnemyGift.h"



class Player : public MovingObject {
public:

    Player();
    Player(const sf::Vector2f & , const sf::Texture &, const sf::Vector2i &);

    virtual sf::Vector2f move(const float &) override;

    int getLive() const;
    int getScore() const;

    void levelUP();
    void gravity(const float &);

    using MovingObject::handleCollision;

    //---Collision Function Section---
    virtual void handleCollision(GameObject &, const sf::Vector2f &) override;
    virtual void handleCollision(StupidEnemy &, const sf::Vector2f &) override;
    virtual void handleCollision(RandEnemy &, const sf::Vector2f &) override;
    virtual void handleCollision(SmartEnemy &, const sf::Vector2f &) override;
    virtual void handleCollision(Coin &, const sf::Vector2f &) override;
    virtual void handleCollision(LiveGift &, const sf::Vector2f &) override;
    virtual void handleCollision(ScoreGift &, const sf::Vector2f &) override;
    virtual void handleCollision(TimeGift &, const sf::Vector2f &) override;
    virtual void handleCollision(EnemyGift &, const sf::Vector2f &) override;

private:
    int m_lives;
    int m_level;
    int m_score;
};