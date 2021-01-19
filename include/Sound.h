#pragma once

#include <SFML/Audio.hpp>
#include <memory>
#include "Macros.h"


class Sound {

public:
    static Sound & soundObject();
    void play(enum Sounds_t);

private:
    Sound();
    Sound(const Sound &) = default;
    Sound & operator=(const Sound &) = default;


    std::vector<sf::SoundBuffer> m_soundBuffer;
    std::vector<sf::Sound> m_sounds;
};