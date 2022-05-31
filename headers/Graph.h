#include "Vertex.h"

class Graph
{
private:
    Vertex *first;

public:
    Graph(char **argv);
    ~Graph();

    void connectVertex(Vertex *a, Vertex *b);
    void connectVertex(Vertex *a, Vertex *b, int weight);
    Vertex *getVertexByID(int id);
    void setVertex(int nVertex);

    void imprimeAdjacentes();
};
