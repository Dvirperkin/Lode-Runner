#pragma once
#include "MovingObject.h"

class Enemy : public MovingObject {

public:
    Enemy(const sf::Vector2f & , const sf::Texture &, const sf::Vector2i &);

    void addEnemy();
    int getNumOfEnemies();

private:
    static int m_numOfEnemies;
};

