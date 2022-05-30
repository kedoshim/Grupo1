#include "Vertex.h"

class Graph
{
private:
    Vertex *first;

public:
    Graph(char **argv);
    ~Graph();

    void connectVertex(Vertex *a, Vertex *b);
    Vertex *getVertexByID(int id);
    void setVertex(int nVertex);
};
