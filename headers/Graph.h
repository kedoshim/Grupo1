#include "Vertex.h"

class Graph
{
private:
    int isDirectioned;
    int edgeIsWeighted;
    int vertexIsWeighted;
    Vertex *first;

public:
    Graph(char **argv);
    ~Graph();

    void connectVertex(Vertex *a, Vertex *b);
    void connectVertex(Vertex *a, Vertex *b, int weight);
    Vertex *getVertexByID(int id);
    void setVertex(int nVertex);
    void readArchives(char **argv);

    void function();

    void imprimeAdjacentes();
    void imprimeAdjacentes(char* output);
};
