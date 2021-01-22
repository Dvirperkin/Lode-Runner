#include "MainMenu.h"

MainMenu::MainMenu() :  m_lastRectangleBold(DO_NOTHING),
                        m_title("Lode Runner",Font::FontObject().getFont()),
                        m_subTitle("(Corona Virus Version)",Font::FontObject().getFont()),
                        m_backGround(Textures::texturesObject().getSprite(MENU_BACKGROUND))
{
    //Initializes the background
    m_backGround.scale(WINDOW_WIDTH / m_backGround.getGlobalBounds().width,
                       WINDOW_HEIGHT / m_backGround.getGlobalBounds().height);

    //Initializes the title
    m_title.setCharacterSize(CHAR_SIZE * 2);
    m_title.setFillColor(sf::Color::White);
    m_title.setPosition(WINDOW_WIDTH / 2 ,WINDOW_HEIGHT / m_title.getGlobalBounds().height * 5);
    m_title.setOrigin(m_title.getGlobalBounds().width / 2, m_title.getGlobalBounds().height / 2);


    //Initializes the sub - title.
    m_subTitle.setCharacterSize(CHAR_SIZE);
    m_subTitle.setFillColor(sf::Color::White);
    m_subTitle.setOrigin(m_subTitle.getGlobalBounds().width / 2, m_subTitle.getGlobalBounds().height / 2);
    m_subTitle.setPosition(WINDOW_WIDTH / 2 ,
                           m_title.getGlobalBounds().top + m_title.getGlobalBounds().height + m_subTitle.getGlobalBounds().height);


    //Initializes menu buttons.
   for(int index = 0; index < NUM_BUTTONS; index++) {
       switch(index){

           case 0:
               m_menuButton.push_back(MenuButton(index, "New Game"));
               break;

           case 1:
               m_menuButton.push_back(MenuButton(index, "Exit"));
               break;
       }
   }
}
//=============================================================================
enum ScreenType_t MainMenu::display(sf::RenderWindow & window) {

    window.clear();
    draw(window);
    window.display();

    if(!Sound::soundObject().checkMusicPlay(MAIN_MENU_MUSIC))
        Sound::soundObject().playMusic(MAIN_MENU_MUSIC);

    if (auto event = sf::Event{}; window.waitEvent(event))
        switch (event.type)
        {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::MouseButtonPressed:
                if(event.mouseButton.button == sf::Mouse::Left){
                    for(int index = 0; index < NUM_BUTTONS; index++){
                        if(m_menuButton[index].checkPressed(window.mapPixelToCoords({event.mouseButton.x , event.mouseButton.y}))) {
                            Sound::soundObject().stopMusic(MAIN_MENU_MUSIC);
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

    window.draw(m_backGround);
    window.draw(m_title);
    window.draw(m_subTitle);

    for(int index = 0; index < NUM_BUTTONS; index++) {
        m_menuButton[index].draw(window);
    }
}
//=============================================================================
void MainMenu::handleMouseMove(sf::RenderWindow &window, const sf::Vector2f &location) {

    for (int index = 0; index < m_menuButton.size(); index++)
        {
            if (m_menuButton[index].checkPressed(location))
            {
                //Check if the mouse moved to another rectangle.
                if (index != m_lastRectangleBold)
                {
                    m_menuButton[index].setOutlineThickness(THICKNESS);

                    if(m_lastRectangleBold != DO_NOTHING) {
                        m_menuButton[m_lastRectangleBold].setOutlineThickness(0);
                        m_menuButton[m_lastRectangleBold].draw(window);
                    }
                    m_lastRectangleBold = index;
                }
                return;
            }
        }

    if(m_lastRectangleBold != DO_NOTHING) {
        m_menuButton[m_lastRectangleBold].setOutlineThickness(NO_THICKNESS);
    }
    m_lastRectangleBold = DO_NOTHING;

}
//=============================================================================