#include "SmartVirus.h"
#include "Stage.h"

SmartVirus::SmartVirus(const sf::Vector2f & location, Stage & stage)
 : Virus(location, SMART_VIRUS_TEXT, stage.getStageSize()), m_stage(&stage), m_firstRun(true), m_time(0)
 {
     m_timeLimit = (m_stage->getStageSize().x + m_stage->getStageSize().y > STAGE_SIZE_FACTOR ? SMALL_TIME_LIMIT : BIG_TIME_LIMIT);
 }
//=============================================================================
sf::Vector2f SmartVirus::move(const float &timeElapsed){

    m_time += timeElapsed;

    //Set the last array position.
    auto lastArrPosition =  sf::Vector2i((getLastPosition().x / WINDOW_WIDTH) * m_stage->getStageSize().x ,
                                         ((getLastPosition().y - STAGE_DETAILS_SIZE) / (WINDOW_HEIGHT - STAGE_DETAILS_SIZE)) * m_stage->getStageSize().y);
    //Set the current array position.
    auto currentArrPosition = sf::Vector2i((getPosition().x / WINDOW_WIDTH) * m_stage->getStageSize().x ,
                                           ((getPosition().y - STAGE_DETAILS_SIZE) / (WINDOW_HEIGHT - STAGE_DETAILS_SIZE)) * m_stage->getStageSize().y);
    m_currPair = {lastArrPosition, currentArrPosition};

    //Use to set the last directionAndObj (enemy last position and enemy current position).
    if (m_firstRun) {
        m_lastPair = m_currPair;
        m_firstRun = false;
    }

    std::pair<sf::Vector2f , graphStaticObjects_t> directionAndObj = m_stage->getGameGraph().getDirectionAndObj(getPosition());

    auto direction = directionAndObj.first;
    auto object = directionAndObj.second;

    //The enemy managed to move.
    if (m_currPair != m_lastPair) {
        m_lastPair = m_currPair;
        m_time = 0;
    }

    //The enemy did not manage to move - got stuck.
    else if (m_currPair == m_lastPair && (m_time > m_timeLimit)){

        //On the air (trying to get down).
        if (object == NULL_OBJECT) {
            //Check if on the left bottom diagonal there is a curtain if so - it need to move right.
            if (m_stage->getGameGraph().getObjectInPosition({currentArrPosition.x - 1, currentArrPosition.y + 1}) == CURTAIN_OBJECT) {
                changePosition(timeElapsed, RIGHT, REFLECTION_UP);
                return RIGHT;
            }

            //Check if on the right bottom diagonal there is a curtain if so - it need to move left.
            if (m_stage->getGameGraph().getObjectInPosition({currentArrPosition.x + 1, currentArrPosition.y + 1}) == CURTAIN_OBJECT)
            {
                changePosition(timeElapsed, LEFT, REFLECTION_UP);
                return LEFT;
            }
        }

        else if (object == LADDER_OBJECT) {
            //If on the left/right bottom diagonal there is a wall if so - it's need to go up.
            if (m_stage->getGameGraph().getObjectInPosition({currentArrPosition.x - 1, currentArrPosition.y + 1}) == CURTAIN_OBJECT
                || m_stage->getGameGraph().getObjectInPosition({currentArrPosition.x + 1, currentArrPosition.y + 1}) == CURTAIN_OBJECT) {
                //If on the left/right diagonal has well then it's going up.
                changePosition(timeElapsed, UP, REFLECTION_UP);
                return UP;
            }

            else {
                changePosition(timeElapsed, DOWN, REFLECTION_UP);
                return DOWN;
            }
        }
    }

    //If not stuck.
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
void SmartVirus::gravity(const float & timeElapsed){
    setInTheAir(true);

    changePosition(timeElapsed, DOWN, REFLECTION_RIGHT);
}
//=============================================================================
void SmartVirus::handleCollision(GameObject & gameObject, const sf::Vector2f & keyPressed) {
    gameObject.handleCollision(*this, keyPressed);
}
//=============================================================================
void SmartVirus::handleCollision(Player & player, const sf::Vector2f & keyPressed) {
    player.handleCollision(*this, keyPressed);
}
//=============================================================================