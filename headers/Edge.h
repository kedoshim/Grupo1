#include <bits/stdc++.h>

class Edge
{
private:
    int id;
    Edge *nextEdge = NULL;
    int weight;

public:
    Edge(int idEdge);
    Edge(int idEdge, int weightEdge);
    ~Edge();
    void setNextEdge(int idEdge);
    void setNextEdge(int idEdge, int weightVertex);
    Edge *getNext() { return nextEdge; };
    int getID() { return id; };
    int getWeight() { return weight; };
};