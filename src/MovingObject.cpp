#include "MovingObject.h"
#include "Player.h"
#include "StupidEnemy.h"
#include "RandEnemy.h"
#include "SmartEnemy.h"
#include "Coin.h"
#include "Pole.h"
#include "Ladder.h"
#include "LiveGift.h"
#include "ScoreGift.h"
#include "TimeGift.h"
#include "EnemyGift.h"


MovingObject::MovingObject(const sf::Vector2f &location, const sf::Texture &texture, const sf::Vector2i & stageSize)
 : GameObject(location , texture, stageSize), m_inTheAir(false), m_onLadder(false), m_onPole(false)
{
}
//=============================================================================
bool MovingObject::getOnPole() const {
    return m_onPole;
}
//=============================================================================
bool MovingObject::getInTheAir() const {
    return m_inTheAir;
}
//=============================================================================
bool MovingObject::getOnLadder() const{

    return m_onLadder;
}
//=============================================================================
void MovingObject::setOnLadder(bool status) {
    m_onLadder = status;
}
//=============================================================================
void MovingObject::setOnPole(bool status) {
    m_onPole = status;
}
//=============================================================================
void MovingObject::setInTheAir(bool status) {
    m_inTheAir = status;
}
//=============================================================================
void MovingObject::handleCollision(GameObject &gameObject, const sf::Vector2f &keyPressed) {
    /*ignore*/
}
//=============================================================================
void MovingObject::handleCollision(Player &gameObject, const sf::Vector2f &keyPressed) {
    /*ignore*/
}
//=============================================================================
void MovingObject::handleCollision(StupidEnemy &gameObject, const sf::Vector2f &) {
    /*ignore*/
}
//=============================================================================
void MovingObject::handleCollision(RandEnemy &gameObject, const sf::Vector2f &) {
    /*ignore*/
}
//=============================================================================
void MovingObject::handleCollision(SmartEnemy &gameObject, const sf::Vector2f &) {
    /*ignore*/
}
//=============================================================================
void MovingObject::handleCollision(Coin &gameObject, const sf::Vector2f & keyPressed) {
    setInTheAir(false);
    setOnLadder(false);

    if(keyPressed == UP){
        setLastPosition();
    }
}
//=============================================================================
void MovingObject::handleCollision(Wall &gameObject, const sf::Vector2f &) {
    setInTheAir(false);

    setLastPosition();
}
//=============================================================================
void MovingObject::handleCollision(Pole &gameObject, const sf::Vector2f & keyPressed) {
    setInTheAir(false);
    setOnLadder(false);

    //Prevent to go up on pole.
    if(keyPressed == UP) {
        setLastPosition();
        return;
    }

    //Falling from pole.
    if (getOnPole() && keyPressed == DOWN) {
        setPosition({getPosition().x,getPosition().y + getGlobalBounds().height});
        setOnPole(false);
    }

    //In case of fall on pole, move the player on the pole.
    if(gameObject.getGlobalBounds().contains({getGlobalBounds().left + getGlobalBounds().width - 10, getGlobalBounds().top + getGlobalBounds().height})
            && !getOnPole()){

        setPosition(gameObject.getPosition());
        setOnPole(true);
    }
}
//=============================================================================
void MovingObject::handleCollision(Ladder &gameObject, const sf::Vector2f & keyPressed) {
    setInTheAir(false);

    if(gameObject.getGlobalBounds().contains(getCenter())) {

        if (!getOnLadder() && (keyPressed == UP || keyPressed == DOWN)) {
            setPosition(gameObject.getPosition());

            setOnPole(false);
            setOnLadder(true);
            return;
        }



        else if (getOnLadder() && (keyPressed == RIGHT || keyPressed == LEFT)) {
            setOnLadder(false);
        }
    }

    //Change Sprite.
}
//=============================================================================
void MovingObject::handleCollision(LiveGift &gameObject, const sf::Vector2f &) {
    setInTheAir(false);
    setOnLadder(false);
}
//=============================================================================
void MovingObject::handleCollision(ScoreGift &gameObject, const sf::Vector2f &) {
    setInTheAir(false);
    setOnLadder(false);
}
//=============================================================================
void MovingObject::handleCollision(TimeGift &, const sf::Vector2f &) {
    setInTheAir(false);
    setOnLadder(false);
}
//=============================================================================
void MovingObject::handleCollision(EnemyGift &, const sf::Vector2f &) {
    setInTheAir(false);
    setOnLadder(false);
}
//=============================================================================