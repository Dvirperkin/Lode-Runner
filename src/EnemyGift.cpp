#include "EnemyGift.h"
#include "Stage.h"
#include "Player.h"

EnemyGift::EnemyGift(const sf::Vector2f & location, const sf::Vector2i & stageSize , Stage & stage)
 : Gift(location, GIFT, stageSize){

    m_stage = &stage;
}
//=============================================================================
void EnemyGift::activate() {
    m_stage->addEnemy();
}
//=============================================================================
void EnemyGift::handleCollision(Player & player, const sf::Vector2f & keyPressed) {
    activate();
    isDisposed();
    player.handleCollision(*this, keyPressed);
}
//=============================================================================
