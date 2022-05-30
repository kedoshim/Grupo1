#include "../headers/Edge.h"

Edge::Edge(int vID)
{
    vertexID = vID;
}

void Edge::setNextEdge(int vID)
{
    Edge *e = new Edge(vID);
    this->nextEdge = e;
}