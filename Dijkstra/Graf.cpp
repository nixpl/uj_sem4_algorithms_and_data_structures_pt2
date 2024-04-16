#include "Graf.h"

void Graph::createVertices(int ile) { verticesCount = ile; }

int Graph::getVerticesCount() { return verticesCount; }

bool Graph::checkEdgeInVertex(std::list<edge> &vertex, int second_vertex)
{
    auto it = vertex.begin();
    while (it != vertex.end())
    {
        if (it->vertex_Index2 == second_vertex)
            return true;
        it++;
    }
    return false;
}

int Graph::getEdgeWeightInVertex(std::list<edge> &vertex, int second_vertex)
{
    auto it = vertex.begin();
    while (it != vertex.end())
    {
        if (it->vertex_Index2 == second_vertex)
            return it->waga;
        it++;
    }
    return -1;
}

std::list<std::list<edge>>::iterator Graph::findVertex(int vertex)
{
    auto it = vertexList.begin();
    while (it != vertexList.end())
    {
        if (it->back().vertex_Index1 == vertex)
            return it;
        it++;
    }
    return it;
}

void Graph::addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2, float i_weight)
{
    auto vertex = findVertex(i_Vertex_Index_1);
    if (vertex != vertexList.end() && !checkEdgeInVertex(*vertex, i_Vertex_Index_2))
        vertex->push_back(edge(i_Vertex_Index_1, i_Vertex_Index_2, i_weight));
    else
    {
        std::list<edge> newVertex;
        newVertex.push_back(edge(i_Vertex_Index_1, i_Vertex_Index_2, i_weight));
        vertexList.push_back(newVertex);
    }
}
bool Graph::removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2)
{
    auto vertex = findVertex(i_Vertex_Index_1);
    if (vertex != vertexList.end())
    {
        int sizeBeforeRemove = vertex->size();
        vertex->remove(edge(i_Vertex_Index_1, i_Vertex_Index_2));
        return sizeBeforeRemove != (int)vertex->size();
    }
    return false;
}
bool Graph::checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2)
{
    auto vertex = findVertex(i_Vertex_Index_1);
    if (vertex != vertexList.end())
        return checkEdgeInVertex(*vertex, i_Vertex_Index_2);
    return false;
}

int Graph::getEdgeWeight(int i_Vertex_Index_1, int i_Vertex_Index_2)
{
    auto vertex = findVertex(i_Vertex_Index_1);
    if (vertex != vertexList.end())
        return getEdgeWeightInVertex(*vertex, i_Vertex_Index_2);
    return -1;
}

int Graph::vertexDegree(int idx)
{
    auto vertex = findVertex(idx);
    if (vertex != vertexList.end())
        return vertex->size();
    return 0;
}
std::vector<int> Graph::getNeighbourIndices(int idx)
{
    std::vector<int> neighbourIndices;
    auto vertex = findVertex(idx);
    if (vertex != vertexList.end())
    {
        for (auto el : *vertex)
            neighbourIndices.push_back(el.vertex_Index2);
    }
    return neighbourIndices;
}
void Graph::printNeighbourIndices(int idx)
{
    std::cout << "[ ";
    for (auto neighbour : getNeighbourIndices(idx))
        std::cout << neighbour << " ";
    std::cout << "]";
}
int Graph::getNumberOfEdges()
{
    int numberOfEdges = 0;
    for (auto vertex : vertexList)
        numberOfEdges += vertex.size();

    return numberOfEdges;
}
void Graph::readFromFile(std::string path)
{
    std::fstream file;
    file.open(path, std::ios::in);
    std::string buff;
    std::getline(file, buff);
    verticesCount = std::stoi(buff);
    try
    {
        while (getline(file, buff))
        {
            int gapIndex = buff.find(' ');
            int i_Vertex_Index_1 = std::stoi(buff.substr(0, gapIndex));
            int i_Vertex_Index_2 = std::stoi(buff.substr(gapIndex + 1));
            gapIndex = buff.find(' ', gapIndex + 1);
            int i_weight = std::stoi(buff.substr(gapIndex + 1));

            addEdge(i_Vertex_Index_1, i_Vertex_Index_2, i_weight);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Cannot read data from file: " << path << std::endl;
    }

    file.close();
}

void Graph::searchDFS(int currentVertex, std::vector<int> &searchOrder, std::unordered_set<int> &visitedInfo)
{
    std::vector<int> neighbourIndices = getNeighbourIndices(currentVertex);
    std::sort(neighbourIndices.begin(), neighbourIndices.end());

    for (auto neighbour : neighbourIndices)
    {
        if (visitedInfo.find(neighbour) == visitedInfo.end())
        {
            visitedInfo.insert(neighbour);
            searchOrder.push_back(neighbour);
            searchDFS(neighbour, searchOrder, visitedInfo);
        }
    }
}

std::vector<int> Graph::searchDFS(int idx)
{
    std::unordered_set<int> visitedInfo = {idx};
    std::vector<int> searchOrder = {idx};
    searchDFS(idx, searchOrder, visitedInfo);
    return searchOrder;
}

void Graph::printDFS(int idx)
{
    std::cout << "[ ";
    std::vector<int> order = searchDFS(idx);
    for (auto vertex : order)
        std::cout << vertex << " ";
    std::cout << "]";
}

std::vector<int> Graph::searchBFS(int idx)
{
    std::vector<int> searchOrder;
    std::unordered_set<int> visitedInfo;
    std::vector<int> toVisit = {idx};

    while (!toVisit.empty())
    {
        std::vector<int> newToVisit;
        visitedInfo.insert(toVisit.begin(), toVisit.end());

        for (auto host : toVisit)
        {
            searchOrder.push_back(host);
            std::vector<int> hostNeighbours = getNeighbourIndices(host);
            std::sort(hostNeighbours.begin(), hostNeighbours.end());
            for (auto neighbour : hostNeighbours)
                if (visitedInfo.find(neighbour) == visitedInfo.end())
                    newToVisit.push_back(neighbour);
        }
        toVisit = newToVisit;
    }

    return searchOrder;
}

void Graph::printBFS(int idx)
{
    std::cout << "[ ";
    std::vector<int> order = searchBFS(idx);
    for (auto vertex : order)
        std::cout << vertex << " ";
    std::cout << "]";
}
