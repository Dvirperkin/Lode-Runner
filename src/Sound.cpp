#include "Sound.h"

Sound::Sound()
{
    m_soundBuffer.resize(NUM_OF_SOUNDS);
    m_sounds.resize(NUM_OF_SOUNDS);

    m_soundBuffer[COLLISION_COIN].loadFromFile("SyringeSound.ogg");
    m_sounds[COLLISION_COIN].setBuffer(m_soundBuffer[COLLISION_COIN]);

}
//=============================================================================
Sound &Sound::soundObject() {
    static Sound soundObject;

    return soundObject;
}
//=============================================================================
void Sound::play(enum Sounds_t sound){
    m_sounds[sound].play();
}
//=============================================================================
