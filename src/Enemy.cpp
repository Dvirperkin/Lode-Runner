#include "Enemy.h"

int Enemy::m_numOfEnemies = 0;

Enemy::Enemy(const sf::Vector2f &location, const sf::Texture &texture, const sf::Vector2i & stageSize)
    : MovingObject(location , texture, stageSize)
{
}
//=============================================================================
void Enemy::addEnemy() {
    m_numOfEnemies++;
}
//=============================================================================
int Enemy::getNumOfEnemies() {
    return m_numOfEnemies;
}
//=============================================================================





