#include "Edge.h"

class Vertex
{
private:
    int id;
    Vertex *prev = nullptr;
    Vertex *next = nullptr;
    Edge *nextEdge = nullptr;

public:
    Vertex(int idVertex);
    void setPrev(Vertex *v) { this->prev = v; };
    void setNext(Vertex *v) { this->next = v; };
    Vertex *getPrev() { return this->prev; };
    Vertex *getNext() { return this->next; };
    int getID() { return id; };
    void setNextEdge(int vID);
    ~Vertex();
};
