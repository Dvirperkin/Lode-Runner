#include "StageDetails.h"
#include "Player.h"
#include <string>

StageDetails::StageDetails() : m_coin(0), m_maxCoin(0), m_stageNumber(0), m_countDown(0){

    m_backGround = Textures::texturesObject().getSprite(STAGE_DETAILS);
    m_backGround.scale(WINDOW_WIDTH / m_backGround.getGlobalBounds().width,
                          STAGE_DETAILS_SIZE / m_backGround.getGlobalBounds().height);

    for(auto index = 0; index < NUM_OF_DETAILS; index++){
        m_details.push_back(sf::Text("", Font::FontObject().getFont()));
        m_details[index].setFillColor(sf::Color::White);
        m_details[index].setCharacterSize(40);
    }
}
//===========================================================================
void StageDetails::draw(sf::RenderWindow & window, Player & player) {

    window.draw(m_backGround);
    drawLive(window, player);
    drawScore(window, player);
    drawLevel(window);

    if(m_countDown > 0)
        drawTime(window);
}
//===========================================================================
void StageDetails::drawLive(sf::RenderWindow &window, Player & player) {

    std::string liveString;

    liveString += "Live : ";
    liveString += std::to_string(player.getLive());
    m_details[LIVE_DETAIL].setString(liveString);

    m_details[LIVE_DETAIL].setOrigin(m_details[LIVE_DETAIL].getGlobalBounds().width / 2, m_details[LIVE_DETAIL].getGlobalBounds().height / 2);

    auto x = (WINDOW_WIDTH / NUM_OF_DETAILS) * LIVE_DETAIL + (WINDOW_WIDTH / NUM_OF_DETAILS) / 2;

    m_details[LIVE_DETAIL].setPosition(x , STAGE_DETAILS_SIZE / 4);

    window.draw(m_details[LIVE_DETAIL]);
}
//===========================================================================
void StageDetails::drawScore(sf::RenderWindow & window, Player & player) {

    std::string scoreString;

    scoreString += "Score : ";
    scoreString += std::to_string(player.getScore());
    m_details[SCORE_DETAIL].setString(scoreString);

    m_details[SCORE_DETAIL].setOrigin(m_details[SCORE_DETAIL].getGlobalBounds().width / 2, m_details[SCORE_DETAIL].getGlobalBounds().height / 2);


    auto x = (WINDOW_WIDTH / NUM_OF_DETAILS) * SCORE_DETAIL + (WINDOW_WIDTH / NUM_OF_DETAILS) / 2;
    m_details[SCORE_DETAIL].setPosition(x ,STAGE_DETAILS_SIZE / 4);

    window.draw(m_details[SCORE_DETAIL]);
}
//===========================================================================
void StageDetails::drawLevel(sf::RenderWindow & window) {

    std::string levelString;

    levelString += "Stage : ";

    levelString += std::to_string(m_stageNumber);

    m_details[LEVEL_DETAIL].setString(levelString);

    m_details[LEVEL_DETAIL].setOrigin(m_details[LEVEL_DETAIL].getGlobalBounds().width / 2, m_details[LEVEL_DETAIL].getGlobalBounds().height / 2);

    auto x = (WINDOW_WIDTH / NUM_OF_DETAILS) * LEVEL_DETAIL + (WINDOW_WIDTH / NUM_OF_DETAILS) / 2;
    m_details[LEVEL_DETAIL].setPosition(x ,STAGE_DETAILS_SIZE / 4);

    window.draw(m_details[LEVEL_DETAIL]);
}
//===========================================================================
void StageDetails::drawTime(sf::RenderWindow & window) {

    std::string timeString;

    timeString += "Time Left : ";
    timeString += std::to_string(m_countDown / HOUR);
    timeString += ":";

    if(m_countDown % MINUTE < 10)
        timeString += "0";

    timeString += std::to_string(m_countDown % MINUTE);

    m_details[TIME_DETAIL].setString(timeString);

    m_details[TIME_DETAIL].setOrigin(m_details[TIME_DETAIL].getGlobalBounds().width / 2, m_details[TIME_DETAIL].getGlobalBounds().height / 2);

    auto x = (WINDOW_WIDTH / NUM_OF_DETAILS) * TIME_DETAIL + (WINDOW_WIDTH / NUM_OF_DETAILS) / 2;
    m_details[TIME_DETAIL].setPosition(x ,STAGE_DETAILS_SIZE / 4);

    if(m_countDown < 10) {
        if(!Sound::soundObject().checkSoundPlay(LOW_TIME))
            Sound::soundObject().playSound(LOW_TIME);

        m_details[TIME_DETAIL].setFillColor(sf::Color::Red);

    }
    else
        m_details[TIME_DETAIL].setFillColor(sf::Color::White);

    window.draw(m_details[TIME_DETAIL]);
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
int StageDetails::getTimer() const{
    return m_countDown;
}
//===========================================================================
void StageDetails::setStageNumber(const int stageNumber) {
    if(stageNumber > 0)
        m_stageNumber = stageNumber;
}
//===========================================================================
void StageDetails::setTimer(const int timer) {
    m_startCountDown = timer;
    m_countDown = timer;
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
    if(m_countDown > NO_TIME)
        m_countDown += ADD_TIME;
}
//===========================================================================
void StageDetails::updateTimer(float elapsedTime) {

    second -= elapsedTime;
    if(second <= 0) {
        m_countDown--;
        second = 1;
    }
}
//===========================================================================