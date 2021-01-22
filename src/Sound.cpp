#include "Sound.h"

Sound::Sound(){
    m_soundBuffer.resize(NUM_OF_SOUNDS);
    m_sounds.resize(NUM_OF_SOUNDS);
    m_musics.resize(NUM_OF_MUSICS);

    //---Load Musics Section---

    m_musics[MAIN_MENU_MUSIC] = std::make_unique<sf::Music>();
    m_musics[MAIN_MENU_MUSIC]->openFromFile("MainMenuMusic.ogg");
    m_musics[MAIN_MENU_MUSIC]->setLoop(true);

    m_musics[STAGE_MUSIC] = std::make_unique<sf::Music>();
    m_musics[STAGE_MUSIC]->openFromFile("StageMusic.ogg");
    m_musics[STAGE_MUSIC]->setLoop(true);

    //---Load Sounds Section---

    m_soundBuffer[WIN].loadFromFile("Victory.ogg");
    m_sounds[WIN].setBuffer(m_soundBuffer[WIN]);

    m_soundBuffer[GAME_OVER].loadFromFile("GameOver.ogg");
    m_sounds[GAME_OVER].setBuffer(m_soundBuffer[GAME_OVER]);

    m_soundBuffer[LEVELUP].loadFromFile("LevelUp.ogg");
    m_sounds[LEVELUP].setBuffer(m_soundBuffer[LEVELUP]);

    m_soundBuffer[VIRUS_COLLISION].loadFromFile("VirusCollision.ogg");
    m_sounds[VIRUS_COLLISION].setBuffer(m_soundBuffer[VIRUS_COLLISION]);

    m_soundBuffer[VACCINE_SOUND].loadFromFile("SyringeSound.ogg");
    m_sounds[VACCINE_SOUND].setBuffer(m_soundBuffer[VACCINE_SOUND]);

    m_soundBuffer[LOW_TIME].loadFromFile("LowTime.ogg");
    m_sounds[LOW_TIME].setBuffer(m_soundBuffer[LOW_TIME]);

    m_soundBuffer[OPEN_CURTAIN].loadFromFile("CurtainOpen.ogg");
    m_sounds[OPEN_CURTAIN].setBuffer(m_soundBuffer[OPEN_CURTAIN]);

    m_soundBuffer[LIVE_GIFT_SOUND].loadFromFile("LiveGift.ogg");
    m_sounds[LIVE_GIFT_SOUND].setBuffer(m_soundBuffer[LIVE_GIFT_SOUND]);

    m_soundBuffer[SCORE_GIFT_SOUND].loadFromFile("ScoreGift.ogg");
    m_sounds[SCORE_GIFT_SOUND].setBuffer(m_soundBuffer[SCORE_GIFT_SOUND]);

    m_soundBuffer[TIME_GIFT_SOUND].loadFromFile("TimeGift.ogg");
    m_sounds[TIME_GIFT_SOUND].setBuffer(m_soundBuffer[TIME_GIFT_SOUND]);

    m_soundBuffer[VIRUS_GIFT_SOUND].loadFromFile("VirusGift.ogg");
    m_sounds[VIRUS_GIFT_SOUND].setBuffer(m_soundBuffer[VIRUS_GIFT_SOUND]);
}
//=============================================================================
Sound &Sound::soundObject() {
    static Sound soundObject;

    return soundObject;
}
//=============================================================================
void Sound::playSound(enum Sounds_t sound){
    m_sounds[sound].play();
    m_sounds[sound].setVolume(VOLUME * 2);
}
//=============================================================================
void Sound::stopSound(enum Sounds_t sound) {
    if(checkSoundPlay(sound))
        m_sounds[sound].stop();
}
//=============================================================================
bool Sound::checkSoundPlay(enum Sounds_t sound) {

    if(m_sounds[sound].getStatus() == m_sounds[sound].Playing)
        return true;

    return false;
}
//=============================================================================
void Sound::playMusic(enum Music_t music) {
    m_musics[music]->play();
    m_musics[music]->setVolume(VOLUME);

}
//=============================================================================
void Sound::stopMusic(enum Music_t music) {
    m_musics[music]->stop();
}
//=============================================================================
bool Sound::checkMusicPlay(enum Music_t music) {

    if(m_musics[music]->getStatus() == m_musics[music]->Playing)
        return true;

    return false;
}
//=============================================================================
