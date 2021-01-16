#include "StageDetails.h"
#include "Player.h"
#include "iostream"

StageDetails::StageDetails()
 :  m_stageDetails({WINDOW_WIDTH, STAGE_DETAILS_SIZE}), m_coin(0), m_maxCoin(0), m_stageNumber(0), m_countDown(0){
    m_stageDetails.setFillColor({GRAY, GRAY, GRAY});
}
//===========================================================================
void StageDetails::draw(sf::RenderWindow & window) const {
    window.draw(m_stageDetails);
}
//===========================================================================
void StageDetails::reloadStageDetails() {
    m_countDown = m_startCountDown;
    m_coin = m_maxCoin;
}
//===========================================================================
int StageDetails::getCoin() const{
    return m_coin;
}
//===========================================================================
void StageDetails::setStageNumber(const int stageNumber) {
    if(stageNumber > 0)
        m_stageNumber = stageNumber;
}
//===========================================================================
void StageDetails::setTimer(const int timer) {
    if (timer >= 0) {
        m_startCountDown = timer;
        m_countDown = timer;
    }
}
//===========================================================================
void StageDetails::incCoin() {
    m_coin++;
    m_maxCoin++;
}
//===========================================================================
void StageDetails::decCoin() {
    m_coin--;
}
//===========================================================================
void StageDetails::resetMaxCoin() {
    m_maxCoin = 0;
}
//===========================================================================
void StageDetails::addTime() {
    m_countDown += ADD_TIME;
}
//===========================================================================