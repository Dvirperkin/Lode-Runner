//
// Created by dvir on 02/01/2021.
//

#include "SmartEnemy.h"

SmartEnemy::SmartEnemy(const sf::Vector2f & location, const sf::Texture & texture, const sf::Vector2i & stageSize)
 : Enemy(location, texture, stageSize)
 {}
//=============================================================================
sf::Vector2f SmartEnemy::move(const float &) {

    return STAND;
}
//=============================================================================
void SmartEnemy::gravity(const float &) {

}
//=============================================================================
void SmartEnemy::handleCollision(GameObject &gameObject, const sf::Vector2f &keyPressed) {

}
//=============================================================================
void SmartEnemy::handleCollision(Player &gameObject, const sf::Vector2f &) {

}
//=============================================================================