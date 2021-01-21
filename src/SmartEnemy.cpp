#include "SmartEnemy.h"
#include "Stage.h"

SmartEnemy::SmartEnemy(const sf::Vector2f & location, Stage & stage)
 : Enemy(location, SMART_ENEMY_TEXT, stage.getStageSize()), m_stage(&stage), m_firstRun(true), m_time(0)
 {
     m_timeLimit = (m_stage->getStageSize().x + m_stage->getStageSize().y > STAGE_SIZE_FACTOR ? SMALL_TIME_LIMIT : BIG_TIME_LIMIT);
 }
//=============================================================================
sf::Vector2f SmartEnemy::move(const float &timeElapsed){

    m_time += timeElapsed;

    // set the last array position
    auto lastArrPosition =  sf::Vector2i((getLastPosition().x / WINDOW_WIDTH) * m_stage->getStageSize().x ,
                                         ((getLastPosition().y - STAGE_DETAILS_SIZE) / (WINDOW_HEIGHT - STAGE_DETAILS_SIZE)) * m_stage->getStageSize().y);
    // set the current array position
    auto currentArrPosition = sf::Vector2i((getPosition().x / WINDOW_WIDTH) * m_stage->getStageSize().x ,
                                           ((getPosition().y - STAGE_DETAILS_SIZE) / (WINDOW_HEIGHT - STAGE_DETAILS_SIZE)) * m_stage->getStageSize().y);
    m_currPair = {lastArrPosition, currentArrPosition};

    // used to set the last directionAndObj (enemy last position and enemy current position)
    if (m_firstRun) {
        m_lastPair = m_currPair;
        m_firstRun = false;
    }

    std::pair<sf::Vector2f , graphStaticObjects_t> directionAndObj = m_stage->getGameGraph().getDirectionAndObj(getPosition());

    auto direction = directionAndObj.first;
    auto object = directionAndObj.second;

    if (m_currPair != m_lastPair) { // the enemy managed to move
        m_lastPair = m_currPair;
        m_time = 0;
    }

        // need to set a factor to m_time
    else if (m_currPair == m_lastPair && (m_time > m_timeLimit)) // the enemy did not manage to move - got stuck
    {
        if (object == NULL_OBJECT) { // on the air (trying to get down)
            //check if in the left bottom diagonal there is a wall if so - we need to move right.
            if (m_stage->getGameGraph().getObjectInPosition({currentArrPosition.x - 1, currentArrPosition.y + 1}) == WALL_OBJECT) {
                changePosition(timeElapsed, RIGHT, REFLECTION_UP);
                return RIGHT;
            }
            //check if in the right bottom diagonal there is a wall if so - we need to move left.
            if (m_stage->getGameGraph().getObjectInPosition({currentArrPosition.x + 1, currentArrPosition.y + 1}) == WALL_OBJECT)
            {
                changePosition(timeElapsed, LEFT, REFLECTION_UP);
                return LEFT;
            }
        }

        else if (object == LADDER_OBJECT) {
            //if in the left/right bottom diagonal there is a wall if so - we need to go up.
            if (m_stage->getGameGraph().getObjectInPosition({currentArrPosition.x - 1, currentArrPosition.y + 1}) == WALL_OBJECT
                || m_stage->getGameGraph().getObjectInPosition({currentArrPosition.x + 1, currentArrPosition.y + 1}) == WALL_OBJECT) {
                // if on the left/right diagonal has well then we are going up
                changePosition(timeElapsed, UP, REFLECTION_UP);
                return UP;
            }
            else {
                changePosition(timeElapsed, DOWN, REFLECTION_UP);
                return DOWN;
            }
        }
    }
    //if not stuck.
    if (direction == LEFT) {
        changePosition(timeElapsed, LEFT, REFLECTION_LEFT);
        return LEFT;
    } else if (direction == RIGHT) {
        changePosition(timeElapsed, RIGHT, REFLECTION_RIGHT);
        return RIGHT;
    } else if (direction == UP) {
        changePosition(timeElapsed, UP, REFLECTION_LEFT);
        return UP;
    } else if (direction == DOWN) {
        changePosition(timeElapsed, DOWN, REFLECTION_LEFT);
        return DOWN;
    }
    return STAND;
}
//=============================================================================
void SmartEnemy::gravity(const float & timeElapsed){
    setInTheAir(true);

    changePosition(timeElapsed, DOWN, REFLECTION_RIGHT);
}
//=============================================================================
void SmartEnemy::handleCollision(GameObject & gameObject, const sf::Vector2f & keyPressed) {
    gameObject.handleCollision(*this, keyPressed);
}
//=============================================================================
void SmartEnemy::handleCollision(Player & player, const sf::Vector2f & keyPressed) {
    player.handleCollision(*this, keyPressed);
}
//=============================================================================