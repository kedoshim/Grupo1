#include <iostream>
#include "../headers/Grafo.h"

using namespace std;

int main(int argc, char **argv) /*argv[1]=input; argv[2]=output; argv[3]==grafo direcionado; argv[4]==aresta ponderada; argv[5]==vertice ponderado*/
{
    int nvertices;
    int id;
    float peso;
    int idA, idB;
    Grafo *grafo;
    Vertice *vert1;
    Vertice *vert2;
    
    cin >> nvertices;
    grafo = new Grafo(nvertices, 1, 1, 1);

    return 0;
}
