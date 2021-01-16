#include "GameObject.h"
#include "Macros.h"
#include <iostream>

GameObject::GameObject(const sf::Vector2f & position, const sf::Texture & texture, const sf::Vector2i & stageSize)
        : m_position(position), m_sprite(texture), m_isDisposed(false), m_lastReflection(REFLECTION_RIGHT)
{
    //Get the default size of the object to set the correct origin.
    m_objectSize.x = m_sprite.getTexture()->getSize().x;
    m_objectSize.y = m_sprite.getTexture()->getSize().y;

    m_sprite.setOrigin({m_objectSize.x / 2 , m_objectSize.y / 2});

    m_sprite.setScale(WINDOW_WIDTH / (stageSize.x * m_sprite.getLocalBounds().width), WINDOW_HEIGHT / (stageSize.y * m_sprite.getLocalBounds().height));

    //Get the new size of the object after resize it according to the size of the stage.
    m_objectSize.x = m_sprite.getScale().x * m_sprite.getTexture()->getSize().x;
    m_objectSize.y = m_sprite.getScale().y *  m_sprite.getTexture()->getSize().y;

    initPosition(position, stageSize);
}
//=============================================================================
const sf::Vector2f &GameObject::getPosition() const
{
    return m_position;
}
//=============================================================================
const sf::Vector2f & GameObject::getLastPosition() const {
    return m_lastPosition;
}
//=============================================================================
const sf::Vector2f & GameObject::getLastReflection() const {
    return m_lastReflection;
}
//=============================================================================
void GameObject::draw(sf::RenderWindow &window) const
{
    window.draw(m_sprite);
}
//=============================================================================
void GameObject::initPosition(const sf::Vector2f & position, const sf::Vector2i & stageSize) {
    m_firstPosition.x = (position.x * WINDOW_WIDTH / stageSize.x) + WINDOW_WIDTH / (stageSize.x * 2);
    m_firstPosition.y = (position.y * (WINDOW_HEIGHT - STAGE_DETAILS_SIZE) / stageSize.y) + STAGE_DETAILS_SIZE + WINDOW_HEIGHT / (stageSize.y * 2);
    m_sprite.setPosition(m_firstPosition);
    m_position = m_firstPosition;
    m_lastPosition = m_sprite.getPosition();
}
//=============================================================================
void GameObject::changeSize(){
    //Decrease the size of the object by 20%.
    m_sprite.scale(0.8,0.8);
    m_objectSize.x = m_sprite.getScale().x * m_sprite.getTexture()->getSize().x;
    m_objectSize.y = m_sprite.getScale().y *  m_sprite.getTexture()->getSize().y;
}
//=============================================================================
void GameObject::setFirstPosition() {
    m_sprite.setPosition(m_firstPosition);
}
//=============================================================================
void GameObject::setPosition(const sf::Vector2f & position) {
    m_sprite.setPosition(position);
}
//=============================================================================
void GameObject::changePosition(const float & timeElapsed, const sf::Vector2f & direction, const sf::Vector2f & reflection){

    auto checkMove = m_lastReflection + (direction * SPEED_PER_SECOND * timeElapsed);

    m_lastPosition = m_sprite.getPosition();
    m_sprite.move(direction * SPEED_PER_SECOND * timeElapsed);
    m_position = m_sprite.getPosition();

    if(m_position.x < 0 || m_position.x > WINDOW_WIDTH || m_position.y < 0 || m_position.y > WINDOW_HEIGHT)
        setLastPosition();

    if(reflection == REFLECTION_RIGHT && m_lastReflection == REFLECTION_LEFT){
        m_sprite.scale(REFLECTION_LEFT);

        m_lastReflection = reflection;
    }

    else if(m_lastReflection != reflection) {
        m_sprite.scale(reflection);

        m_lastReflection = reflection;
    }
}
//=============================================================================
void GameObject::setLastPosition() {
    m_sprite.setPosition(m_lastPosition);
}
//=============================================================================
void GameObject::isDisposed() {

    if(m_isDisposed)
        m_isDisposed = false;

    else
        m_isDisposed = true;
}
//=============================================================================
bool GameObject::checkDisposed() const{
    return m_isDisposed;
}
//=============================================================================
sf::FloatRect GameObject::getGlobalBounds() const {
    return m_sprite.getGlobalBounds();
}
//=============================================================================
bool GameObject::checkCollision(const sf::FloatRect & otherGlobalBound) {
    return m_sprite.getGlobalBounds().intersects(otherGlobalBound);
}
//=============================================================================

