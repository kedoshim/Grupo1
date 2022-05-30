#include "../headers/Vertex.h"

Vertex::Vertex(int idVertex)
{
    id = idVertex;
    this->setNext(nullptr);
}

Vertex::~Vertex()
{
}

void Vertex::setNextEdge(int vID)
{
    Edge *e = new Edge(vID);
    this->nextEdge = e;
}