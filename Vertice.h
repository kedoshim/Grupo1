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
    void setAresta(Aresta* endereco);
    void setAnterior(Vertice* a);
    void setProximo(Vertice* p);
    void setPeso(float p);
    Aresta* getAresta();
    Vertice* getAnterior();
    Vertice* getProximo();
    int getPeso();


};
