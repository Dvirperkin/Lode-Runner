#include "Textures.h"

Textures::Textures()
{
    m_textures.resize(NUM_OF_TEXTURES);

    m_textures[PLAYER].loadFromFile("Player.png");
    m_textures[STUPID_VIRUS_TEXT].loadFromFile("StupidVirus.png");
    m_textures[RAND_VIRUS_TEXT].loadFromFile("RandVirus.png");
    m_textures[SMART_VIRUS_TEXT].loadFromFile("SmartVirus.png");
    m_textures[CURTAIN].loadFromFile("Curtain.png");
    m_textures[VACCINE].loadFromFile("Vaccine.png");
    m_textures[LADDER].loadFromFile("Ladder.png");
    m_textures[POLE].loadFromFile("Rope.png");
    m_textures[GIFT].loadFromFile("Gift.png");
    m_textures[STAGE_DETAILS].loadFromFile("StageDetails.jpg");
    m_textures[STAGE_BACKGROUND].loadFromFile("StageBackGround.png");
    m_textures[MENU_BACKGROUND].loadFromFile("MenuBackGround.png");
    m_textures[WIN_SCREEN].loadFromFile("WinScreen.png");
    m_textures[GAME_OVER_SCREEN].loadFromFile("GameOver.jpeg");
}
//=======================================================================
Textures & Textures::texturesObject(){
    static Textures texturesObject;

    return texturesObject;
}
//=======================================================================
const sf::Sprite Textures::getSprite(enum Textures_t image) {
    return sf::Sprite(m_textures[image]);
}
//=======================================================================