#pragma once

#include <SFML/Audio.hpp>
#include <memory>
#include "Macros.h"


class Sounds {

public:
    Sounds();
    const sf::SoundBuffer & getCollisionEnemySound () const;
    const sf::SoundBuffer & getCollisionCoinSound () const;
    const sf::SoundBuffer & getCantMoveSound () const;
    const sf::SoundBuffer & getFinishedLevelSound () const;
    const sf::SoundBuffer & getLowTimeSound () const;

private:
    std::vector<std::unique_ptr<std::string>> m_music;
    std::vector<sf::SoundBuffer> m_sounds;
};