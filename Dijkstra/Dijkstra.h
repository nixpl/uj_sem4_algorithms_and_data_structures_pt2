#pragma once
#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include "Graf.h"
#include "Pair.h"

class Dijkstra
{
private:
    const int maxDistance = std::numeric_limits<int>::max();

    Graph graph;
    int startVertex;

    std::vector<int> distanceVec;
    std::vector<int> wayBackVec;
    std::vector<bool> checked;

public:
    Dijkstra(Graph &graph, int startVertex);

    int getShortestPathValue(int destinationVertex);
    std::vector<int> getPath(int destinationVertex);
};