#include "TimeGift.h"
#include "Player.h"
TimeGift::TimeGift(const sf::Vector2f & location, const sf::Texture & texture, const sf::Vector2i & stageSize, StageDetails & stageDetails)
 : Gift(location, texture, stageSize){
    m_stageDetails = &stageDetails;
 }
//=============================================================================
void TimeGift::activate() {
    m_stageDetails->addTime();
}
//=============================================================================
void TimeGift::handleCollision(Player & player, const sf::Vector2f & keyPressed) {
    activate();
    isDisposed();
    player.handleCollision(*this, keyPressed);
}
//=============================================================================