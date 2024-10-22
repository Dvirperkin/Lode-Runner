#include "GameController.h"

GameController::GameController() : m_currentScreen(MAIN_MENU){

    m_screens.push_back(std::make_unique<MainMenu>());
    m_screens.push_back(std::make_unique<Stage>());
}
//=============================================================================
void GameController::Run() {

    auto window = sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Lode Runner", sf::Style::Fullscreen);
    window.setFramerateLimit(FRAME_LIMIT);

    while(window.isOpen())
    {
        switch(m_currentScreen){
            case MAIN_MENU:
                m_currentScreen = m_screens[MAIN_MENU]->display(window);
                break;

            case STAGE:
                m_currentScreen = m_screens[STAGE]->display(window);
                break;

            case EXIT:
                window.close();
                break;
        }
    }
}
//=============================================================================