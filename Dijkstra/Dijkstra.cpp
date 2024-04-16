#include "Dijkstra.h"

Dijkstra::Dijkstra(Graph &graph, int startVertex) : graph(graph), startVertex(startVertex)
{
    int graphSize = graph.getVerticesCount();
    distanceVec = std::vector<int>(graphSize, maxDistance);
    distanceVec.at(startVertex) = 0;
    wayBackVec = std::vector<int>(graphSize, -1);
    checked = std::vector<bool>(graphSize, false);

    std::priority_queue<Pair<int, int>, std::vector<Pair<int, int>>, std::greater<Pair<int, int>>>
        queue;
    queue.push(Pair(startVertex, 0));
    for (int i = 0; i < graphSize - 1; i++)
    {
        int currentVertex = queue.top().getFirst();
        queue.pop();
        checked.at(currentVertex) = true;

        std::vector<int> neighbours = graph.getNeighbourIndices(currentVertex);
        for (int neighbour : neighbours)
        {
            if (!checked.at(neighbour))
            {
                int distanceToNeighbour = graph.getEdgeWeight(currentVertex, neighbour);
                if (distanceVec.at(neighbour) > distanceVec.at(currentVertex) + distanceToNeighbour)
                {
                    wayBackVec.at(neighbour) = currentVertex;

                    distanceVec.at(neighbour) = distanceVec.at(currentVertex) + distanceToNeighbour;
                    queue.push(Pair(neighbour, distanceVec.at(neighbour)));
                }
            }
        }

        while (true) // pętla się wykona tak długa aż długość w otrzymywaniej parze nie będzie "przedawniona"
        {
            Pair currentPair = queue.top();
            if (distanceVec.at(currentPair.getFirst()) >= currentPair.getSecond())
                break;
            queue.pop();
        }
    }
}

int Dijkstra::getShortestPathValue(int destinationVertex) { return distanceVec.at(destinationVertex); }
std::vector<int> Dijkstra::getPath(int destinationVertex)
{
    std::vector<int> path;

    int currentVertex = destinationVertex;
    while (wayBackVec.at(currentVertex) != -1)
    {
        path.push_back(currentVertex);
        currentVertex = wayBackVec.at(currentVertex);
    }
    path.push_back(startVertex);

    return path;
}
