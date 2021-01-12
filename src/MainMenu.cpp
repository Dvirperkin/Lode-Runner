#include "MainMenu.h"

MainMenu::MainMenu() : m_lastRectangleBold(-1){

   for(int index = 0; index < 3; index++)
      m_menu.push_back(MenuButton(index));
}
//=============================================================================
enum ScreenType_t MainMenu::display(sf::RenderWindow & window) {

    window.clear();
    draw(window);
    window.display();

    //Music();

    if (auto event = sf::Event{}; window.waitEvent(event))
        switch (event.type)
        {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::MouseButtonPressed:
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    for(int index = 0; index < 3; index++)
                    {
                        if(m_menu[index].checkPressed(window.mapPixelToCoords({event.mouseButton.x , event.mouseButton.y}))) {
                            m_backGroundMusic.stop();
                            return (enum ScreenType_t) (index + 1);
                        }
                    }
                }
                break;

            case sf::Event::MouseMoved:
                handleMouseMove(window, window.mapPixelToCoords({event.mouseMove.x, event.mouseMove.y}));
                break;
        }

    return MAIN_MENU;
}
//=============================================================================
void MainMenu::draw(sf::RenderWindow & window) {
    for(int index = 0; index < 3; index++)
        m_menu[index].draw(window);
}
//=============================================================================
void MainMenu::handleMouseMove(sf::RenderWindow &window, const sf::Vector2f &location) {

    for (int index = 0; index < m_menu.size(); index++)
        {
            if (m_menu[index].checkPressed(location))
            {
                //Check if the mouse moved to another rectangle.
                if (index != m_lastRectangleBold)
                {
                    m_menu[index].setOutlineThickness(THICKNESS);

                    if(m_lastRectangleBold != -1) {
                        m_menu[m_lastRectangleBold].setOutlineThickness(0);
                        m_menu[m_lastRectangleBold].draw(window);
                    }
                    m_lastRectangleBold = index;
                }
                return;
            }
        }
    if(m_lastRectangleBold != -1) {
        m_menu[m_lastRectangleBold].setOutlineThickness(0);
    }
    m_lastRectangleBold = -1;

}
//=============================================================================
void MainMenu::Music() {
    if(m_backGroundMusic.getStatus() != m_backGroundMusic.Playing) {
        if(!m_backGroundMusic.openFromFile("MainMenuMusic.ogg"))
            exit(EXIT_FAILURE);

        m_backGroundMusic.setLoop(true);
        m_backGroundMusic.play();
    }
}
//=============================================================================































