#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Textures.h"
#include "Sound.h"

class Player;
class Virus;
class StupidVirus;
class RandVirus;
class SmartVirus;
class Vaccine;
class Curtain;
class Rope;
class Ladder;
class LiveGift;
class ScoreGift;
class TimeGift;
class VirusGift;

class GameObject {

public:
    //--------------------Constructor/Destructor Section--------------------
    GameObject() = default;
    GameObject(const sf::Vector2f &, enum Textures_t, const sf::Vector2i &);

    //--------------------Action Function Section--------------------
    void initPosition(const sf::Vector2f &, const sf::Vector2i &);
    void changePosition(const float &, const sf::Vector2f & , const sf::Vector2f &);
    bool checkDisposed() const;
    void changeSize(float, float);
    void returnFirstPosition();

    //--------------------Get Function Section--------------------
    const sf::Vector2f & getPosition () const;
    const sf::Vector2f & getLastPosition() const;
    const sf::Vector2f & getLastReflection() const;
    sf::FloatRect getGlobalBounds() const;

    //--------------------Set Function Section--------------------
    void setPosition(const sf::Vector2f &);
    void setLastPosition();

    //--------------------Virtual Function Section--------------------
    virtual void isDisposed();
    virtual void draw (sf::RenderWindow &) const;
    //---Collision Function Section---
    bool checkCollision(const sf::FloatRect &);
    virtual void handleCollision(GameObject &, const sf::Vector2f &) = 0;
    virtual void handleCollision(Player &, const sf::Vector2f &) = 0;
    virtual void handleCollision(StupidVirus &, const sf::Vector2f &) = 0;
    virtual void handleCollision(RandVirus &, const sf::Vector2f &) = 0;
    virtual void handleCollision(SmartVirus &, const sf::Vector2f &) = 0;
    virtual void handleCollision(Vaccine &, const sf::Vector2f &) = 0;
    virtual void handleCollision(Curtain &, const sf::Vector2f &) = 0;
    virtual void handleCollision(Rope &, const sf::Vector2f &) = 0;
    virtual void handleCollision(Ladder &, const sf::Vector2f &) = 0;
    virtual void handleCollision(LiveGift &, const sf::Vector2f &) = 0;
    virtual void handleCollision(ScoreGift &, const sf::Vector2f &) = 0;
    virtual void handleCollision(TimeGift &, const sf::Vector2f &) = 0;
    virtual void handleCollision(VirusGift &, const sf::Vector2f &) = 0;

private:
    sf::Vector2f m_firstPosition;
    sf::Vector2f m_position;
    sf::Vector2f m_lastPosition;
    sf::Vector2f m_lastReflection;
    sf::Vector2f m_objectSize;
    sf::Sprite m_sprite;
    bool m_isDisposed;
};