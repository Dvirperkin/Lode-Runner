#include "Player.h"
#include "Stage.h"

Player::Player() {}
//=============================================================================
Player::Player(const sf::Vector2f &location, const sf::Vector2i & stageSize)
 : MovingObject(location, PLAYER, stageSize) , m_lives(LIVE), m_score(0), m_level(0)
{
}
//===================================================================
sf::Vector2f Player::move(const float &timeElapsed)
{
    if(getInTheAir())
        return STAND;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
        Sound::soundObject().playSound(VIRUS_COLLISION);
        isDisposed();
        m_lives--;
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        changePosition(timeElapsed, LEFT, REFLECTION_LEFT);
        return LEFT;
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        changePosition(timeElapsed, RIGHT, REFLECTION_RIGHT);
        return RIGHT;
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        changePosition(timeElapsed, UP, REFLECTION_UP);
        return UP;
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        changePosition(timeElapsed, DOWN, REFLECTION_DOWN);
        return DOWN;
    }

    return STAND;
}
//=============================================================================
void Player::Dig(Stage & stage) const {

    auto arrPosition = sf::Vector2i((getPosition().x / WINDOW_WIDTH) * stage.getStageSize().x,
                                    ((getPosition().y - STAGE_DETAILS_SIZE) / (WINDOW_HEIGHT - STAGE_DETAILS_SIZE)) * stage.getStageSize().y);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        stage.BreakWall(arrPosition.y + 1, arrPosition.x - 1);
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::X) || sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
        stage.BreakWall(arrPosition.y + 1, arrPosition.x + 1);
    }
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
int Player::getLevel() const {
    return m_level;
}
//=============================================================================
void Player::setLive(int live) {
    m_lives = live;
}
//=============================================================================
void Player::setLevel(int level) {
    m_level = level;
}
//=============================================================================
void Player::levelUP() {
    m_score += m_level * LEVEL_SCORE;
    m_level++;
}
//=============================================================================
void Player::addLive() {
    m_lives++;
}
//=============================================================================
void Player::addScore(int score) {
    if(score > 0)
        m_score += score;
}
//=============================================================================
void Player::enemyCollision(const Virus & enemy, const sf::Vector2f & keyPressed) {
    setInTheAir(false);

    if(enemy.getLocked()) {
        setPosition({getPosition().x + keyPressed.x, getLastPosition().y - OFFSET_Y * 2});
        return;
    }

    Sound::soundObject().playSound(VIRUS_COLLISION);
    isDisposed();
    m_lives--;
}
//=============================================================================
void Player::handleCollision(GameObject &gameObject, const sf::Vector2f &keyPressed) {
    if(this == &gameObject)
        return;

    gameObject.handleCollision(*this, keyPressed);
}
//=============================================================================
void Player::handleCollision(StupidVirus & stupidEnemy, const sf::Vector2f & keyPressed) {
    enemyCollision(stupidEnemy, keyPressed);
}
//=============================================================================
void Player::handleCollision(RandVirus & randEnemy, const sf::Vector2f & keyPressed) {
    enemyCollision(randEnemy, keyPressed);
}
//=============================================================================
void Player::handleCollision(SmartVirus & smartEnemy, const sf::Vector2f & keyPressed) {
    enemyCollision(smartEnemy, keyPressed);
}
//=============================================================================
void Player::handleCollision(Vaccine & coin, const sf::Vector2f & keyPressed) {
    setOnLadder(false);
    setOnPole(false);

    m_score += m_level * COIN_SCORE;
}
//=============================================================================
void Player::handleCollision(Curtain & wall, const sf::Vector2f & keyPressed) {
    setInTheAir(false);

    if(!wall.checkDisposed()) {
        if (wall.getGlobalBounds().contains(getPosition())) {
            isDisposed();
            m_lives--;
        }

        setLastPosition();
    }
}
//=============================================================================
void Player::handleCollision(LiveGift & liveGift, const sf::Vector2f & keyPressed) {
    setOnLadder(false);
    setOnPole(false);
}
//=============================================================================
void Player::handleCollision(ScoreGift & scoreGift, const sf::Vector2f & keyPressed) {
    setOnLadder(false);
    setOnPole(false);
}
//=============================================================================
void Player::handleCollision(TimeGift & timeGift, const sf::Vector2f & keyPressed) {
    setOnLadder(false);
    setOnPole(false);
}
//=============================================================================
void Player::handleCollision(VirusGift &, const sf::Vector2f & keyPressed) {
    setOnLadder(false);
    setOnPole(false);
}
//=============================================================================