#include "../headers/Edge.h"

Edge::Edge(int vID)
{
    id = vID;
}

Edge::Edge(int vID, int weightEdge)
{
    id = vID;
    weight = weightEdge;
}

void Edge::setNextEdge(int vID)
{
    Edge *e = new Edge(vID);

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

void Edge::setNextEdge(int vID, int weightVertex)
{
    Edge *e = new Edge(vID, weightVertex);
    this->nextEdge = e;
}
