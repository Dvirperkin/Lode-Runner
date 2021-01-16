#include "Stage.h"

//=======================---Constructor Section---============================
Stage::Stage() : m_levelFile("Levels.txt"), m_firstRun(true){
    srand(time(NULL));
    initializingStage();
}
//=======================---Public Function Section---========================
enum ScreenType_t Stage::display(sf::RenderWindow & window) {

    window.clear();
    m_stageDetails.draw(window);
    draw(window);
    window.display();

    //Music();

    if(m_firstRun) {
        m_clock.restart().asSeconds();
        m_firstRun = false;
    }

    auto timeElapsed = m_clock.restart().asSeconds();

    if(timeElapsed > TIME_ELAPSED_LIMIT)
        timeElapsed = TIME_ELAPSED_LIMIT;

    for (auto event = sf::Event{}; window.pollEvent(event);) {

        if ((event.type == sf::Event::Closed) ||
            (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)) {
            m_levelFile.close();
            window.close();
            break;
        }
    }

        //Player moves.
        auto keyPressed = m_player.move(timeElapsed);

        gravity(m_player, keyPressed, timeElapsed, window);


        //Check current situation in the game.
        auto situation = gameSituation();

        if(situation != DO_NOTHING)
            return (enum ScreenType_t) situation;

        //Enemies moves.
        for(auto & enemy : m_enemies){
          keyPressed = enemy->move(timeElapsed);

          gravity(*enemy, keyPressed, timeElapsed, window);
        }

