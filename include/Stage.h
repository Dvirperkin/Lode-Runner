#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <experimental/vector>
#include "GameGraph.h"
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

    void addEnemy();
    void BreakWall(int, int);

    sf::Vector2i getStageSize() const;

    GameGraph & getGameGraph ();
    graphStaticObjects_t getStaticObject (const int & , const int &) const;

private:
    StageDetails m_stageDetails;
    std::fstream m_levelFile;
    sf::Sprite m_backGround;
    Player m_player;
    std::vector<std::unique_ptr<Enemy>> m_enemies;
    std::vector<std::vector<std::unique_ptr<StaticObject>>> m_staticObjects;
    std::vector<Wall *> m_brokenWall;
    sf::Vector2i m_stageSize;
    sf::Clock m_clock;
    bool m_firstRun;
    std::unique_ptr<GameGraph> m_graph;
    sf::Sprite m_winScreen;

    int gameSituation(sf::RenderWindow &);
    void initializingStage();
    void reloadStage();
    void restartGame(sf::RenderWindow &, sf::Sprite &, enum Sounds_t);
    void createEnemy(const int, const int);
    void createGift(const int, const int);
    void buildBrokenWall(float);
    void gravity(MovingObject &, const sf::Vector2f &, const float &, const sf::RenderWindow &);
    bool handleCollision(MovingObject &, const sf::Vector2f &, const sf::RenderWindow &);
    void drawMovingObject(sf::RenderWindow &) const;
    void drawStaticObjects(sf::RenderWindow &) const;
};