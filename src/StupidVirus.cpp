#include "StupidVirus.h"

StupidVirus::StupidVirus(const sf::Vector2f & location, const sf::Vector2i & stageSize)
 : Virus(location, STUPID_VIRUS_TEXT, stageSize), m_direction(true)
 {}
//==============================================================================
sf::Vector2f StupidVirus::move(const float & timeElapsed) {

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
void StupidVirus::gravity(const float & timeElapsed) {
    setInTheAir(true);

    changePosition(timeElapsed, DOWN, getLastReflection());
}
//=============================================================================
void StupidVirus::handleCollision(GameObject &gameObject, const sf::Vector2f &keyPressed) {
    gameObject.handleCollision(*this, keyPressed);
}
//=============================================================================
void StupidVirus::handleCollision(Player &gameObject, const sf::Vector2f &keyPressed) {
    gameObject.handleCollision(*this, keyPressed);
}
//=============================================================================
void StupidVirus::handleCollision(Curtain &wall, const sf::Vector2f &keyPressed) {
    setInTheAir(false);

    if(getGlobalBounds().contains(wall.getGlobalBounds().left, wall.getGlobalBounds().top + getGlobalBounds().height) ||
        getGlobalBounds().left + getGlobalBounds().width >= WINDOW_WIDTH)
    {
        setLastPosition();
        m_direction = true;
        return;
    }

    else if(getGlobalBounds().contains(wall.getGlobalBounds().left + wall.getGlobalBounds().width, wall.getGlobalBounds().top + getGlobalBounds().height) ||
            getGlobalBounds().left <= 0)
    {
        setLastPosition();
        m_direction = false;
        return;
    }

    Virus::handleCollision(wall, keyPressed);
    
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