#pragma once
#include <SFML/Graphics.hpp>

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
    GameObject(const sf::Vector2f &, const sf::Texture &, const sf::Vector2i &);

    void initPosition(int, int, sf::Vector2i);
    virtual void draw (sf::RenderWindow &) const;

    const sf::Vector2f & getPosition () const;
    const sf::Vector2f & getLastPosition() const;
    const sf::Vector2f & getLastReflection() const;
    sf::FloatRect getGlobalBounds() const;
    sf::Vector2f getOrigin() const;
    sf::Vector2f getCenter() const;

    void setPosition(const sf::Vector2f &);
    void changePosition(const float &, const sf::Vector2f & , const sf::Vector2f &);
    void setLastPosition();

    void isDisposed();
    bool checkDisposed() const;
    void changeSize();

    //---Collision Function Section---
    bool checkCollision(const sf::FloatRect &);
    virtual void handleCollision(GameObject &gameObject, const sf::Vector2f &keyPressed) = 0;
    virtual void handleCollision(Player &gameObject, const sf::Vector2f &keyPressed) = 0;
    virtual void handleCollision(StupidEnemy &gameObject, const sf::Vector2f &) = 0;
    virtual void handleCollision(RandEnemy &gameObject, const sf::Vector2f &) = 0;
    virtual void handleCollision(SmartEnemy &gameObject, const sf::Vector2f &) = 0;
    virtual void handleCollision(Coin &gameObject, const sf::Vector2f &) = 0;
    virtual void handleCollision(Wall &gameObject, const sf::Vector2f &) = 0;
    virtual void handleCollision(Pole &gameObject, const sf::Vector2f &) = 0;
    virtual void handleCollision(Ladder &gameObject, const sf::Vector2f &) = 0;
    virtual void handleCollision(LiveGift &gameObject, const sf::Vector2f &) = 0;
    virtual void handleCollision(ScoreGift &gameObject, const sf::Vector2f &) = 0;
    virtual void handleCollision(TimeGift &, const sf::Vector2f &) = 0;
    virtual void handleCollision(EnemyGift &, const sf::Vector2f &) = 0;

private:
    sf::Vector2f m_position;
    sf::Vector2f m_lastPosition;
    sf::Vector2f m_lastReflection;
    sf::Sprite m_sprite;
    bool m_isDisposed;
    sf::Vector2f m_objectSize;
};
