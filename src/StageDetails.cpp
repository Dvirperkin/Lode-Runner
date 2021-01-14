#include "StageDetails.h"

StageDetails::StageDetails()
 :  m_coin(0), m_stageNumber(0), m_countDown(0){
}
//===========================================================================
void StageDetails::draw() const {

}
//===========================================================================
void StageDetails::setStageNumber(const int stageNumber) {
    if(stageNumber > 0)
        m_stageNumber = stageNumber;
}
//===========================================================================
void StageDetails::setTimer(const int timer) {
    m_countDown = timer;
}
//===========================================================================
void StageDetails::incCoin() {
    m_coin++;
}
//===========================================================================
void StageDetails::decCoin() {
    m_coin--;
}
//===========================================================================
void StageDetails::addTime() {
    m_countDown += ADD_TIME;
}
//===========================================================================