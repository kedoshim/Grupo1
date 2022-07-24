#include "Vertex.h"

class Graph
{
private:
    int nVertex;
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
    int getnVertex();
    bool getEdgeIsWeighted(){return edgeIsWeighted;};
    Vertex *getVertexByID(int id);
    Vertex *getFirst();
    int getVertexPower(Vertex *a);
    void setVertex(int nVertex);
    void readArchives(char **argv);
    void clearVertex();

    void fechoTransitivoDireto();
    void fechoTransitivoIndireto();
    void percorreVertices(Vertex *v, bool arestasRetorno);
    void percorreVertices(Vertex *v);
    void arvoreCaminhamento();
    void agrupamentoLocal(int id);
    void agrupamentoGlobal(Graph* g);
    void Djkstra();
    void Floyd(Vertex *a, Vertex *b);
};
