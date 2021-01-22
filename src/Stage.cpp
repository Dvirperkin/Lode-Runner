#include "Stage.h"

//==========================---Constructor Section---==========================
Stage::Stage() : m_levelFile("Levels.txt"), m_firstRun(true),
                 m_backGround(Textures::texturesObject().getSprite(STAGE_BACKGROUND)),
                 m_graph(std::make_unique<GameGraph>(*this)){

    srand(time(NULL));

    m_backGround.scale(WINDOW_WIDTH / m_backGround.getGlobalBounds().width,
                       WINDOW_HEIGHT / m_backGround.getGlobalBounds().height);

    initializingStage();
    m_graph->initializeData();
}

//========================---Public Function Section---========================
enum ScreenType_t Stage::display(sf::RenderWindow & window) {

    window.clear();
    draw(window);
    m_stageDetails.draw(window, m_player);
    window.display();

    if(!Sound::soundObject().checkMusicPlay(STAGE_MUSIC))
        Sound::soundObject().playMusic(STAGE_MUSIC);

    if(m_firstRun) {
        m_clock.restart().asSeconds();
        m_firstRun = false;
    }

    auto timeElapsed = m_clock.restart().asSeconds();

    if(timeElapsed > TIME_ELAPSED_LIMIT)
        timeElapsed = TIME_ELAPSED_LIMIT;

    m_stageDetails.updateTimer(timeElapsed);

    //Initialize game graph.
    m_graph->initializeData();
    m_graph->BFS(sf::Vector2i((m_player.getPosition().x / WINDOW_WIDTH) * m_stageSize.x,
                              ((m_player.getPosition().y - STAGE_DETAILS_SIZE) / (WINDOW_HEIGHT - STAGE_DETAILS_SIZE)) * m_stageSize.y));

    for (auto event = sf::Event{}; window.pollEvent(event);) {

        if ((event.type == sf::Event::Closed)) {
            m_levelFile.close();
            window.close();
            break;
        }

        else if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)){
            restartGame(window, GAME_OVER_SCREEN, GAME_OVER);
            return MAIN_MENU;
        }
    }
        //Player moves.
        auto keyPressed = m_player.move(timeElapsed);
        m_player.Dig(*this);

        gravity(m_player, keyPressed, timeElapsed, window);

        //Check current situation in the game.
        auto situation = gameSituation(window);

        if(situation != DO_NOTHING)
            return (enum ScreenType_t) situation;

        //Viruses moves.
        for(auto & Virus : m_viruses){
          keyPressed = Virus->move(timeElapsed);

          gravity(*Virus, keyPressed, timeElapsed, window);
        }

    buildBrokenWall(timeElapsed);


    return STAGE;
}
//=============================================================================
void Stage::draw(sf::RenderWindow &window){
    window.draw(m_backGround);
    drawStaticObjects(window);
    drawMovingObject(window);
}
//=============================================================================
void Stage::addVirus() {

    //Get random row and col and place a virus in an empty place.
    for(auto rowStaticObject = rand() % m_staticObjects.size(); rowStaticObject < m_staticObjects.size(); rowStaticObject++){
        for(auto colStaticObject = 0; colStaticObject < m_staticObjects[rowStaticObject].size(); colStaticObject++){

            if(!m_staticObjects[rowStaticObject][colStaticObject]){
                createVirus(rowStaticObject, colStaticObject);

                m_viruses[m_viruses.size() - 1]->setAddedFromGift();
                return;
            }
        }
    }
}
//=============================================================================
void Stage::BreakWall(int staticObjectRow, int staticObjectCol) {

    if (staticObjectRow >= m_staticObjects.size() || staticObjectCol >= m_staticObjects[staticObjectRow].size() ||
        staticObjectCol < 0 || !m_staticObjects[staticObjectRow][staticObjectCol])
        return;

    if (!m_staticObjects[staticObjectRow][staticObjectCol]->checkDisposed() &&
        typeid(*m_staticObjects[staticObjectRow][staticObjectCol]) == typeid(Curtain)) {
        m_staticObjects[staticObjectRow][staticObjectCol]->isDisposed();
        m_openCurtain.push_back(dynamic_cast<Curtain *>(m_staticObjects[staticObjectRow][staticObjectCol].get()));
    }

    Sound::soundObject().playSound(OPEN_CURTAIN);
}
//=============================================================================
sf::Vector2i Stage::getStageSize() const{
    return m_stageSize;
}
//=============================================================================
GameGraph & Stage::getGameGraph(){
    return *m_graph;
}
//=============================================================================
graphStaticObjects_t Stage::getStaticObject(const int &row, const int &col) const {

    if(!m_staticObjects[row][col])
        return NULL_OBJECT;

    if(typeid(*m_staticObjects[row][col]) == typeid(Curtain))
        return CURTAIN_OBJECT;

    if(typeid(*m_staticObjects[row][col]) == typeid(Ladder))
        return LADDER_OBJECT;

    if(typeid(*m_staticObjects[row][col]) == typeid(Rope))
        return ROPE_OBJECT;

    //In case it includes coin, player, virus or gift.
    return NULL_OBJECT;

}
//=============================================================================


