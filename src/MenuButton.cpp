#include "MenuButton.h"

MenuButton::MenuButton(int position, std::string text)
    : m_frame({MENU_BUTTON_WIDTH , MENU_BUTTON_HEIGHT}), m_buttonText(text, Font::FontObject().getFont()){

    m_frame.setPosition(MENU_BUTTON_WIDTH, ((WINDOW_HEIGHT / 3) + (MENU_BUTTON_HEIGHT * position) + (50 * position)));
    m_frame.setOutlineColor({GRAY, GRAY, GRAY});
    m_frame.setFillColor(sf::Color::Transparent);

    m_buttonText.setCharacterSize(MENU_BUTTON_CHAR_SIZE);
    m_buttonText.setOrigin(m_buttonText.getGlobalBounds().width / 2, m_buttonText.getGlobalBounds().height / 2);
    m_buttonText.setPosition(getPosition().x + getGlobalBound().width / 2,
                                    getPosition().y + getGlobalBound().height / 2 - CHAR_SIZE / 3);
    m_buttonText.setFillColor(sf::Color::Black);
    m_buttonText.setOutlineColor(sf::Color::White);
    m_buttonText.setOutlineThickness(THICKNESS);
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
    window.draw(m_buttonText);
}
//=============================================================================
void MenuButton::setOutlineThickness(int thickness) {
    m_frame.setOutlineThickness(thickness);
}
//=============================================================================
sf::Vector2f MenuButton::getPosition() const{
    return m_frame.getPosition();
}
//=============================================================================
sf::FloatRect MenuButton::getGlobalBound() const {
    return m_frame.getGlobalBounds();
}
//=============================================================================