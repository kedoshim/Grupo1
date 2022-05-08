#include "Vertice.h"

class Grafo
{
private:
    int nvertices;
    int aPonderadas;
    int vPonderados;
    int direcionado;
    Vertice* first;
public:
    Grafo(int nVert, int aPonderadas, int vPonderados, int direcionado);//1 se ponderado, 0 se não
    ~Grafo();
    void setAresta(int IdA,int idB,float peso,int direcionado);
    void setPesoVertice(int id, float peso);
    void setArestas(int ponderadas);
    Aresta* getArestaEntreAB(int IDvertA,int IDvertB);
    Vertice* getVerticeDeID(int id);
};