//=======================---Private Function Section---========================
void Stage::initializingStage(){
    int timer;
    std::string line;

    //Initialize vectors and coins.
    m_viruses.clear();
    m_openCurtain.clear();
    m_staticObjects.clear();
    m_stageDetails.resetMaxCoin();

    m_levelFile >> m_stageSize.y >> m_stageSize.x >> timer;

    m_levelFile.get();

    m_stageDetails.setTimer(timer);


    for(int row = 0; row < m_stageSize.y; row++)
    {
        getline(m_levelFile,line);

        m_staticObjects.push_back({});

        for(int col = 0; col < m_stageSize.x; col++){
            switch(line[col]){
                case PLAYER_SYMBOL:
                    m_player = Player(sf::Vector2f(col , row), getStageSize());
                    m_player.levelUP();
                    m_stageDetails.setStageNumber(m_player.getLevel());
                    m_player.changeSize(MOVING_FACTOR, MOVING_FACTOR);
                    m_staticObjects[row].push_back(nullptr);
                    break;

                case VIRUS_SYMBOL:
                    createVirus(row, col);
                    m_staticObjects[row].push_back(nullptr);
                    break;

                case VACCINE_SYMBOL:
                    m_staticObjects[row].push_back(std::make_unique<Vaccine>(sf::Vector2f(col, row), getStageSize(), m_stageDetails));
                    m_stageDetails.incCoin();
                    break;

                case CURTAIN_SYMBOL:
                    m_staticObjects[row].push_back(std::make_unique<Curtain>(sf::Vector2f(col, row), getStageSize()));
                    break;

                case LADDER_SYMBOL:
                    m_staticObjects[row].push_back(std::make_unique<Ladder>(sf::Vector2f(col, row), getStageSize()));
                    break;

                case ROPE_SYMBOL:
                    m_staticObjects[row].push_back(std::make_unique<Rope>(sf::Vector2f(col, row), getStageSize()));
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
int Stage::gameSituation(sf::RenderWindow & window) {

    //The stage is complete.
    if(m_stageDetails.getCoin() == 0) {
        Sound::soundObject().stopSound(LOW_TIME);
        Sound::soundObject().playSound(LEVELUP);
        sf::sleep(sf::seconds(LEVELUP_WAITING_TIME));

        //Load next stage.
        if(!m_levelFile.eof()) {
            m_player.levelUP();
            auto PlayerLives = m_player.getLive();
            auto PlayerScore = m_player.getScore();
            auto PlayerLevel = m_player.getLevel();
            initializingStage();
            m_player.setLive(PlayerLives);
            m_player.addScore(PlayerScore);
            m_player.setLevel(PlayerLevel);
            m_stageDetails.setStageNumber(m_player.getLevel());
            return STAGE;
        }

        //The player wins, and returns to the main menu.
        else {
            restartGame(window, WIN_SCREEN, WIN);
            return MAIN_MENU;
        }
    }

    //Time is up.
    if(m_stageDetails.getTimer() == 0)
        m_player.isDisposed();

    if(m_player.checkDisposed()) {

        sf::sleep(sf::seconds(DEAD_WAITING_TIME));
        Sound::soundObject().stopSound(LOW_TIME);

        //If the player disqualified return to the main menu
        //and reloads the first level to start a new game.
        if(m_player.getLive() == 0) {
            restartGame(window, GAME_OVER_SCREEN, GAME_OVER);
            return MAIN_MENU;
        }

        //If the player dead but not disqualified reload the current stage.
        reloadStage();
        return STAGE;
    }

    return DO_NOTHING;
}
//=============================================================================
void Stage::reloadStage() {

    m_player.returnFirstPosition();
    m_player.isDisposed();

    for(auto rowStaticObject = 0; rowStaticObject < m_staticObjects.size(); rowStaticObject++){
        for(auto colStaticObject = 0; colStaticObject < m_staticObjects[rowStaticObject].size(); colStaticObject++){
            if(m_staticObjects[rowStaticObject][colStaticObject]){

                m_staticObjects[rowStaticObject][colStaticObject]->returnFirstPosition();

                //If the current static object was taken return it.
                if(m_staticObjects[rowStaticObject][colStaticObject]->checkDisposed())
                    m_staticObjects[rowStaticObject][colStaticObject]->isDisposed();
            }
        }
    }

    m_openCurtain.clear();

    for(auto currentVirus = 0; currentVirus < m_viruses.size(); currentVirus++) {

        //Checks if the current virus was added from a gift and if so erase him.
        if(m_viruses[currentVirus]->getAddedFromGift()) {
            m_viruses.erase(m_viruses.begin() + currentVirus);
            currentVirus--;
        }

        else
            m_viruses[currentVirus]->returnFirstPosition();
    }

    m_stageDetails.reloadStageDetails();
}
//=============================================================================
void Stage::restartGame(sf::RenderWindow & window, enum Textures_t texture, enum Sounds_t sound) {

    auto sprite = Textures::texturesObject().getSprite(texture);

    sprite.scale(WINDOW_WIDTH / sprite.getGlobalBounds().width,
                 WINDOW_HEIGHT / sprite.getGlobalBounds().height);

    auto scoreString = "Your Score is : " + std::to_string(m_player.getScore());
    auto score = sf::Text(scoreString, Font::FontObject().getFont(), CHAR_SIZE);

    if(texture == WIN_SCREEN) {
        score.setFillColor(sf::Color::Yellow);
        score.setPosition(SCORE_WIN_POSITION);
    }

    else{
        score.setFillColor(sf::Color::White);
        score.setPosition(SCORE_LOSE_POSITION);
    }

    Sound::soundObject().stopMusic(STAGE_MUSIC);

    m_levelFile.seekg(0, std::ios::beg);
    initializingStage();
    reloadStage();

    window.clear();
    window.draw(sprite);
    window.draw(score);
    window.display();
    Sound::soundObject().playSound(sound);
    sf::sleep(sf::seconds(FINISH_WAITING_TIME));
}
//=============================================================================
void Stage::createVirus(const int row, const int col){

    auto virus = (enum VirusType_t) (rand() % MOD3);

    switch(virus)
    {
        case STUPID_VIRUS:
            m_viruses.push_back(std::make_unique<StupidVirus>(sf::Vector2f(col, row), getStageSize()));
            break;

        case RAND_VIRUS:
            m_viruses.push_back(std::make_unique<RandVirus>(sf::Vector2f(col, row), getStageSize()));
            break;

        case SMART_VIRUS:
            m_viruses.push_back(std::make_unique<SmartVirus>(sf::Vector2f(col, row), *this));
            break;
    }

   m_viruses[m_viruses.size() - 1]->changeSize(MOVING_FACTOR, MOVING_FACTOR);
}
//=============================================================================
void Stage::createGift(const int row, const int col){

    auto gift = (enum GiftType_t) (rand() % MOD4);

    switch(gift)
    {
        case LIVE_GIFT:
            m_staticObjects[row].push_back(std::make_unique<LiveGift>(sf::Vector2f(col, row), getStageSize(), m_player));
            break;

        case SCORE_GIFT:
            m_staticObjects[row].push_back(std::make_unique<ScoreGift>(sf::Vector2f(col, row), getStageSize(), m_player));
            break;

        case TIME_GIFT:
            m_staticObjects[row].push_back(std::make_unique<TimeGift>(sf::Vector2f(col, row), getStageSize(), m_stageDetails));
            break;

        case VIRUS_GIFT:
            m_staticObjects[row].push_back(std::make_unique<VirusGift>(sf::Vector2f(col, row), getStageSize(), *this));
            break;
    }
}
//=============================================================================
void Stage::buildBrokenWall(float elapsedTime) {

    for(auto index = 0; index < m_openCurtain.size(); index++)
    {
        if(m_openCurtain[index]) {
            m_openCurtain[index]->reduceTime(elapsedTime);

            if(m_openCurtain[index]->getDisposedTime() <= 0) {
                m_openCurtain[index]->isDisposed();
                m_openCurtain.erase(m_openCurtain.begin() + index);
            }
        }
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

    auto collide = false;

    //Calculate the player place in the array.
    auto arrPosition = sf::Vector2i((movingObject.getPosition().x / WINDOW_WIDTH) * m_stageSize.x,
                                    ((movingObject.getPosition().y - STAGE_DETAILS_SIZE) / (WINDOW_HEIGHT - STAGE_DETAILS_SIZE)) * m_stageSize.y);

    //Checks for collision with nearby static object.
    for(auto rowStaticObject = arrPosition.y - 1; rowStaticObject <= arrPosition.y + 1; rowStaticObject++) {
        for (auto colStaticObject = arrPosition.x - 1; colStaticObject <= arrPosition.x + 1; colStaticObject++) {

            //Prevents exiting array boundaries.
            if (rowStaticObject >= 0 && rowStaticObject < m_staticObjects.size() && colStaticObject >= 0 &&
                colStaticObject < m_staticObjects[rowStaticObject].size()) {

                //Condition for disposed objects or empty slots.
                if (!m_staticObjects[rowStaticObject][colStaticObject] ||
                    (m_staticObjects[rowStaticObject][colStaticObject]->checkDisposed() &&
                    typeid(*m_staticObjects[rowStaticObject][colStaticObject]) != typeid(Curtain)))
                    continue;

                //Checks if there is a collision between the moving object to the current static object.
                if (movingObject.checkCollision(m_staticObjects[rowStaticObject][colStaticObject]->getGlobalBounds())) {
                    collide = true;

                    movingObject.handleCollision(*m_staticObjects[rowStaticObject][colStaticObject], keyPressed);
                }

                //Check if the player is in a disappear wall.
                if(!m_player.getOnLadder() && !m_player.getOnPole() &&
                   m_staticObjects[rowStaticObject][colStaticObject]->checkDisposed() &&
                    typeid(*m_staticObjects[rowStaticObject][colStaticObject]) == typeid(Curtain) &&
                    typeid(movingObject) == typeid(Player))
                    collide = false;
            }
        }
    }

    //Checks for collision between player to virus.
    if(typeid(movingObject) == typeid(Player)){
        for(auto & virus : m_viruses){
            if(movingObject.checkCollision(virus->getGlobalBounds())){
                movingObject.handleCollision(*virus, keyPressed);

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

    for(int index = 0; index < m_viruses.size(); index++)
        m_viruses[index]->draw(window);
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