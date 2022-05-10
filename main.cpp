#include <iostream>
#include "Grafo.h"

using namespace std;

int main(int argc, int *argv[]) /*argv[1]=input; argv[2]=output; argv[3]==grafo direcionado; argv[4]==aresta ponderada; argv[5]==vertice ponderado*/
{
    int nvertices;
    int id;
    float peso;
    int idA,idB;
    Grafo* grafo;
    Vertice* vert1;
    Vertice* vert2;
    cin >> nvertices;
    grafo=new Grafo(nvertices,*argv[1],*argv[2],*argv[3]);

    return 0;
}
