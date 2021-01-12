#include "StageDetails.h"

StageDetails::StageDetails(sf::Vector2i & stageSize, int & timer, int & coin)
 :  m_coin(0), m_stageNumber(0){

}
//===========================================================================
void StageDetails::draw() const {

}
//===========================================================================
void StageDetails::setTimer() {

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