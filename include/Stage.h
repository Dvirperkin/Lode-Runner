#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <experimental/vector>
#include "Window.h"
#include "Player.h"
#include "StupidEnemy.h"
#include "RandEnemy.h"
#include "SmartEnemy.h"
#include "Coin.h"
#include "Wall.h"
#include "Pole.h"
#include "Ladder.h"
#include "LiveGift.h"
#include "ScoreGift.h"
#include "TimeGift.h"
#include "EnemyGift.h"
#include "StageDetails.h"
#include "Textures.h"

class Stage : public Window{
public:
    Stage();
    virtual enum ScreenType_t display(sf::RenderWindow &) override;
    virtual void draw(sf::RenderWindow &) override;
    virtual void Music() override;

private:
    StageDetails m_stageDetails;
    std::fstream m_levelFile;
    sf::Music m_backGroundMusic;
    Player m_player;
    std::vector<std::unique_ptr<Enemy>> m_enemies;
    std::vector<std::string> m_map;
    std::vector<std::unique_ptr<StaticObject>> m_staticObjects;
    sf::Vector2i m_stageSize;
    sf::Clock m_clock;
    Textures m_Textures;
    bool m_firstRun;

    void initializingStage();
    void createEnemy(const int, const int, const sf::Vector2i &);
    void createGift(const int, const int, const sf::Vector2i &);
    void gravity(MovingObject &, const sf::Vector2f &, const float &);
    bool handleCollision(MovingObject &, const sf::Vector2f &);
    void drawEnemies(sf::RenderWindow &) const;
    void drawPlayer(sf::RenderWindow &) const;
    void drawStaticObjects(sf::RenderWindow &) const;
};