#include "../headers/Vertex.h"

Vertex::Vertex(int idVertex)
{
    id = idVertex;
    this->setNext(NULL);
}

Vertex::Vertex(int idVertex, int weightVertex)
{
    id = idVertex;
    weight = weightVertex;
    this->setNext(NULL);
}

Vertex::~Vertex()
{
}

void Vertex::setNextEdge(int vID)
{
    if (nextEdge == NULL)
    {
        Edge *e = new Edge(vID);
        this->nextEdge = e;
    }
    else
        nextEdge->setNextEdge(vID);
}

void Vertex::setNextEdge(int vID, int weightVertex)
{
    if (nextEdge == NULL)
    {
        Edge *e = new Edge(vID, weightVertex);
        this->nextEdge = e;
    }
    else
        nextEdge->setNextEdge(vID, weightVertex);
}
