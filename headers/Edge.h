#include <bits/stdc++.h>

class Edge
{
private:
    int id;
    Edge *nextEdge = NULL;
    int weight;

public:
    Edge(int idEdge, int *edgeNumber);
    Edge(int idEdge, int weightEdge, int *edgeNumber);
    ~Edge();
    void setNextEdge(int idEdge, int *edgeNumber);
    void setNextEdge(int idEdge, int weightVertex, int *edgeNumber);
    Edge *getNext() { return nextEdge; };
    int getID() { return id; };
    int getWeight() { return weight; };
};