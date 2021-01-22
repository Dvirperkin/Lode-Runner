#include "VirusGift.h"

VirusGift::VirusGift(const sf::Vector2f & location, const sf::Vector2i & stageSize , Stage & stage)
 : Gift(location, GIFT, stageSize){

    m_stage = &stage;
}
//=============================================================================
void VirusGift::activate() {
    m_stage->addVirus();
    Sound::soundObject().playSound(VIRUS_GIFT_SOUND);
}
//=============================================================================
void VirusGift::handleCollision(Player & player, const sf::Vector2f & keyPressed) {
    activate();
    isDisposed();
    player.handleCollision(*this, keyPressed);
}
//=============================================================================
