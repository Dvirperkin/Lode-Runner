#include "RandVirus.h"

RandVirus::RandVirus(const sf::Vector2f & location, const sf::Vector2i & stageSize)
 : Virus(location, RAND_VIRUS_TEXT, stageSize)
 {
 }
//=============================================================================
sf::Vector2f RandVirus::move(const float & timeElapsed) {

    if(getInTheAir() || getLocked())
        return STAND;

    srand(time(NULL));
    auto step = rand() % MOD4;

    switch(step)
    {
        case VIRUS_UP:
            changePosition(timeElapsed, UP, REFLECTION_UP);
            return UP;

        case VIRUS_DOWN:
            changePosition(timeElapsed, DOWN, REFLECTION_DOWN);
            return DOWN;

        case VIRUS_LEFT:
            changePosition(timeElapsed, LEFT, REFLECTION_LEFT);
            return LEFT;

        case VIRUS_RIGHT:
            changePosition(timeElapsed, RIGHT, REFLECTION_RIGHT);
            return RIGHT;

    }

    return STAND;
}
//=============================================================================
void RandVirus::gravity(const float &timeElapsed) {
    setInTheAir(true);

    changePosition(timeElapsed, DOWN, REFLECTION_RIGHT);
}
//=============================================================================
void RandVirus::handleCollision(GameObject &gameObject, const sf::Vector2f &keyPressed) {
    gameObject.handleCollision(*this, keyPressed);
}
//=============================================================================
void RandVirus::handleCollision(Player &gameObject, const sf::Vector2f &keyPressed) {
    gameObject.handleCollision(*this, keyPressed);
}
//=============================================================================
