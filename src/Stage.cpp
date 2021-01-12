#include "Stage.h"

//=======================---Constructor Section---============================
Stage::Stage() : m_levelFile("Levels.txt"), m_firstRun(true)
{
    srand(time(NULL));
    initializingStage();
}
//=======================---Public Function Section---========================
enum ScreenType_t Stage::display(sf::RenderWindow & window) {

    window.clear();
    draw(window);
    window.display();

    //Music();

    if(m_firstRun) {
        m_clock.restart().asSeconds();
        m_firstRun = false;
    }

    auto elapsed = m_clock.restart().asSeconds();

    //elapsed = 0.02;

    for (auto event = sf::Event{}; window.pollEvent(event);) {

        if ((event.type == sf::Event::Closed) ||
            (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)) {
            m_levelFile.close();
            window.close();
            break;
        }
    }

        //Player move.
        auto keyPressed = m_player.move(elapsed);

        gravity(m_player, keyPressed, elapsed);

        //Enemies moves.
        for(auto & enemy : m_enemies){
          keyPressed = enemy->move(elapsed);

          gravity(*enemy, keyPressed, elapsed);
        }

        return STAGE;
}
//=============================================================================
void Stage::draw(sf::RenderWindow &window)
{
    drawStaticObjects(window);
    drawEnemies(window);
    drawPlayer(window);
}
//=============================================================================
void Stage::Music() {
    if (m_backGroundMusic.getStatus() != m_backGroundMusic.Playing) {
        if (!m_backGroundMusic.openFromFile("StageMusic.ogg"))
            exit(EXIT_FAILURE);

        m_backGroundMusic.setLoop(true);
        m_backGroundMusic.play();
    }
}
//=======================---Private Function Section---========================
void Stage::initializingStage()
{
    sf::Vector2i stageSize;
    int timer;
    std::string line;

    m_levelFile >> stageSize.x >> stageSize.y >> timer;

    m_levelFile.get();

    for(int row = 0; row < stageSize.y; row++)
    {
        getline(m_levelFile,line);
        m_map.push_back(line);

        for(int col = 0; col < stageSize.x; col++)
        {
            switch(m_map[row][col])
            {
                case PLAYER_SYMBOL:
                    m_player = Player(sf::Vector2f(col , row), m_Textures.getPlayerTexture(), stageSize);
                    m_player.initPosition(row, col, stageSize);
                    m_player.levelUP();
                    m_player.changeSize();
                    break;

                case ENEMY_SYMBOL:
                    createEnemy(row, col, stageSize);
                    m_enemies[m_enemies.size() - 1]->initPosition(row, col, stageSize);
                    m_enemies[m_enemies.size() - 1]->changeSize();
                    break;

                case COIN_SYMBOL:
                    m_staticObjects.push_back(std::make_unique<Coin>(sf::Vector2f(col, row) , m_Textures.getCoinTexture(), stageSize));
                    m_stageDetails.incCoin();
                    break;

                case WALL_SYMBOL:
                    m_staticObjects.push_back(std::make_unique<Wall>(sf::Vector2f(col, row) , m_Textures.getWallTexture(), stageSize));
                    break;

                case LADDER_SYMBOL:
                    m_staticObjects.push_back(std::make_unique<Ladder>(sf::Vector2f(col, row) , m_Textures.getLadderTexture(), stageSize));
                    break;

                case POLE_SYMBOL:
                    m_staticObjects.push_back(std::make_unique<Pole>(sf::Vector2f(col, row) , m_Textures.getPoleTexture(), stageSize));
                    break;

                case GIFT_SYMBOL:
                    createGift(row, col, stageSize);
                    break;
            }
            if(m_map[row][col] != PLAYER_SYMBOL && m_map[row][col] != ENEMY_SYMBOL && m_map[row][col] != EMPTY)
                m_staticObjects[m_staticObjects.size() - 1]->initPosition(row, col, stageSize);
        }
    }
}
//=============================================================================
void Stage::createEnemy(const int row, const int col, const sf::Vector2i & stageSize){

    auto enemy = (enum EnemyType_t) (rand() % MOD3);

    enemy = RAND_ENEMY;


    switch(enemy)
    {
        case STUPID_ENEMY:
            m_enemies.push_back(std::make_unique<StupidEnemy>(sf::Vector2f(col, row) , m_Textures.getEnemyTexture(), stageSize));
            break;

        case RAND_ENEMY:
            m_enemies.push_back(std::make_unique<RandEnemy>(sf::Vector2f(col, row) , m_Textures.getEnemyTexture(), stageSize));
            break;

        case SMART_ENEMY:
            m_enemies.push_back(std::make_unique<SmartEnemy>(sf::Vector2f(col, row) , m_Textures.getEnemyTexture(), stageSize));
            break;
    }
}
//=============================================================================
void Stage::createGift(const int row, const int col, const sf::Vector2i & stageSize){

    auto gift = (enum GiftType_t) (rand() % MOD4);

    switch(gift)
    {
        case LIVE_GIFT:
            m_staticObjects.push_back(std::make_unique<LiveGift>(sf::Vector2f(col, row) , m_Textures.getGiftTexture(), stageSize));
            break;

        case SCORE_GIFT:
            m_staticObjects.push_back(std::make_unique<ScoreGift>(sf::Vector2f(col, row) , m_Textures.getGiftTexture(), stageSize));
            break;

        case TIME_GIFT:
            m_staticObjects.push_back(std::make_unique<TimeGift>(sf::Vector2f(col, row) , m_Textures.getGiftTexture(), stageSize));
            break;

        case ENEMY_GIFT:
            m_staticObjects.push_back(std::make_unique<EnemyGift>(sf::Vector2f(col, row) , m_Textures.getGiftTexture(), stageSize));
            break;
    }
}
//=============================================================================
void Stage::gravity(MovingObject & movingObject ,const sf::Vector2f & keyPressed, const float & timeElapsed) {

    if(!handleCollision(movingObject, keyPressed))
    {
        movingObject.gravity(timeElapsed);
    }

    handleCollision(movingObject, keyPressed);
}
//=============================================================================
bool Stage::handleCollision(MovingObject & movingObject, const sf::Vector2f & keyPressed) {

    bool collide = false;

    for(auto & staticObject : m_staticObjects){
        if(movingObject.checkCollision(staticObject->getGlobalBounds())){
            collide = true;
            movingObject.handleCollision(*staticObject, keyPressed);
        }
    }

    std::experimental::erase_if(m_staticObjects, [](auto& staticObject){
        return staticObject->checkDisposed();
    });

    for(auto & enemy : m_enemies){
        if(movingObject.checkCollision(enemy->getGlobalBounds())){
            movingObject.handleCollision(*enemy, keyPressed);

            /*if(m_player.checkDisposed())
            {
                std::cout << "Fail" << std::endl;
            }*/
        }
    }

    return collide;
}
//=============================================================================
void Stage::drawEnemies(sf::RenderWindow &window) const
{
    for(int index = 0; index < m_enemies.size(); index++)
        m_enemies[index]->draw(window);
}
//=============================================================================
void Stage::drawPlayer(sf::RenderWindow &window) const
{
    m_player.draw(window);
}
//=============================================================================
void Stage::drawStaticObjects(sf::RenderWindow &window) const
{
    for(int index = 0; index < m_staticObjects.size(); index++)
        m_staticObjects[index]->draw(window);

}
//=============================================================================