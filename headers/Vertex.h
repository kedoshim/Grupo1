#include "Edge.h"

class Vertex
{
private:
    int id;
    int weight;
    bool wasVisited = false;
    Vertex *prev = NULL;
    Vertex *next = NULL;
    Edge *nextEdge = NULL;
    int visitedBefore = 0;

public:
    Vertex(int idVertex);
    Vertex(int idVertex, int weightVertex);
    void setPrev(Vertex *v) { this->prev = v; };
    void setNext(Vertex *v) { this->next = v; };
    void setVisited(bool was) { this->wasVisited = was; };
    Vertex *getPrev() { return this->prev; };
    Vertex *getNext() { return this->next; };
    bool getVisited() { return this->wasVisited; };
    int getID() { return id; };
    Edge *getEdge() { return nextEdge; };
    void setNextEdge(int vID);
    void setNextEdge(int vID, int weightVertex);
    void setVisitedBefore(int vID) { this->visitedBefore = vID; };
    int getVisitedBefore() { return this->visitedBefore; };
    ~Vertex();
};
