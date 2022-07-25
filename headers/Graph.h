#include "Vertex.h"
using namespace std;

class Graph
{
private:
    string archiveS;
    string outString;
    int order = 0;
    int edgeNumber = 0;
    int position = 0;
    int isDirected;
    int edgeIsWeighted;
    int vertexIsWeighted;
    Vertex *first;
    Vertex *last;
    string arestasR = "";
    string arvoreC = "";

public:
    Graph(int order, bool directed, bool edgeWeighted, bool vertexWeighted);
    ~Graph();

    void connectVertex(Vertex *a, Vertex *b);
    void connectVertex(Vertex *a, Vertex *b, int weight);
    Vertex *getVertexByID(int id);
    Vertex *getFirst();
    void setVertex(int nVertex);
    void setOrder(int nVertex);
    int getOrder() { return order; };
    void readArchives(char **argv);
    void clearVertex();
    void setOutString(string outString) { this->outString = outString; };

    bool getDirected() { return isDirected; };
    bool getWeightedEdge() { return edgeIsWeighted; };
    bool getWeightedVertex() { return vertexIsWeighted; };
    Graph *getVerticeInduzido();
    int getEdgeNumber() { return edgeNumber; };

    float agrupamentoLocal(int id, bool print);
    void agrupamentoGlobal();
    float camMinD();
    void camMinF();
    void agmPrim(Graph *g);
    void agmKruskal();
    void fechoTransitivoDireto(int id);
    void fechoTransitivoIndireto(int id);
    void percorreVertices(Vertex *v, bool arestasRetorno);
    void percorreVertices(Vertex *v);
    void arvoreCaminhamento();
    void auxArvCam(Vertex *v, vector<int> *vec, vector<int> *returnE, vector<string> *grafoS);
    void outFileArvCam(vector<string> *grafoS);
    void insertVertex(int id);
};
