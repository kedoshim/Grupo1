#include "Aresta.h"

class Vertice
{
private:
    int ID;
    float peso=0;
    Vertice* vanterior=nullptr;
    Vertice* vproximo=nullptr;
    Aresta* aresta;
public:
    Vertice(int id,float peso)
    Vertice(int id,float peso, Vertice* anterior);
    ~Vertice();
    setAresta(Aresta* endereco);
    setAnterior(Vertice* a);
    setProximo(Vertice* p);
    setPeso(float p);


};
