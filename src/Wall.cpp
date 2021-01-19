#include "Wall.h"

Wall::Wall(const sf::Vector2f &location, const sf::Vector2i & stageSize)
    : StaticObject(location , WALL, stageSize)
{

}
//=============================================================================
void Wall::isDisposed() {
    GameObject::isDisposed();
    m_disposedTimer = sf::seconds(WALL_DISPOSED_TIME);
}
//=============================================================================
void Wall::reduceTime(float timeElapsed) {
    m_disposedTimer = sf::seconds(m_disposedTimer.asSeconds() - timeElapsed);
}
//=============================================================================
float Wall::getDisposedTime() {
    return m_disposedTimer.asSeconds();
}
//=============================================================================
void Wall::handleCollision(Player & player, const sf::Vector2f &keyPressed) {
    player.handleCollision(*this, keyPressed);
}
//=============================================================================
void Wall::handleCollision(StupidEnemy & stupidEnemy, const sf::Vector2f & keyPressed) {
    stupidEnemy.handleCollision(*this, keyPressed);
}
//=============================================================================
void Wall::handleCollision(RandEnemy & randEnemy, const sf::Vector2f & keyPressed) {
    randEnemy.handleCollision(*this, keyPressed);
}
//=============================================================================
void Wall::handleCollision(SmartEnemy & smartEnemy, const sf::Vector2f & keyPressed) {
    smartEnemy.handleCollision(*this, keyPressed);
}
//=============================================================================