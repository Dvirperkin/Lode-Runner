#include "Enemy.h"
#include "Wall.h"

Enemy::Enemy(const sf::Vector2f &location, enum Textures_t object, const sf::Vector2i & stageSize)
    : MovingObject(location , object, stageSize), m_addedFromGift(false), m_locked(false)
{
}
//=============================================================================
void Enemy::setLock() {
    m_locked = !m_locked;
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
bool Enemy::getLocked() const {
    return m_locked;
}
//=============================================================================
void Enemy::handleCollision(Wall & wall, const sf::Vector2f & keyPressed) {

    if(!wall.checkDisposed())
        setLastPosition();

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





