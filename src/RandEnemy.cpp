#include "RandEnemy.h"
#include <iostream>

RandEnemy::RandEnemy(const sf::Vector2f & location, const sf::Vector2i & stageSize)
 : Enemy(location, ENEMY, stageSize)
 {
 }
//=============================================================================
sf::Vector2f RandEnemy::move(const float & timeElapsed) {

    if(getInTheAir() || getLocked())
        return STAND;

    srand(time(NULL));
    auto step = rand() % MOD4;

    switch(step)
    {
        case ENEMY_UP:
            changePosition(timeElapsed, UP, REFLECTION_UP);
            return UP;

        case ENEMY_DOWN:
            changePosition(timeElapsed, DOWN, REFLECTION_DOWN);
            return DOWN;

        case ENEMY_LEFT:
            changePosition(timeElapsed, LEFT, REFLECTION_LEFT);
            return LEFT;

        case ENEMY_RIGHT:
            changePosition(timeElapsed, RIGHT, REFLECTION_RIGHT);
            return RIGHT;

    }

    return STAND;
}
//=============================================================================
void RandEnemy::gravity(const float &timeElapsed) {
    setInTheAir(true);

    changePosition(timeElapsed, DOWN, REFLECTION_RIGHT);
}
//=============================================================================
void RandEnemy::handleCollision(GameObject &gameObject, const sf::Vector2f &keyPressed) {
    gameObject.handleCollision(*this, keyPressed);
}
//=============================================================================
void RandEnemy::handleCollision(Player &gameObject, const sf::Vector2f &keyPressed) {
    gameObject.handleCollision(*this, keyPressed);
}
//=============================================================================
