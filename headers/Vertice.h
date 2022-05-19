#include "../headers/Aresta.h"
#include <string>

using namespace std;

class Vertice
{
private:
    int ID;
    string nome;
    int grauIn;
    int grauOut;
    float peso = 0;
    Vertice *vanterior = nullptr;
    Vertice *vproximo = nullptr;
    Aresta *aresta;

public:
    Vertice(int id, float peso, Vertice *anterior);
    ~Vertice();
    void aumentaGrau(int i);
    void setAresta(Aresta *endereco);
    void setAnterior(Vertice *a);
    void setProximo(Vertice *p);
    void setPeso(float p);
    void setNome(string n);
    int getID();
    Aresta *getAresta();
    Vertice *getAnterior();
    Vertice *getProximo();
    int getPeso();
    string getNome();
};
