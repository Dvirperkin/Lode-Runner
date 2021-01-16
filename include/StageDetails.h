#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"

class StageDetails {
public:
    StageDetails();
    void draw(sf::RenderWindow &) const;
    void reloadStageDetails();

    int getCoin() const;

    void setStageNumber(const int);
    void setTimer(const int);

    void incCoin();
    void decCoin();
    void resetMaxCoin();
    void addTime();

private:
    sf::RectangleShape m_stageDetails;
    int m_startCountDown;
    int m_stageNumber;
    int m_countDown;
    int m_maxCoin;
    int m_coin;
};