#include "edge.h"

edge::edge(int i_Vertex_Index1, int i_Vertex_Index2)
{
    vertex_Index1 = i_Vertex_Index1;
    vertex_Index2 = i_Vertex_Index2;
    waga = 0;
}

edge::edge(int i_Vertex_Index_1, int i_Vertex_Index_2, float i_weight)
{
    vertex_Index1 = i_Vertex_Index_1;
    vertex_Index2 = i_Vertex_Index_2;
    waga = i_weight;
}

bool edge::operator==(const edge &other) const
{
    return (vertex_Index1 == other.vertex_Index1 &&
            vertex_Index2 == other.vertex_Index2);
}

bool edge::operator>(const edge &other) const
{
    return (waga > other.waga);
}

bool edge::operator<(const edge &other) const
{
    return (waga < other.waga);
}