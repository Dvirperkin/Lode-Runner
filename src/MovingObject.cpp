#include "MovingObject.h"
#include "Player.h"
#include "StupidVirus.h"
#include "RandVirus.h"
#include "SmartVirus.h"
#include "Vaccine.h"
#include "Rope.h"
#include "Ladder.h"
#include "LiveGift.h"
#include "ScoreGift.h"
#include "TimeGift.h"
#include "VirusGift.h"


MovingObject::MovingObject(const sf::Vector2f &location, enum Textures_t object, const sf::Vector2i & stageSize)
 : GameObject(location , object, stageSize), m_inTheAir(false), m_onLadder(false), m_onPole(false){

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
void MovingObject::handleCollision(Player & player, const sf::Vector2f &keyPressed) {
    /*ignore*/
}
//=============================================================================
void MovingObject::handleCollision(StupidVirus &gameObject, const sf::Vector2f &) {
    /*ignore*/
}
//=============================================================================
void MovingObject::handleCollision(RandVirus &gameObject, const sf::Vector2f &) {
    /*ignore*/
}
//=============================================================================
void MovingObject::handleCollision(SmartVirus &gameObject, const sf::Vector2f &) {
    /*ignore*/
}
//=============================================================================
void MovingObject::handleCollision(Vaccine &gameObject, const sf::Vector2f & keyPressed) {
    setOnLadder(false);
    setOnPole(false);

    if(keyPressed == UP){
        setLastPosition();
    }
}
//=============================================================================
void MovingObject::handleCollision(Curtain & wall, const sf::Vector2f &) {
    setInTheAir(false);

    if(!wall.checkDisposed())
        setLastPosition();
}
//=============================================================================
void MovingObject::handleCollision(Rope &gameObject, const sf::Vector2f & keyPressed) {
    setInTheAir(false);
    //setOnLadder(false);

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
    if(gameObject.getGlobalBounds().contains({getGlobalBounds().left + getGlobalBounds().width, getGlobalBounds().top + getGlobalBounds().height})
            && !getOnPole()){

        setPosition({getPosition().x, gameObject.getPosition().y});
        setOnPole(true);
    }
}
//=============================================================================
void MovingObject::handleCollision(Ladder &gameObject, const sf::Vector2f & keyPressed) {
    setInTheAir(false);
    //setOnPole(false);

    if(gameObject.getGlobalBounds().contains(getPosition()) || gameObject.getGlobalBounds().contains(getPosition().x, getPosition().y + getGlobalBounds().height/2)) {

        if (!getOnLadder() && (keyPressed == UP || keyPressed == DOWN)) {
            setPosition({gameObject.getPosition().x, getPosition().y});

            setOnPole(false);
            setOnLadder(true);
            return;
        }

        if (getOnLadder() && (keyPressed == RIGHT || keyPressed == LEFT)) {
            setOnLadder(false);
        }
    }

    else if(!getOnLadder() && (keyPressed == UP))
        setLastPosition();

    //Change Sprite.
}
//=============================================================================
void MovingObject::handleCollision(LiveGift &gameObject, const sf::Vector2f & keyPressed) {
    setOnLadder(false);
    setOnPole(false);

    if(keyPressed == UP){
        setLastPosition();
    }
}
//=============================================================================
void MovingObject::handleCollision(ScoreGift &gameObject, const sf::Vector2f & keyPressed) {
    setOnLadder(false);
    setOnPole(false);

    if(keyPressed == UP){
        setLastPosition();
    }
}
//=============================================================================
void MovingObject::handleCollision(TimeGift &, const sf::Vector2f & keyPressed) {
    setOnLadder(false);
    setOnPole(false);

    if(keyPressed == UP){
        setLastPosition();
    }
}
//=============================================================================
void MovingObject::handleCollision(VirusGift &, const sf::Vector2f & keyPressed) {
    setOnLadder(false);
    setOnPole(false);

    if(keyPressed == UP){
        setLastPosition();
    }
}
//=============================================================================