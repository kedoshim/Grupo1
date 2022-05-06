#include "Aresta.h"
#include "Vertice.h"

class Grafo
{
private:
    int nvertices;
    Vertice* first;
public:
    Grafo(int nVert, int vPonderados, int aPonderadas);//1 se ponderado, 0 se não
    ~Grafo();
    setAresta(int IdA,int idB,float peso,int direcionado);
    setPesoVertice(int id, float peso);
    Aresta* getArestaEntreAB(int IDvertA,int IDvertB);
    Vertice* getVerticeDeID(int id);
};
