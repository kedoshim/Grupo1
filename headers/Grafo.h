#include <fstream>
#include "../headers/Vertice.h"

class Grafo
{
private:
    int nvertices;
    int aPonderadas;
    int vPonderados;
    int direcionado;
    Vertice* first;

public:
    Grafo(int nVert, int aPonderadas, int vPonderados, int direcionado);//1 se ponderado, 0 se n�o
    ~Grafo();
    int nome2id(string id);
    void setAresta(int IdA,int idB,float peso,int direcionado);
    void setPesoVertice(int id, float peso);
    void setArestas(int ponderadas);
    Aresta* getArestaEntreAB(int IDvertA,int IDvertB);
    Aresta* getUltimaAresta(int id,int heatORtail);
    Vertice* getVerticeDeID(int id);
};
