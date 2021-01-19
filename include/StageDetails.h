#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Macros.h"
#include "Font.h"
#include "Textures.h"

class Player;

class StageDetails {
public:
    StageDetails();
    void draw(sf::RenderWindow &, Player &);
    void reloadStageDetails();

    int getCoin() const;
    int getTimer() const;
    void setStageNumber(const int);
    void setTimer(const int);

    void incCoin();
    void decCoin();
    void resetMaxCoin();
    void addTime();
    void updateTimer(float);

private:
    sf::Sprite m_backGround;
    std::vector<sf::Text> m_details;
    int m_startCountDown;
    int m_stageNumber;
    int m_countDown;
    int m_maxCoin;
    int m_coin;
    float second = 1;

    void drawLive(sf::RenderWindow &, Player &);
    void drawScore(sf::RenderWindow &, Player &);
    void drawTime(sf::RenderWindow &);
    void drawLevel(sf::RenderWindow &);
};