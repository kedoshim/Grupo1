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
    Vertice(int id);
    Vertice(int id, Vertice* anterior);
    Vertice(int id,float peso);             //se os vertices forem ponderados
    Vertice(int id,float peso, Vertice* anterior);
    ~Vertice();
    setAresta(Aresta* endereco);
    setAnterior(Vertice* a);
    setProximo(Vertice* p);
    setPeso(float p);


};
