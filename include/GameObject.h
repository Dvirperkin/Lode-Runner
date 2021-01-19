#pragma once
#include <SFML/Graphics.hpp>
#include "Textures.h"

class Player;
class StupidEnemy;
class RandEnemy;
class SmartEnemy;
class Coin;
class Wall;
class Pole;
class Ladder;
class LiveGift;
class ScoreGift;
class TimeGift;
class EnemyGift;

class GameObject {

public:
    GameObject() = default;
    GameObject(const sf::Vector2f &, enum Textures_t, const sf::Vector2i &);

    void initPosition(const sf::Vector2f &, const sf::Vector2i &);
    virtual void draw (sf::RenderWindow &) const;

    const sf::Vector2f & getPosition () const;
    const sf::Vector2f & getLastPosition() const;
    const sf::Vector2f & getLastReflection() const;
    sf::FloatRect getGlobalBounds() const;

    void setFirstPosition();
    void setPosition(const sf::Vector2f &);
    void setLastPosition();

    void changePosition(const float &, const sf::Vector2f & , const sf::Vector2f &);
    bool checkDisposed() const;
    void changeSize(float, float);

    virtual void isDisposed();

    //---Collision Function Section---
    bool checkCollision(const sf::FloatRect &);
    virtual void handleCollision(GameObject &, const sf::Vector2f &) = 0;
    virtual void handleCollision(Player &, const sf::Vector2f &) = 0;
    virtual void handleCollision(StupidEnemy &, const sf::Vector2f &) = 0;
    virtual void handleCollision(RandEnemy &, const sf::Vector2f &) = 0;
    virtual void handleCollision(SmartEnemy &, const sf::Vector2f &) = 0;
    virtual void handleCollision(Coin &, const sf::Vector2f &) = 0;
    virtual void handleCollision(Wall &, const sf::Vector2f &) = 0;
    virtual void handleCollision(Pole &, const sf::Vector2f &) = 0;
    virtual void handleCollision(Ladder &, const sf::Vector2f &) = 0;
    virtual void handleCollision(LiveGift &, const sf::Vector2f &) = 0;
    virtual void handleCollision(ScoreGift &, const sf::Vector2f &) = 0;
    virtual void handleCollision(TimeGift &, const sf::Vector2f &) = 0;
    virtual void handleCollision(EnemyGift &, const sf::Vector2f &) = 0;

private:
    sf::Vector2f m_firstPosition;
    sf::Vector2f m_position;
    sf::Vector2f m_lastPosition;
    sf::Vector2f m_lastReflection;
    sf::Sprite m_sprite;
    bool m_isDisposed;
    sf::Vector2f m_objectSize;
};