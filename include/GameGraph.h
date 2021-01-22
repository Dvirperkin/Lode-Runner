#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Ladder.h"
#include <queue>
#include "Macros.h"



struct NodesData {
    int _neighbors[MAX_NEIGHBORS] = {NO_NEIGHBOR, NO_NEIGHBOR, NO_NEIGHBOR, NO_NEIGHBOR};
    bool _visited = false;
    int _distance = -1 ;
    sf::Vector2i _predecessor = {NO_PREDECESSOR , NO_PREDECESSOR};
    bool _isNode = true;

    //The object in the current node.
    graphStaticObjects_t _repObject = NULL_OBJECT;
};

class GameGraph {

public:
    //--------------------Constructor/Destructor Section--------------------
    GameGraph(Stage &);

    //--------------------Action Function Section--------------------
    void initializeData ();
    void BFS (const sf::Vector2i &);

    //--------------------Get Function Section--------------------
    const graphStaticObjects_t& getObjectInPosition(const sf::Vector2i&);//used to get the object in the current position.
    std::pair<sf::Vector2f , graphStaticObjects_t> getDirectionAndObj(const sf::Vector2f&);

private:
    std::vector<NodesData> m_graph;
    Stage * m_stage;

    void initializeGraph();
    void addNeighbors ();
    const sf::Vector2i convertNodeToCell (const int &) const;
    const sf::Vector2i getPosInArr(const sf::Vector2f&) const;
    const int convertCellToNode (const int & , const int &) const;
};

