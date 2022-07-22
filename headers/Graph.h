#include "Vertex.h"
using namespace std;

class Graph
{
private:
    string outString;
    int order = 0;
    int isDirectioned;
    int edgeIsWeighted;
    int vertexIsWeighted;
    Vertex *first;
    string arestasR = "";
    string arvoreC = "";

public:
    Graph(char **argv);
    ~Graph();

    void connectVertex(Vertex *a, Vertex *b);
    void connectVertex(Vertex *a, Vertex *b, int weight);
    Vertex *getVertexByID(int id);
    Vertex *getFirst();
    void setVertex(int nVertex);
    void readArchives(char **argv);
    void clearVertex();

    void fechoTransitivoDireto(int id);
    void fechoTransitivoIndireto(int id);
    void percorreVertices(Vertex *v, bool arestasRetorno);
    void percorreVertices(Vertex *v);
    void arvoreCaminhamento();
    void auxArvCam(Vertex *v, vector<int> *vec, vector<int> *returnE, vector<string> *grafoS);
    void outFileArvCam(vector<string> *grafoS);
};
