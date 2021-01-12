#pragma once
#include <SFML/Graphics.hpp>

class StageDetails {
public:
    StageDetails() = default;
    StageDetails(sf::Vector2i &, int &, int &);
    void draw() const;
    void setTimer();
    void incCoin();
    void decCoin();

private:
    int m_stageNumber;
    sf::Clock m_timer;
    int m_coin;
};