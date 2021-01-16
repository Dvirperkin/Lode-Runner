#include "LiveGift.h"
#include "Player.h"

LiveGift::LiveGift(const sf::Vector2f & location, const sf::Texture & texture, const sf::Vector2i & stageSize, Player & player)
 : Gift(location, texture, stageSize)
 {
    m_player = &player;
 }
//=============================================================================
void LiveGift::activate() {
    isDisposed();
    m_player->addLive();
}
//=============================================================================
void LiveGift::handleCollision(Player & player, const sf::Vector2f & keyPressed) {
    activate();
    player.handleCollision(*this, keyPressed);
}
//=============================================================================