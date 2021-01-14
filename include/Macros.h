#pragma once

enum ScreenType_t {MAIN_MENU, STAGE, STAGE_CONSTRUCTION, EXIT};
enum Sounds_t {COLLISION_ENEMY, COLLISION_COIN, CANT_MOVE, FINISHED_LEVEL, LOW_TIME};
enum Textures_t {PLAYER, ENEMY, WALL, COIN, LADDER, POLE, GIFT};
enum EnemyType_t {STUPID_ENEMY, RAND_ENEMY, SMART_ENEMY};
enum GiftType_t {LIVE_GIFT, SCORE_GIFT, TIME_GIFT, ENEMY_GIFT};

const int WINDOW_HEIGHT = 1000;
const int WINDOW_WIDTH = 1850;
const int MENU_BUTTON_HEIGHT = 100;
const int GRAY = 100;
const int MENU_BUTTON_WIDTH = WINDOW_WIDTH / 3;
const int NUM_OF_TEXTURES = 7;
const int NUM_OF_SOUNDS = 5;
const int THICKNESS = 7;
const int START_LEVEL = 1;
const int MOD3 = 3;
const int MOD4 = 4;
const int LIVE = 3;
const int COIN_SCORE = 2;
const int LEVEL_SCORE = 50;
const int GIFT_SCORE = 100;
const int ADD_TIME = 10;
const int FIRST_ENEMY = 1;

const float TIME_ELAPSED_LIMIT = 0.05;

const char EMPTY = ' ';
const char PLAYER_SYMBOL = '@';
const char ENEMY_SYMBOL = '%';
const char COIN_SYMBOL = '*';
const char WALL_SYMBOL = '#';
const char LADDER_SYMBOL = 'H';
const char POLE_SYMBOL = '-';
const char GIFT_SYMBOL = '+';


const int ENEMY_UP = 0;
const int ENEMY_DOWN = 1;
const int ENEMY_LEFT = 2;
const int ENEMY_RIGHT = 3;

const auto SPEED_PER_SECOND = 300.f;
const sf::Vector2f LEFT = {-1 , 0};
const sf::Vector2f RIGHT = {1 , 0};
const sf::Vector2f UP = {0 , -1};
const sf::Vector2f DOWN = {0 , 1};
const sf::Vector2f STAND = {0 , 0};
const sf::Vector2f REFLECTION_LEFT = {-1 , 1};
const sf::Vector2f REFLECTION_RIGHT = {1 , 1};
const sf::Vector2f REFLECTION_UP = {1 , 1};
const sf::Vector2f REFLECTION_DOWN = {1 , 1};