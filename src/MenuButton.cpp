#include "MenuButton.h"

MenuButton::MenuButton(int position) : m_frame({MENU_BUTTON_WIDTH , MENU_BUTTON_HEIGHT}){

    m_frame.setPosition(MENU_BUTTON_WIDTH, ((WINDOW_HEIGHT / 3) + (MENU_BUTTON_HEIGHT * position) + (50 * position)));
    m_frame.setOutlineColor({GRAY, GRAY, GRAY});
}
//=============================================================================
bool MenuButton::checkPressed(const sf::Vector2f &location) {

    if(m_frame.getGlobalBounds().contains(location))
        return true;

    return false;
}
//=============================================================================
void MenuButton::draw(sf::RenderWindow & window) {
    window.draw(m_frame);
}
//=============================================================================
void MenuButton::setOutlineThickness(int thickness) {
    m_frame.setOutlineThickness(thickness);
}
//=============================================================================