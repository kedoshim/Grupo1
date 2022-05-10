#include <iostream>
#include "Grafo.h"

using namespace std;

Grafo::Grafo(int nVert, int aPonderadas, int vPonderados, int direcionado)
{
    Vertice* first;
    Vertice* vert1;
    Vertice* vert2;
    int id;
    vert1=new Vertice(1);
    first=vert1;
    for(id=2;id<=nVert/2;id++){   //fiz a lista de vertices como um ciclo duplamente encadeado
        vert2=new Vertice(id);
        vert1->setProximo(vert2);
        vert2->setAnterior(vert1);
        vert1=vert2;
    }
    vert1->setProximo(first);
    first->setAnterior(vert1);
    setArestas(aPonderadas);
}

Vertice* Grafo::getVerticeDeID(int id)
{
    Vertice* v;
    v=first;
    if(id<nvertices/2)
        for(v=first;id!=v->getID();v=v->getProximo());
    else
        for(v=first;id!=v->getID();v=v->getAnterior());
    return v;
}

void Grafo::setArestas(int ponderadas)
{
    int peso=0;
    Aresta* a;
    int idA,idB;
    if(ponderadas==0){
        while(!cin.eof()){
        cin >> idA >> idB;
        a=new Aresta(idA,idB,getUltimaAresta(idA),getUltimaAresta(idB),0,direcionado);
        }
    }
    else{
        while(!cin.eof()){
        cin >> idA >> idB >> peso;
        a=new Aresta(idA,idB,peso,direcionado);
        }
    }

}

Aresta* getUltimaAresta(int id)
{
    Vertice* v;
    Aresta* a;
    Aresta* b;
    v=getVerticeDeID(id);
    a=v->getAresta;
    while(a!=nullptr){
        b=a;
        a=a->getNextAB(id);
    }
    return b;
}

Aresta* Grafo::getArestaEntreAB(int IDvertA,int IDvertB)
{

}
