#pragma once

#include <fstream>
#include <string>

#include "GameGraph.h"
#include "StageDetails.h"
#include "Screen.h"
#include "Player.h"
#include "StupidVirus.h"
#include "RandVirus.h"
#include "SmartVirus.h"
#include "Vaccine.h"
#include "Curtain.h"
#include "Rope.h"
#include "Ladder.h"
#include "LiveGift.h"
#include "ScoreGift.h"
#include "TimeGift.h"
#include "VirusGift.h"

class Stage : public Screen{
public:
    //--------------------Constructor/Destructor Section--------------------
    Stage();

    //--------------------Virtual Function Section--------------------
    virtual enum ScreenType_t display(sf::RenderWindow &) override;
    virtual void draw(sf::RenderWindow &) override;

    //--------------------Action Function Section--------------------
    void addVirus();
    void BreakWall(int, int);

    //--------------------Get Section--------------------
    sf::Vector2i getStageSize() const;
    GameGraph & getGameGraph ();
    graphStaticObjects_t getStaticObject (const int & , const int &) const;

private:
    std::vector<std::vector<std::unique_ptr<StaticObject>>> m_staticObjects;
    std::vector<std::unique_ptr<Virus>> m_viruses;
    std::vector<Curtain *> m_openCurtain;
    std::unique_ptr<GameGraph> m_graph;
    StageDetails m_stageDetails;
    std::fstream m_levelFile;
    sf::Vector2i m_stageSize;
    sf::Clock m_clock;
    Player m_player;
    bool m_firstRun;

    sf::Sprite m_backGround;

    void initializingStage();
    int gameSituation(sf::RenderWindow &);
    void reloadStage();
    void restartGame(sf::RenderWindow &, enum Textures_t texture, enum Sounds_t);
    void createVirus(const int, const int);
    void createGift(const int, const int);
    void buildBrokenWall(float);
    void gravity(MovingObject &, const sf::Vector2f &, const float &, const sf::RenderWindow &);
    bool handleCollision(MovingObject &, const sf::Vector2f &, const sf::RenderWindow &);
    void drawMovingObject(sf::RenderWindow &) const;
    void drawStaticObjects(sf::RenderWindow &) const;
};