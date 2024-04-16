#include "Graph.h"

Graph::Graph() : numberOfVertices{} {}

void Graph::createVertices(int ile) { numberOfVertices = ile; }

void Graph::addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2) { matrix[i_Vertex_Index_1][i_Vertex_Index_2] = true; }

void Graph::removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2) { matrix[i_Vertex_Index_1][i_Vertex_Index_2] = false; }

bool Graph::checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2) { return matrix[i_Vertex_Index_1][i_Vertex_Index_2]; }

int Graph::vertexDegree(int idx)
{
    int degree = 0;
    for (int j = 0; j < numberOfVertices; j++)
        if (matrix[idx][j])
            degree++;

    return degree;
}

std::vector<int> Graph::getNeighbourIndices(int idx)
{
    std::vector<int> neighbourIndices;
    for (int j = 0; j < numberOfVertices; j++)
        if (matrix[idx][j])
            neighbourIndices.push_back(j);

    return neighbourIndices;
}

void Graph::printNeighbourIndices(int idx)
{
    std::cout << "[ ";
    for (int j = 0; j < numberOfVertices; j++)
        if (matrix[idx][j])
            std::cout << j << " ";

    std::cout << "]";
}

int Graph::getNumberOfEdges()
{
    int numberOfEdges = 0;
    for (int i = 0; i < numberOfVertices; i++)
        for (int j = 0; j < numberOfVertices; j++)
            if (matrix[i][j])
                numberOfEdges++;

    return numberOfEdges;
}

void Graph::readFromFile(std::string path)
{
    std::fstream file;
    file.open(path, std::ios::in);
    std::string buff;
    std::getline(file, buff);
    try
    {
        numberOfVertices = std::stoi(buff);

        while (getline(file, buff))
        {
            int gapIndex = buff.find(' ');
            int i_Vertex_Index_1 = std::stoi(buff.substr(0, gapIndex));
            int i_Vertex_Index_2 = std::stoi(buff.substr(gapIndex + 1));

            addEdge(i_Vertex_Index_1, i_Vertex_Index_2);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Cannot read data from file: " << path << std::endl;
    }

    file.close();
}