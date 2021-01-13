#pragma once
#include "Window.h"
#include "MenuButton.h"

class MainMenu : public Window {
public:
    MainMenu();
    virtual enum ScreenType_t display(sf::RenderWindow &) override;
    virtual void draw(sf::RenderWindow &) override;
    virtual void Music() override;

private:
    std::vector<MenuButton> m_menu;
    int m_lastRectangleBold;
    sf::Music m_backGroundMusic;

    void handleMouseMove(sf::RenderWindow & Window, const sf::Vector2f & location);
};