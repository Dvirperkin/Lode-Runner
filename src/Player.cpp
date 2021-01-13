#include "Player.h"
#include <iostream>

Player::Player(const sf::Vector2f &location, const sf::Texture &texture, const sf::Vector2i & stageSize)
 : MovingObject(location , texture, stageSize) , m_lives(LIVE), m_score(0), m_level(0)
{
}
//===================================================================
sf::Vector2f Player::move(const float &timeElapsed)
{
    if(getInTheAir())
        return STAND;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        changePosition(timeElapsed, LEFT, REFLECTION_LEFT);
        return LEFT;
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        changePosition(timeElapsed, RIGHT, REFLECTION_RIGHT);
        return RIGHT;
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {

        changePosition(timeElapsed, UP, REFLECTION_UP);
        return UP;
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        changePosition(timeElapsed, DOWN, REFLECTION_DOWN);
        return DOWN;
    }

    return STAND;
}
//=============================================================================
void Player::gravity(const float &timeElapsed) {
    setInTheAir(true);

    changePosition(timeElapsed, DOWN, getLastReflection());
}
//=============================================================================
int Player::getLive() const {
    return m_lives;
}
//=============================================================================
int Player::getScore() const{
    return m_score;
}
//=============================================================================
void Player::levelUP() {
    m_score += m_level * LEVEL_SCORE;
    m_level++;
}
//=============================================================================
void Player::handleCollision(GameObject &gameObject, const sf::Vector2f &keyPressed) {
    if(this == &gameObject)
        return;

    gameObject.handleCollision(*this, keyPressed);
}
//=============================================================================
void Player::handleCollision(StupidEnemy &gameObject, const sf::Vector2f &) {
    setInTheAir(false);
    isDisposed();
    m_lives--;
    std::cout << m_lives << std::endl;
    std::cout << "StupidEnemy" << std::endl;
}
//=============================================================================
void Player::handleCollision(RandEnemy &gameObject, const sf::Vector2f &) {
    setInTheAir(false);
    isDisposed();
    m_lives--;
    std::cout << m_lives << std::endl;
    std::cout << "RandEnemy" << std::endl;
}
//=============================================================================
void Player::handleCollision(SmartEnemy &gameObject, const sf::Vector2f &) {
    setInTheAir(false);
    isDisposed();
    m_lives--;
    std::cout << m_lives << std::endl;
    std::cout << "SmartEnemy" << std::endl;
}
//=============================================================================
void Player::handleCollision(Coin &gameObject, const sf::Vector2f & keyPressed) {
    setInTheAir(false);
    setOnLadder(false);

    m_score += m_level * COIN_SCORE;
}
//=============================================================================
void Player::handleCollision(LiveGift &gameObject, const sf::Vector2f &) {
    setInTheAir(false);
    setOnLadder(false);
}
//=============================================================================
void Player::handleCollision(ScoreGift &gameObject, const sf::Vector2f &) {
    setInTheAir(false);
    setOnLadder(false);
}
//=============================================================================
void Player::handleCollision(TimeGift &, const sf::Vector2f &) {
    setInTheAir(false);
    setOnLadder(false);
}
//=============================================================================
void Player::handleCollision(EnemyGift &, const sf::Vector2f &) {
    setInTheAir(false);
    setOnLadder(false);
}
//=============================================================================