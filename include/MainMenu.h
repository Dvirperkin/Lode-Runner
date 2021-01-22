#pragma once
#include "Screen.h"
#include "MenuButton.h"


class MainMenu : public Screen {
public:
    //--------------------Constructor/Destructor Section--------------------
    MainMenu();

    //--------------------Virtual Function Section--------------------
    virtual enum ScreenType_t display(sf::RenderWindow &) override;
    virtual void draw(sf::RenderWindow &) override;

private:
    std::vector<MenuButton> m_menuButton;
    int m_lastRectangleBold;
    sf::Text m_title;
    sf::Text m_subTitle;
    sf::Sprite m_backGround;

    void handleMouseMove(sf::RenderWindow & , const sf::Vector2f & );
};