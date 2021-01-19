#include "StupidEnemy.h"
#include<iostream>
StupidEnemy::StupidEnemy(const sf::Vector2f & location, const sf::Vector2i & stageSize)
 : Enemy(location, STUPID_ENEMY_TEXT, stageSize), m_direction(true)
 {}
//==============================================================================
sf::Vector2f StupidEnemy::move(const float & timeElapsed) {

    if(getInTheAir() || getLocked())
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
void StupidEnemy::handleCollision(Wall &wall, const sf::Vector2f &keyPressed) {
    setInTheAir(false);

    if(getGlobalBounds().contains(wall.getGlobalBounds().left, wall.getGlobalBounds().top + getGlobalBounds().height))
    {
        setLastPosition();
        m_direction = true;
        return;
    }

    else if(getGlobalBounds().contains(wall.getGlobalBounds().left + wall.getGlobalBounds().width, wall.getGlobalBounds().top + getGlobalBounds().height))
    {
        setLastPosition();
        m_direction = false;
        return;
    }

    Enemy::handleCollision(wall, keyPressed);
    
    if(!getLocked() && wall.checkDisposed()) {
        setPosition(wall.getPosition());
        setLock();
    }

    else if(getLocked())
    {
        if(!wall.checkDisposed()) {
            setPosition({getPosition().x, getPosition().y - getGlobalBounds().height - OFFSET_Y});
            setLock();
        }
    }
}
//=============================================================================