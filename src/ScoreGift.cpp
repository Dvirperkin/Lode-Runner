#include "ScoreGift.h"
#include "Player.h"

ScoreGift::ScoreGift(const sf::Vector2f & location, const sf::Vector2i & stageSize, Player & player)
 : Gift(location, GIFT, stageSize){
    m_player = &player;
 }
//=============================================================================
void ScoreGift::activate() {
    isDisposed();
    m_player->addScore(GIFT_SCORE);
}
//=============================================================================
void ScoreGift::handleCollision(Player & player, const sf::Vector2f & keyPressed) {
    activate();
    player.handleCollision(*this, keyPressed);
}
//=============================================================================