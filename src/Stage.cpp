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
    int timer;
    std::string line;

    m_levelFile >> m_stageSize.x >> m_stageSize.y >> timer;

    m_levelFile.get();

    m_stageDetails.setTimer(timer);
    m_stageDetails.setStageNumber(START_LEVEL);

    for(int row = 0; row < m_stageSize.y; row++)
    {
        getline(m_levelFile,line);
        m_map.push_back(line);

        m_staticObjects.resize(m_stageSize.y);

        for(int col = 0; col < m_stageSize.x; col++)
        {
            switch(m_map[row][col])
            {
                case PLAYER_SYMBOL:
                    m_player = Player(sf::Vector2f(col , row), m_Textures.getPlayerTexture(), m_stageSize);
                    m_player.levelUP();
                    m_player.changeSize();
                    m_staticObjects[row].push_back(nullptr);
                    break;

                case ENEMY_SYMBOL:
                    createEnemy(row, col, m_stageSize);
                    m_enemies[m_enemies.size() - 1]->changeSize();
                    m_staticObjects[row].push_back(nullptr);
                    break;

                case COIN_SYMBOL:
                    m_staticObjects[row].push_back(std::make_unique<Coin>(sf::Vector2f(col, row) , m_Textures.getCoinTexture(), m_stageSize));
                    m_stageDetails.incCoin();
                    break;

                case WALL_SYMBOL:
                    m_staticObjects[row].push_back(std::make_unique<Wall>(sf::Vector2f(col, row) , m_Textures.getWallTexture(), m_stageSize));
                    break;

                case LADDER_SYMBOL:
                    m_staticObjects[row].push_back(std::make_unique<Ladder>(sf::Vector2f(col, row) , m_Textures.getLadderTexture(), m_stageSize));
                    break;

                case POLE_SYMBOL:
                    m_staticObjects[row].push_back(std::make_unique<Pole>(sf::Vector2f(col, row) , m_Textures.getPoleTexture(), m_stageSize));
                    break;

                case GIFT_SYMBOL:
                    createGift(row, col, m_stageSize);
                    break;

                case EMPTY:
                    m_staticObjects[row].push_back(nullptr);
                    break;
            }
        }
    }
}
//=============================================================================
void Stage::createEnemy(const int row, const int col, const sf::Vector2i & stageSize){

    auto enemy = (enum EnemyType_t) (rand() % MOD3);

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
            m_staticObjects[row].push_back(std::make_unique<LiveGift>(sf::Vector2f(col, row) , m_Textures.getGiftTexture(), stageSize));
            break;

        case SCORE_GIFT:
            m_staticObjects[row].push_back(std::make_unique<ScoreGift>(sf::Vector2f(col, row) , m_Textures.getGiftTexture(), stageSize));
            break;

        case TIME_GIFT:
            m_staticObjects[row].push_back(std::make_unique<TimeGift>(sf::Vector2f(col, row) , m_Textures.getGiftTexture(), stageSize));
            break;

        case ENEMY_GIFT:
            m_staticObjects[row].push_back(std::make_unique<EnemyGift>(sf::Vector2f(col, row) , m_Textures.getGiftTexture(), stageSize, *this));
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

    auto arrPosition = sf::Vector2i((movingObject.getPosition().x / WINDOW_WIDTH) * m_stageSize.x,
                                    (movingObject.getPosition().y / WINDOW_HEIGHT) * m_stageSize.y);

    //Checks for collision with nearby static object.
    for(int rowStaticObject = arrPosition.y - 1; rowStaticObject <= arrPosition.y + 1; rowStaticObject++){
        for(int colStaticObject = arrPosition.x - 1; colStaticObject <= arrPosition.x + 1; colStaticObject++){
            if(!m_staticObjects[rowStaticObject][colStaticObject])
                continue;

            if(movingObject.checkCollision(m_staticObjects[rowStaticObject][colStaticObject]->getGlobalBounds())){
                collide = true;
                movingObject.handleCollision(*m_staticObjects[rowStaticObject][colStaticObject], keyPressed);

                if(m_staticObjects[rowStaticObject][colStaticObject]->checkDisposed())
                {
                    m_staticObjects[rowStaticObject][colStaticObject].release();
                }
            }
        }
    }

    //Checks for collision with enemy.
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
    for(int rowStaticObject = 0; rowStaticObject < m_staticObjects.size(); rowStaticObject++)
    {
        for(int colStaticObject = 0; colStaticObject < m_staticObjects[rowStaticObject].size(); colStaticObject++)
        {
            if(m_staticObjects[rowStaticObject][colStaticObject])
            {
               m_staticObjects[rowStaticObject][colStaticObject]->draw(window);
            }
        }
    }
}
//=============================================================================