#include <iostream>
#include "Graf.h"
#include "Dijkstra.h"

int main()
{
    Graph myGraph;
    myGraph.readFromFile("GrafD1.txt");

    Dijkstra dijkstra(myGraph, 5);

    std::cout << dijkstra.getShortestPathValue(8) << std::endl;

    std::vector<int> path = dijkstra.getPath(8);
    for (auto vertex : path)
        std::cout << vertex << " ";

    return 0;
}
