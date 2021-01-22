#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Macros.h"
#include "Textures.h"
#include "Font.h"
#include "Sound.h"

class Player;

class StageDetails {
public:
    //--------------------Constructor/Destructor Section--------------------
    StageDetails();

    //--------------------Action Function Section--------------------
    void draw(sf::RenderWindow &, Player &);
    void reloadStageDetails();
    void incCoin();
    void decCoin();
    void resetMaxCoin();
    void addTime();
    void updateTimer(float);

    //--------------------Get Function Section--------------------
    int getCoin() const;
    int getTimer() const;

    //--------------------Set Function Section--------------------
    void setStageNumber(const int);
    void setTimer(const int);

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