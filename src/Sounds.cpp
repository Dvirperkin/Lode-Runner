#include "Sounds.h"

Sounds::Sounds()
{
    m_sounds.resize(NUM_OF_SOUNDS);

    m_sounds[COLLISION_ENEMY].loadFromFile("aa");
    m_sounds[COLLISION_COIN].loadFromFile("bb");
    m_sounds[CANT_MOVE].loadFromFile("cc");
    m_sounds[FINISHED_LEVEL].loadFromFile("dd");
    m_sounds[LOW_TIME].loadFromFile("ee");


    m_music.push_back(std::make_unique<std::string>("Main Menu music"));
    m_music.push_back(std::make_unique<std::string>("Stage music"));
    m_music.push_back(std::make_unique<std::string>("Stage Construction music"));
}
//=============================================================================
const sf::SoundBuffer &Sounds::getCollisionEnemySound() const
{
    return m_sounds[COLLISION_ENEMY];
}
//=============================================================================
const sf::SoundBuffer &Sounds::getCollisionCoinSound() const
{
    return m_sounds[COLLISION_COIN];
}
//=============================================================================
const sf::SoundBuffer &Sounds::getCantMoveSound() const
{
    return m_sounds[CANT_MOVE];
}
//=============================================================================
const sf::SoundBuffer &Sounds::getFinishedLevelSound() const
{
    return m_sounds[FINISHED_LEVEL];
}
//=============================================================================
const sf::SoundBuffer &Sounds::getLowTimeSound() const
{
    return m_sounds[LOW_TIME];
}
//=============================================================================