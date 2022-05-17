#include <iostream>
#include "../headers/Grafo.h"

using namespace std;

Grafo::Grafo(int nVert, int aPonderadas, int vPonderados, int direcionado)
{
    Vertice *first;
    Vertice *vert1;
    Vertice *vert2;
    int id;

    vert1 = new Vertice(1, 0, nullptr);
    first = vert1;

    for (id = 2; id <= nVert / 2; id++)
    { // fiz a lista de vertices como um ciclo duplamente encadeado
        vert2 = new Vertice(id, 0, nullptr);
        vert1->setProximo(vert2);
        vert2->setAnterior(vert1);
        vert1 = vert2;
    }

    vert1->setProximo(first);
    first->setAnterior(vert1);
    setArestas(aPonderadas);
}

Vertice* Grafo::getVerticeDeID(int id)
{
    Vertice *v;
    v = first;

    if (id < nvertices / 2)
        for (v = first; id != v->getID(); v = v->getProximo())
            ;
    else
        for (v = first; id != v->getID(); v = v->getAnterior())
            ;

    return v;
}

void Grafo::setArestas(int ponderadas)
{
    float peso = 0;
    Aresta *a;
    int idA, idB;

    if (ponderadas == 0)
    {
        while (!cin.eof())
        {
            cin >> idA >> idB;
            a = new Aresta(nome2id(idA), nome2id(idA), getUltimaAresta(idA,1), getUltimaAresta(idB,-1), 0, direcionado);
        }
    }
    else
    {
        while (!cin.eof())
        {
            cin >> idA >> idB >> peso;
            a = new Aresta(idA, idB, getUltimaAresta(idA,1), getUltimaAresta(idB,-1), peso, direcionado);
        }
    }
}

Aresta *Grafo::getUltimaAresta(int id, int headORtail)
{
    Vertice *v;
    Aresta *a;
    Aresta *b;
    v = getVerticeDeID(id);
    if(headORtail!=0)
        v->aumentaGrau(headORtail);
    a = v->getAresta();

    while (a != nullptr)
    {
        b = a;
        a = a->getNextAB(id);
    }

    return b;
}

Aresta *Grafo::getArestaEntreAB(int IDvertA, int IDvertB)
{
}

int Grafo::nome2id(string id)

{
    static idscomnome=0;
    Vertice* v=first;
    for(int i=0;i<nvertices;i++){
        if(v->getname()==id){
          return i;
        }
        if(i>=idscomnome){
          v->setNome(id);
          idscomnome++;
          return i;
}
     v=v->getProximo();

}
