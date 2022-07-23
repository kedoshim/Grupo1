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

void Vertex::setNextEdge(int vID, int *edgeNumber)
{
    (*edgeNumber)++;
    if (nextEdge == NULL)
    {
        Edge *e = new Edge(vID, edgeNumber);
        this->nextEdge = e;
    }
    else
        nextEdge->setNextEdge(vID, edgeNumber);
}

void Vertex::setNextEdge(int vID, int weightVertex, int *edgeNumber)
{
    (*edgeNumber)++;
    if (nextEdge == NULL)
    {
        Edge *e = new Edge(vID, weightVertex, edgeNumber);
        this->nextEdge = e;
    }
    else
        nextEdge->setNextEdge(vID, weightVertex, edgeNumber);
}

bool Vertex::searchEdge(int edgeID)
{
    if (this->nextEdge != nullptr)
    {
        for (Edge *aux = this->nextEdge; aux != nullptr; aux = aux->getNext())
            if (aux->getID() == edgeID)
                return true;
    }

    return false;
}

void Vertex::setNextVertex(Vertex *v)
{
    if (this->next == NULL)
        this->next = v;
    else
        this->next->setNextVertex(v);
}

Edge *Vertex::getEdgeByID(int targetID)
{
    if (this->nextEdge != nullptr)
    {
        for (Edge *aux = this->nextEdge; aux != nullptr; aux = aux->getNext())
            if (aux->getID() == targetID)
                return aux;
    }

    return nullptr;
}