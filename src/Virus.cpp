#include "Virus.h"
#include "Curtain.h"

Virus::Virus(const sf::Vector2f &location, enum Textures_t object, const sf::Vector2i & stageSize)
    : MovingObject(location , object, stageSize), m_addedFromGift(false), m_locked(false)
{
}
//=============================================================================
void Virus::setLock() {
    m_locked = !m_locked;
}
//=============================================================================
void Virus::setAddedFromGift() {
    m_addedFromGift = true;
}
//=============================================================================
bool Virus::getAddedFromGift() const{
    return m_addedFromGift;
}
//=============================================================================
bool Virus::getLocked() const {
    return m_locked;
}
//=============================================================================
void Virus::handleCollision(Curtain & wall, const sf::Vector2f & keyPressed) {
    setInTheAir(false);

    if(!wall.checkDisposed())
        setLastPosition();

    if(!getLocked() && wall.checkDisposed()) {
        setPosition(wall.getPosition());
        setLock();
    }

    else if(getLocked())
    {
        if(!wall.checkDisposed()) {
            setPosition({getPosition().x, getPosition().y - getGlobalBounds().height - (OFFSET_Y * 2)});
            setLock();
        }
    }
}
//=============================================================================





