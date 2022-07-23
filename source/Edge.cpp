#include "../headers/Edge.h"

Edge::Edge(int vID, int *edgeNumber)
{
    (*edgeNumber)++;
    id = vID;
}

Edge::Edge(int vID, int weightEdge, int *edgeNumber)
{
    (*edgeNumber)++;
    id = vID;
    weight = weightEdge;
}

void Edge::setNextEdge(int vID, int *edgeNumber)
{
    Edge *e = new Edge(vID, edgeNumber);

    if (nextEdge == NULL)
        this->nextEdge = e;

    else
    {
        Edge *i;

        for (i = this; i->getNext() != NULL; i = i->getNext())
            continue;

        i->nextEdge = e;
    }
}

void Edge::setNextEdge(int vID, int weightVertex, int *edgeNumber)
{
    Edge *e = new Edge(vID, weightVertex, edgeNumber);
    this->nextEdge = e;
}
