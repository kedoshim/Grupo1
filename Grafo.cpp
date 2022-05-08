#include "Grafo.h"

using namespace std;

Grafo::Grafo(int nVert, int aPonderadas, int vPonderados, int direcionado)
{
    Vertice* first,vert1,vert2;
    int id;
    vert1=new Vertice(1);
    first=vert1;
    for(id=2;id<=nvert/2;id++){   //fiz a lista de vertices como um ciclo duplamente encadeado
        vert2=new Vertice(id);
        vert1.setProximo(vert2);
        vert2.setAnterior(vert1);
        vert1=vert2;
    }
    vert1.setProximo(first);
    first.setAnterior(vert1);
    vatual=vert1;
}

Grafo::getVerticeDeID(int id)
{
    Vertice* v;
    v=first;
    if(id<nvert/2)
        for(v=first;id!=v.getID();v=v.getProximo())
    else
        for(v=first;id!=v.getID();v=v.getAnterior())
    return v;
}

void Grafo::setArestas(int IdA,int idB,float peso,int direcionado)
{
    Aresta* a;
    int idA,idB;
    while(cin.eof()){
    cin >> idA >> idB >> endl;
    a=new Aresta(IdA,idB,peso,direcionado)
    }

}

Grafo::getArestaEntreAB(int IDvertA,int IDvertB)
{

}
