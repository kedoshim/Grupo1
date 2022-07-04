#include "Vertex.h"

class Graph
{
private:
    int isDirectioned;
    int edgeIsWeighted;
    int vertexIsWeighted;
    Vertex *first;
    std::string arestasR = "";
    std::string arvoreC = "";

public:
    Graph(char **argv);
    ~Graph();

    void connectVertex(Vertex *a, Vertex *b);
    void connectVertex(Vertex *a, Vertex *b, int weight);
    Vertex *getVertexByID(int id);
    void setVertex(int nVertex);
    void readArchives(char **argv);
    void clearVertex();

    void fechoTransitivoDireto();
    void percorreVertices(Vertex *v, bool arestasRetorno);
    void arvoreCaminhamento();
};
