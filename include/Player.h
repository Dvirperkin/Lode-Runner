#pragma once

#include "MovingObject.h"

class Stage;

class Player : public MovingObject {
public:
    //--------------------Constructor/Destructor Section--------------------
    Player();
    Player(const sf::Vector2f &, const sf::Vector2i &);

    //--------------------Action Function Section--------------------
    void gravity(const float &);
    void Dig(Stage &) const;
    void levelUP();
    void addLive();
    void addScore(int);
    void enemyCollision(const Virus &, const sf::Vector2f &);

    //--------------------Get Function Section--------------------
    int getLive() const;
    int getScore() const;
    int getLevel() const;

    //--------------------Set Function Section--------------------
    void setLive(int);
    void setLevel(int);

    //--------------------Virtual Function Section--------------------
    virtual sf::Vector2f move(const float &) override;
    //---Collision Function Section---
    using MovingObject::handleCollision;
    virtual void handleCollision(GameObject &, const sf::Vector2f &) override;
    virtual void handleCollision(StupidVirus &, const sf::Vector2f &) override;
    virtual void handleCollision(RandVirus &, const sf::Vector2f &) override;
    virtual void handleCollision(SmartVirus &, const sf::Vector2f &) override;
    virtual void handleCollision(Vaccine &, const sf::Vector2f &) override;
    virtual void handleCollision(Curtain &, const sf::Vector2f &) override;
    virtual void handleCollision(LiveGift &, const sf::Vector2f &) override;
    virtual void handleCollision(ScoreGift &, const sf::Vector2f &) override;
    virtual void handleCollision(TimeGift &, const sf::Vector2f &) override;
    virtual void handleCollision(VirusGift &, const sf::Vector2f &) override;

private:
    int m_lives;
    int m_level;
    int m_score;
};