        return STAGE;
}
//=============================================================================
void Stage::draw(sf::RenderWindow &window){
    drawStaticObjects(window);
    drawMovingObject(window);
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
int Stage::gameSituation() {

    //The stage is complete.
    if(m_stageDetails.getCoin() == 0) {
        //Load next stage.
        if(!m_levelFile.eof()) {
            m_player.levelUP();
            auto PlayerLives = m_player.getLive();
            auto PlayerScore = m_player.getScore();
            auto PlayerLevel = m_player.getLevel();
            initializingStage();
            m_player.setLives(PlayerLives);
            m_player.addScore(PlayerScore);
            m_player.setLevel(PlayerLevel);
            return STAGE;
        }

        //The player wins, and returns to the main menu.
        else {
            m_levelFile.seekg(0, std::ios::beg);
            initializingStage();
            reloadStage();
            return MAIN_MENU;
        }
    }

    if(m_player.checkDisposed()) {
        //If the player disqualified return to the main menu
        //and reloads the first level to start a new game.
        if(m_player.getLive() == 0) {
            m_levelFile.seekg(0, std::ios::beg);
            initializingStage();
            reloadStage();
            return MAIN_MENU;
        }

        //If the player dead but not disqualified reload the current stage.
        reloadStage();
        return STAGE;
    }

    return -1;
}
//=============================================================================
void Stage::initializingStage(){
    int timer;
    std::string line;

    //Initialize vectors and coins.
    m_map.clear();
    m_enemies.clear();
    m_staticObjects.clear();
    m_stageDetails.resetMaxCoin();

    m_levelFile >> m_stageSize.x >> m_stageSize.y >> timer;

    m_levelFile.get();

    m_stageDetails.setTimer(timer);
    m_stageDetails.setStageNumber(START_LEVEL);

    for(int row = 0; row < m_stageSize.y; row++)
    {
        getline(m_levelFile,line);
        m_map.push_back(line);

        m_staticObjects.push_back({});

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
                    createEnemy(row, col);
                    m_staticObjects[row].push_back(nullptr);
                    break;

                case COIN_SYMBOL:
                    m_staticObjects[row].push_back(std::make_unique<Coin>(sf::Vector2f(col, row) , m_Textures.getCoinTexture(), m_stageSize, m_stageDetails));
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
                    createGift(row, col);
                    break;

                case EMPTY:
                    m_staticObjects[row].push_back(nullptr);
                    break;
            }
        }
    }
}
//=============================================================================
void Stage::reloadStage() {

    m_player.setFirstPosition();
    m_player.isDisposed();

    for(auto rowStaticObject = 0; rowStaticObject < m_staticObjects.size(); rowStaticObject++){
        for(auto colStaticObject = 0; colStaticObject < m_staticObjects[rowStaticObject].size(); colStaticObject++){
            if(m_staticObjects[rowStaticObject][colStaticObject])
            {
                m_staticObjects[rowStaticObject][colStaticObject]->setFirstPosition();

                //If the current static object was taken return it.
                if(m_staticObjects[rowStaticObject][colStaticObject]->checkDisposed())
                    m_staticObjects[rowStaticObject][colStaticObject]->isDisposed();
            }
        }
    }

    for(auto currentEnemy = 0; currentEnemy < m_enemies.size(); currentEnemy++) {

        //Checks if the current enemy was added from a gift and if so erase him.
        if(m_enemies[currentEnemy]->getAddedFromGift()) {
            m_enemies.erase(m_enemies.begin() + currentEnemy);
            currentEnemy--;
        }

        m_enemies[currentEnemy]->setFirstPosition();
    }

    m_stageDetails.reloadStageDetails();
}
//=============================================================================
void Stage::createEnemy(const int row, const int col){

    auto enemy = (enum EnemyType_t) (rand() % MOD3);

    switch(enemy)
    {
        case STUPID_ENEMY:
            m_enemies.push_back(std::make_unique<StupidEnemy>(sf::Vector2f(col, row) , m_Textures.getEnemyTexture(), m_stageSize));
            break;

        case RAND_ENEMY:
            m_enemies.push_back(std::make_unique<RandEnemy>(sf::Vector2f(col, row) , m_Textures.getEnemyTexture(), m_stageSize));
            break;

        case SMART_ENEMY:
            m_enemies.push_back(std::make_unique<SmartEnemy>(sf::Vector2f(col, row) , m_Textures.getEnemyTexture(), m_stageSize));
            break;
    }

    m_enemies[m_enemies.size() - 1]->changeSize();
}
//=============================================================================
void Stage::addEnemy() {

    for(auto rowStaticObject = rand() % m_staticObjects.size(); rowStaticObject < m_staticObjects.size(); rowStaticObject++){
        for(auto colStaticObject = 0; colStaticObject < m_staticObjects[rowStaticObject].size(); colStaticObject++){
            if(!m_staticObjects[rowStaticObject][colStaticObject])
            {
                createEnemy(rowStaticObject, colStaticObject);
                m_enemies[m_enemies.size() - 1]->setAddedFromGift();
                return;
            }
        }
    }
}
//=============================================================================
void Stage::createGift(const int row, const int col){

    auto gift = (enum GiftType_t) (rand() % MOD4);

    gift = LIVE_GIFT;

    switch(gift)
    {
        case LIVE_GIFT:
            m_staticObjects[row].push_back(std::make_unique<LiveGift>(sf::Vector2f(col, row) , m_Textures.getGiftTexture(), m_stageSize, m_player));
            break;

        case SCORE_GIFT:
            m_staticObjects[row].push_back(std::make_unique<ScoreGift>(sf::Vector2f(col, row) , m_Textures.getGiftTexture(), m_stageSize, m_player));
            break;

        case TIME_GIFT:
            m_staticObjects[row].push_back(std::make_unique<TimeGift>(sf::Vector2f(col, row) , m_Textures.getGiftTexture(), m_stageSize, m_stageDetails));
            break;

        case ENEMY_GIFT:
            m_staticObjects[row].push_back(std::make_unique<EnemyGift>(sf::Vector2f(col, row) , m_Textures.getGiftTexture(), m_stageSize, *this));
            break;
    }
}
//=============================================================================
void Stage::gravity(MovingObject & movingObject ,const sf::Vector2f & keyPressed, const float & timeElapsed , const sf::RenderWindow & window) {

    if(!handleCollision(movingObject, keyPressed, window) || movingObject.getInTheAir()){
        movingObject.gravity(timeElapsed);
    }

    if(m_player.checkDisposed())
        return;

    handleCollision(movingObject, keyPressed, window);
}
//=============================================================================
bool Stage::handleCollision(MovingObject & movingObject, const sf::Vector2f & keyPressed, const sf::RenderWindow & window) {

    bool collide = false;

    auto arrPosition = sf::Vector2i((movingObject.getPosition().x / WINDOW_WIDTH) * m_stageSize.x,
                                    (movingObject.getPosition().y / WINDOW_HEIGHT) * m_stageSize.y);

    //Checks for collision with nearby static object.
    for(auto rowStaticObject = arrPosition.y - 1; rowStaticObject <= arrPosition.y + 1; rowStaticObject++) {
        for (auto colStaticObject = arrPosition.x - 1; colStaticObject <= arrPosition.x + 1; colStaticObject++) {

            if (rowStaticObject >= 0 && rowStaticObject < m_staticObjects.size() && colStaticObject >= 0 &&
                colStaticObject < m_staticObjects[rowStaticObject].size()) {

                if (!m_staticObjects[rowStaticObject][colStaticObject] || m_staticObjects[rowStaticObject][colStaticObject]->checkDisposed())
                    continue;

                if (movingObject.checkCollision(m_staticObjects[rowStaticObject][colStaticObject]->getGlobalBounds())) {
                    collide = true;

                    movingObject.handleCollision(*m_staticObjects[rowStaticObject][colStaticObject], keyPressed);
                }
            }
        }
    }

    //Checks for collision between player to enemy.
    if(typeid(movingObject) == typeid(Player)){
        for(auto & enemy : m_enemies){
            if(movingObject.checkCollision(enemy->getGlobalBounds())){
                movingObject.handleCollision(*enemy, keyPressed);

                if(m_player.checkDisposed())
                    return true;
            }
        }
    }

    return collide;
}
//=============================================================================
void Stage::drawMovingObject(sf::RenderWindow & window) const{

    m_player.draw(window);

    for(int index = 0; index < m_enemies.size(); index++)
        m_enemies[index]->draw(window);
}
//=============================================================================
void Stage::drawStaticObjects(sf::RenderWindow &window) const{
    for(int rowStaticObject = 0; rowStaticObject < m_staticObjects.size(); rowStaticObject++){
        for(int colStaticObject = 0; colStaticObject < m_staticObjects[rowStaticObject].size(); colStaticObject++){
            if(m_staticObjects[rowStaticObject][colStaticObject] && !(m_staticObjects[rowStaticObject][colStaticObject]->checkDisposed())){
               m_staticObjects[rowStaticObject][colStaticObject]->draw(window);
            }
        }
    }
}
//=============================================================================