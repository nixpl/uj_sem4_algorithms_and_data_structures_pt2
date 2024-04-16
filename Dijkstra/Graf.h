#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include "edge.h"

class Graph
{
private:
    int verticesCount;
    std::list<std::list<edge>> vertexList;

    bool checkEdgeInVertex(std::list<edge> &vertex, int second_vertex);
    int getEdgeWeightInVertex(std::list<edge> &vertex, int second_vertex);
    std::list<std::list<edge>>::iterator findVertex(int vertex);
    void searchDFS(int currentVertex, std::vector<int> &searchOrder, std::unordered_set<int> &visitedInfo);

public:
    void createVertices(int ile);
    int getVerticesCount();
    void addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2, float i_weight = 0);
    bool removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2);
    bool checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2);
    int getEdgeWeight(int i_Vertex_Index_1, int i_Vertex_Index_2);
    int vertexDegree(int idx);
    std::vector<int> getNeighbourIndices(int idx);
    void printNeighbourIndices(int idx);
    int getNumberOfEdges();
    void readFromFile(std::string path);

    std::vector<int> searchDFS(int idx);
    void printDFS(int idx);

    std::vector<int> searchBFS(int idx);
    void printBFS(int idx);
};
