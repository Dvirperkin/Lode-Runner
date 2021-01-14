#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"

class StageDetails {
public:
    StageDetails();
    void draw() const;
    void setStageNumber(const int);
    void setTimer(const int);
    void incCoin();
    void decCoin();
    void addTime();

private:
    int m_stageNumber;
    int m_countDown;
    int m_coin;
};