#include <iostream>
#include "Grafo.h"

using namespace std;

int main(int argc, int *argv[]) /*argv[1]==aresta ponderada; argv[2]==vertice ponderado; argv[3]==grafo direcionado*/
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
