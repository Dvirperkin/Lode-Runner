#pragma once
#include "Window.h"

class StageConstruction : public Window{
public:
    StageConstruction();
    virtual enum ScreenType_t display(sf::RenderWindow &) override;
    virtual void draw(sf::RenderWindow &) override;
    virtual void Music() override;
};