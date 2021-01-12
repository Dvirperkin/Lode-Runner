#include "StupidEnemy.h"
#include<iostream>
StupidEnemy::StupidEnemy(const sf::Vector2f & location, const sf::Texture & texture, const sf::Vector2i & stageSize)
 : Enemy(location, texture, stageSize), m_direction(true)
 {}
//==============================================================================
sf::Vector2f StupidEnemy::move(const float & timeElapsed) {

    if(getInTheAir())
        return STAND;

    if(m_direction) {
        changePosition(timeElapsed, LEFT, REFLECTION_LEFT);
        return LEFT;
    }

    else{
        changePosition(timeElapsed, RIGHT, REFLECTION_RIGHT);
        return RIGHT;
    }

    return STAND;
}
//=============================================================================
void StupidEnemy::gravity(const float & timeElapsed) {
    setInTheAir(true);

    changePosition(timeElapsed, DOWN, getLastReflection());
}
//=============================================================================
void StupidEnemy::handleCollision(GameObject &gameObject, const sf::Vector2f &keyPressed) {
    gameObject.handleCollision(*this, keyPressed);
}
//=============================================================================
void StupidEnemy::handleCollision(Player &gameObject, const sf::Vector2f &keyPressed) {
    gameObject.handleCollision(*this, keyPressed);
}
//=============================================================================
void StupidEnemy::handleCollision(Wall &gameObject, const sf::Vector2f &keyPressed) {
    setInTheAir(false);

    if(getGlobalBounds().contains(gameObject.getGlobalBounds().left, gameObject.getGlobalBounds().top + gameObject.getGlobalBounds().height))
    {
        setLastPosition();
        m_direction = true;
        return;
    }

    else if(getGlobalBounds().contains(gameObject.getGlobalBounds().left + gameObject.getGlobalBounds().width, gameObject.getGlobalBounds().top + gameObject.getGlobalBounds().height))
    {
        setLastPosition();
        m_direction = false;
        return;
    }
}
//=============================================================================