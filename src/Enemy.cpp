#include "Enemy.h"

Enemy::Enemy(const sf::Vector2f &location, const sf::Texture &texture, const sf::Vector2i & stageSize)
    : MovingObject(location , texture, stageSize), m_addedFromGift(false)
{
}
//=============================================================================
void Enemy::setAddedFromGift() {
    m_addedFromGift = true;
}
//=============================================================================
bool Enemy::getAddedFromGift() const{
    return m_addedFromGift;
}
//=============================================================================





