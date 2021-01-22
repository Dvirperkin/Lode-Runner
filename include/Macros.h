#pragma once

//--------------------Enum Section--------------------
enum ScreenType_t {MAIN_MENU, STAGE, EXIT};

enum Textures_t {PLAYER, STUPID_VIRUS_TEXT, RAND_VIRUS_TEXT, SMART_VIRUS_TEXT, CURTAIN, VACCINE, LADDER,
    POLE, GIFT, STAGE_DETAILS, STAGE_BACKGROUND, MENU_BACKGROUND, WIN_SCREEN, GAME_OVER_SCREEN};

enum Sounds_t {WIN, GAME_OVER, LEVELUP, VIRUS_COLLISION, VACCINE_SOUND, LOW_TIME, OPEN_CURTAIN,
               LIVE_GIFT_SOUND, SCORE_GIFT_SOUND, TIME_GIFT_SOUND, VIRUS_GIFT_SOUND};

enum Music_t {MAIN_MENU_MUSIC, STAGE_MUSIC};

enum VirusType_t {STUPID_VIRUS, RAND_VIRUS, SMART_VIRUS};

enum GiftType_t {LIVE_GIFT, SCORE_GIFT, TIME_GIFT, VIRUS_GIFT};

//for BFS algorithm.
enum graphStaticObjects_t {LADDER_OBJECT , ROPE_OBJECT , NULL_OBJECT , CURTAIN_OBJECT};

//--------------------Integers Section--------------------

//Screen Resolution.
const int WINDOW_HEIGHT = 1080;
const int WINDOW_WIDTH = 1920;

//Menu Button.
const int MENU_BUTTON_WIDTH = WINDOW_WIDTH / 3;
const int MENU_BUTTON_HEIGHT = 100;
const int GRAY = 100;
const int MENU_BUTTON_CHAR_SIZE = 70;
const int THICKNESS = 7;
const int NUM_BUTTONS = 2;
const int NO_THICKNESS = 0;

//Game Bar.
const int STAGE_DETAILS_SIZE = 50;
const int NUM_OF_DETAILS = 4;
const int TIME_DETAIL = 3;
const int LEVEL_DETAIL = 2;
const int SCORE_DETAIL = 1;
const int LIVE_DETAIL = 0;
const int MINUTE = 60;
const int HOUR = 60;
const int NO_TIME = -1;

//Resources.
const int NUM_OF_TEXTURES = 14;
const int NUM_OF_SOUNDS = 11;
const int NUM_OF_MUSICS = 2;

//Level UP and gift score.
const int GIFT_SCORE = 100;
const int LEVEL_SCORE = 50;
const int COIN_SCORE = 2;
const int ADD_TIME = 10;

//Virus movement.
const int VIRUS_UP = 0;
const int VIRUS_DOWN = 1;
const int VIRUS_LEFT = 2;
const int VIRUS_RIGHT = 3;

//BFS algorithm.
const int NO_PREDECESSOR = -1;
const int NO_NEIGHBOR = -1;
const int NEIGHBOR_UP = 0;
const int NEIGHBOR_DOWN = 1;
const int NEIGHBOR_RIGHT = 2;
const int NEIGHBOR_LEFT = 3;
const int MAX_NEIGHBORS = 4;

const int MOD4 = 4;
const int MOD3 = 3;
const int LIVE = 3;

const int FRAME_LIMIT = 60;
const int STAGE_SIZE_FACTOR = 60;
const int CHAR_SIZE = 50;
const int VOLUME = 20;
const int DO_NOTHING = -1;
const int OFFSET_Y = 5;

const int FINISH_WAITING_TIME = 10;
const int LEVELUP_WAITING_TIME = 2;
const int DEAD_WAITING_TIME = 2;

//--------------------Floats Section--------------------
const float TIME_ELAPSED_LIMIT = 0.05;
const float CURTAIN_DISPOSED_TIME = 5;
const float MOVING_FACTOR = 0.8;
const float SMALL_TIME_LIMIT = 0.4f;
const float BIG_TIME_LIMIT = 1.4f;
const auto SPEED_PER_SECOND = 200.f;

//--------------------Characters Section--------------------
const char EMPTY = ' ';
const char PLAYER_SYMBOL = '@';
const char VIRUS_SYMBOL = '%';
const char VACCINE_SYMBOL = '*';
const char CURTAIN_SYMBOL = '#';
const char LADDER_SYMBOL = 'H';
const char ROPE_SYMBOL = '-';
const char GIFT_SYMBOL = '+';

//--------------------Vector2f Section--------------------
const sf::Vector2f LEFT = {-1 , 0};
const sf::Vector2f RIGHT = {1 , 0};
const sf::Vector2f UP = {0 , -1};
const sf::Vector2f DOWN = {0 , 1};
const sf::Vector2f STAND = {0 , 0};
const sf::Vector2f REFLECTION_LEFT = {-1 , 1};
const sf::Vector2f REFLECTION_RIGHT = {1 , 1};
const sf::Vector2f REFLECTION_UP = {1 , 1};
const sf::Vector2f REFLECTION_DOWN = {1 , 1};
const sf::Vector2f SCORE_WIN_POSITION = {WINDOW_WIDTH / 2, (WINDOW_HEIGHT / 4) * 3};
const sf::Vector2f SCORE_LOSE_POSITION = {WINDOW_WIDTH / 2, (WINDOW_HEIGHT / 5) * 4};