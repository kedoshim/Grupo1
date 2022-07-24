#include "Vertex.h"
#include "Agm.h"
#include <list>
using namespace std;

class Graph
{
private:
<<<<<<< HEAD
    int nVertex;
    int isDirectioned;
=======
    string archiveS;
    string outString;
    int order = 0;
    int edgeNumber = 0;
    int position = 0;
    int isDirected;
>>>>>>> jongas
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
    int getnVertex();
    bool getEdgeIsWeighted(){return edgeIsWeighted;};
    Vertex *getVertexByID(int id);
    Vertex *getFirst();
    int getVertexPower(Vertex *a);
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
    list<Edge*> arestasGrafo; // lista com arestas do grafo         
    void unir(int v1,int v2, int *ciclo); // Usado para verificar ciclos
    int pai(int v, int *ciclo); // Usado para verificar ciclos


    float camMinD();
    void camMinF();
    void agmPrim(Graph *g);
    void agmKruskal(Graph *g);
    void fechoTransitivoDireto(int id);
    void fechoTransitivoIndireto(int id);
    void percorreVertices(Vertex *v, bool arestasRetorno);
    void percorreVertices(Vertex *v);
    void arvoreCaminhamento();
<<<<<<< HEAD
    void agrupamentoLocal();
    void agrupamentoGlobal();
    void Djkstra();
    void Floyd(Vertex *a, Vertex *b);
=======
    void auxArvCam(Vertex *v, vector<int> *vec, vector<int> *returnE, vector<string> *grafoS);
    void outFileArvCam(vector<string> *grafoS);
    void insertVertex(int id);
>>>>>>> jongas
};
