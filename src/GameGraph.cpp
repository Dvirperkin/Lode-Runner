#include "GameGraph.h"
#include "Stage.h"
#include <cmath>

GameGraph::GameGraph(Stage &stage) : m_stage(&stage) {
}
//=============================================================================
void GameGraph::initializeData()
{
    m_graph.clear();

    //Initialize graph size.
    m_graph.resize(m_stage->getStageSize().x * m_stage->getStageSize().y);

    //Initialize NodesData.
    initializeGraph();

    //Add neighbors.
    addNeighbors();

}
//=============================================================================
void GameGraph::initializeGraph() {

    for(int row = 0; row < m_stage->getStageSize().y; row++)
        for(int col = 0; col < m_stage->getStageSize().x; col++)
        {
            auto currentObject = m_stage->getStaticObject(row , col);

            int node = convertCellToNode(row , col);

            if(currentObject == NULL_OBJECT)
                m_graph[node]._repObject = NULL_OBJECT;

            if(currentObject == CURTAIN_OBJECT) {
                m_graph[node]._isNode = false;
                m_graph[node]._repObject = CURTAIN_OBJECT;
            }

            if(currentObject == LADDER_OBJECT)
                m_graph[node]._repObject = LADDER_OBJECT;

            if(currentObject == ROPE_OBJECT)
                m_graph[node]._repObject = ROPE_OBJECT;

        }
}
//=============================================================================
void GameGraph::addNeighbors()
{
    for (int node = 0; node < m_graph.size(); node++) {

        //In case the current node can be a part of the path (not a wall)
        if (m_graph[node]._isNode) {

            //In case the current node is a NULL_OBJECT and the object under is a NULL_OBJECT as well, The direction can be only down(in the air).
            if (m_graph[node]._repObject == NULL_OBJECT && m_graph[node + m_stage->getStageSize().x]._repObject == NULL_OBJECT)
                m_graph[node + m_stage->getStageSize().x]._neighbors[NEIGHBOR_UP] = node;

                //In case of a NULL and under there is a none NULL_OBJECT (Might be able to go to the sides).
            else {
                //In case the object under is a node (not a curtain) the direction is down.
                if (m_graph[node + m_stage->getStageSize().x]._isNode)
                    m_graph[node + m_stage->getStageSize().x]._neighbors[NEIGHBOR_UP] = node;

                //In case the object on the left is a node (not a curtain) the direction is left.
                if (m_graph[node - 1]._isNode)
                    m_graph[node - 1]._neighbors[NEIGHBOR_RIGHT] = node;

                //In case the object on the right is a node (not a curtain) the direction is right.
                if (m_graph[node + 1]._isNode)
                    m_graph[node + 1]._neighbors[NEIGHBOR_LEFT] = node;
            }

            //In case the current node is a Ladder, the direction is up.
            if (m_graph[node]._repObject == LADDER_OBJECT && m_graph[node - m_stage->getStageSize().x]._isNode)
                m_graph[node - m_stage->getStageSize().x]._neighbors[NEIGHBOR_DOWN] = node;
        }
    }
}
//=============================================================================
void GameGraph::BFS(const sf::Vector2i &playerPosition)
{
    auto sourceNode = convertCellToNode(playerPosition.y , playerPosition.x);

    //In case the player dig and fell under the last row of curtains.
    if(sourceNode > m_stage->getStageSize().x * m_stage->getStageSize().y)
        return;

    m_graph[sourceNode]._distance = 0;
    m_graph[sourceNode]._visited = true;

    std::queue<int> queue;

    queue.push(sourceNode);

    while(!queue.empty())
    {
        int currentNode = queue.front();
        queue.pop();

        for(int neighbor = 0; neighbor < MAX_NEIGHBORS; neighbor++)
            if(m_graph[currentNode]._neighbors[neighbor] != -1 && !m_graph[m_graph[currentNode]._neighbors[neighbor]]._visited)
            {
                m_graph[m_graph[currentNode]._neighbors[neighbor]]._visited = true;
                m_graph[m_graph[currentNode]._neighbors[neighbor]]._distance = m_graph[currentNode]._distance + 1;
                m_graph[m_graph[currentNode]._neighbors[neighbor]]._predecessor = convertNodeToCell(currentNode);
                queue.push(m_graph[currentNode]._neighbors[neighbor]);
            }
    }
}
//=============================================================================
const sf::Vector2i GameGraph::convertNodeToCell(const int &currentNode) const {

    return {currentNode % m_stage->getStageSize().x , currentNode / m_stage->getStageSize().x};
}
//=============================================================================
const int GameGraph::convertCellToNode(const int &row , const int &col) const{

    return row * m_stage->getStageSize().x + col;
}
//=============================================================================
std::pair<sf::Vector2f, graphStaticObjects_t> GameGraph::getDirectionAndObj(const sf::Vector2f &virusPosition) {

    auto virusArrPosition = getPosInArr(virusPosition);
    auto virusNode = convertCellToNode(virusArrPosition.y , virusArrPosition.x);

    auto virusPredecessor = m_graph[virusNode]._predecessor;
    auto obj = m_graph[virusNode]._repObject;

    // If no predecessor
    if(virusPredecessor.x == NO_PREDECESSOR && virusPredecessor.y == NO_PREDECESSOR)
        return std::make_pair(STAND, obj);

    if (virusArrPosition.y < virusPredecessor.y)
        return std::make_pair(DOWN, obj);

    else if(virusArrPosition.x > virusPredecessor.x)
        return std::make_pair(LEFT, obj);

    else if(virusArrPosition.x < virusPredecessor.x)
        return std::make_pair(RIGHT, obj);

    else if(virusArrPosition.y > virusPredecessor.y)
        return std::make_pair(UP, obj);

    // If not moving then stand
    return std::make_pair(STAND, obj);
}
//=============================================================================
const sf::Vector2i GameGraph::getPosInArr(const sf::Vector2f &virusPosition) const {
    return sf::Vector2i((virusPosition.x / WINDOW_WIDTH) * m_stage->getStageSize().x,
                        ((virusPosition.y - STAGE_DETAILS_SIZE) / (WINDOW_HEIGHT - STAGE_DETAILS_SIZE)) * m_stage->getStageSize().y);
}
//=============================================================================
const graphStaticObjects_t &GameGraph::getObjectInPosition(const sf::Vector2i& position) {
    auto node = convertCellToNode(position.y, position.x);
    return m_graph[node]._repObject;
}
//=============================================================================





