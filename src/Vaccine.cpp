#include "Vaccine.h"

Vaccine::Vaccine(const sf::Vector2f &location, const sf::Vector2i & stageSize, StageDetails & stageDetails)
    : SpecialObject(location, VACCINE, stageSize)
{
    m_stageDetails = &stageDetails;
}
//=============================================================================
void Vaccine::activate() {
    isDisposed();
    Sound::soundObject().playSound(VACCINE_SOUND);
    m_stageDetails->decCoin();
}
//=============================================================================
void Vaccine::handleCollision(Player & player, const sf::Vector2f & keyPressed) {
    activate();
    player.handleCollision(*this, keyPressed);
}
//=============================================================================
void Vaccine::handleCollision(StupidVirus & stupidEnemy, const sf::Vector2f & keyPressed) {
    stupidEnemy.handleCollision(*this, keyPressed);
}
//=============================================================================
void Vaccine::handleCollision(RandVirus & randEnemy, const sf::Vector2f & keyPressed) {
    randEnemy.handleCollision(*this, keyPressed);
}
//=============================================================================
void Vaccine::handleCollision(SmartVirus & smartEnemy, const sf::Vector2f & keyPressed) {
    smartEnemy.handleCollision(*this, keyPressed);
}
//=============================================================================