#include "Curtain.h"

Curtain::Curtain(const sf::Vector2f &location, const sf::Vector2i & stageSize)
    : StaticObject(location , CURTAIN, stageSize)
{
}
//=============================================================================
void Curtain::isDisposed() {
    GameObject::isDisposed();
    if(checkDisposed())
        m_disposedTimer = sf::seconds(CURTAIN_DISPOSED_TIME);

}
//=============================================================================
void Curtain::reduceTime(float timeElapsed) {
    m_disposedTimer = sf::seconds(m_disposedTimer.asSeconds() - timeElapsed);
}
//=============================================================================
float Curtain::getDisposedTime() {
    return m_disposedTimer.asSeconds();
}
//=============================================================================
void Curtain::handleCollision(Player & player, const sf::Vector2f &keyPressed) {
    player.handleCollision(*this, keyPressed);
}
//=============================================================================
void Curtain::handleCollision(StupidVirus & stupidEnemy, const sf::Vector2f & keyPressed) {
    stupidEnemy.handleCollision(*this, keyPressed);
}
//=============================================================================
void Curtain::handleCollision(RandVirus & randEnemy, const sf::Vector2f & keyPressed) {
    randEnemy.handleCollision(*this, keyPressed);
}
//=============================================================================
void Curtain::handleCollision(SmartVirus & smartEnemy, const sf::Vector2f & keyPressed) {
    smartEnemy.handleCollision(*this, keyPressed);
}
//=============================================================================