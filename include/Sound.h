#pragma once

#include <SFML/Audio.hpp>
#include <memory>
#include "Macros.h"


class Sound {

public:
    static Sound & soundObject();
    void playSound(enum Sounds_t);
    void stopSound(enum Sounds_t);
    bool checkSoundPlay(enum Sounds_t);

    void playMusic(enum Music_t);
    void stopMusic(enum Music_t);
    bool checkMusicPlay(enum Music_t);

private:
    //--------------------Constructor/Destructor Section--------------------
    Sound();
    Sound(const Sound &) = default;
    Sound & operator=(const Sound &) = default;


    std::vector<sf::SoundBuffer> m_soundBuffer;
    std::vector<sf::Sound> m_sounds;
    std::vector<std::unique_ptr<sf::Music>> m_musics;
};