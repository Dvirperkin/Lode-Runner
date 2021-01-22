#include "TimeGift.h"


TimeGift::TimeGift(const sf::Vector2f & location, const sf::Vector2i & stageSize, StageDetails & stageDetails)
 : Gift(location, GIFT, stageSize){
    m_stageDetails = &stageDetails;
 }
//=============================================================================
void TimeGift::activate() {
    m_stageDetails->addTime();
    Sound::soundObject().playSound(TIME_GIFT_SOUND);
}
//=============================================================================
void TimeGift::handleCollision(Player & player, const sf::Vector2f & keyPressed) {
    activate();
    isDisposed();
    player.handleCollision(*this, keyPressed);
}
//=============================================================================