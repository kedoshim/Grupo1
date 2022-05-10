#include "../headers/Aresta.h"

class Vertice
{
private:
    int ID;
    float peso = 0;
    Vertice *vanterior = nullptr;
    Vertice *vproximo = nullptr;
    Aresta *aresta;

public:
    Vertice(int id, float peso, Vertice *anterior);
    ~Vertice();
    void setAresta(Aresta *endereco);
    void setAnterior(Vertice *a);
    void setProximo(Vertice *p);
    void setPeso(float p);
    int getID();
    Aresta *getAresta();
    Vertice *getAnterior();
    Vertice *getProximo();
    int getPeso();
};
