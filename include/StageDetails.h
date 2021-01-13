#pragma once
#include <SFML/Graphics.hpp>

class StageDetails {
public:
    StageDetails();
    void draw() const;
    void setStageNumber(const int);
    void setTimer(const int);
    void incCoin();
    void decCoin();

private:
    int m_stageNumber;
    sf::Clock m_timer;
    int m_coin;
};