#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

class Graph
{
    // od razu musimy zadeklarowa� maksymaln� ilo�� wierzcho�k�w - tutaj 100;
    int numberOfVertices;
    bool matrix[10000][10000]{}; //[1][2] -> oznacza że jest przejście (1) --> (2)
public:
    Graph();
    void createVertices(int ile);
    void addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2);
    void removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2);
    bool checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2);
    int vertexDegree(int idx);
    std::vector<int> getNeighbourIndices(int idx);
    void printNeighbourIndices(int idx);
    int getNumberOfEdges();
    void readFromFile(std::string path);

private:
    void clear();
};
