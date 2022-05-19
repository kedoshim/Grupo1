#include <iostream>
#include <fstream>
#include "../headers/Grafo.h"

using namespace std;

int main(int argc, char **argv) /*argv[1]=input; argv[2]=output; argv[3]==grafo direcionado; argv[4]==aresta ponderada; argv[5]==vertice ponderado*/
{
  if(argc!=6){
    cout << "Numero errado de argumentos" << endl;
    cout << "Favor executar do seguinte modo:" << endl;
    cout << "./Grupo1 'arquivo de entrada' 'arquivo de saida' 'O grafo é direcionado?(0/1)' 'As arestas são ponderadas?(0/1)' 'Os vertices são ponderados?(0/1)'"  << endl;
    return 1;
  }

  ifstream arquivo;
  arquivo.open(*argv[1]);

  int nvertices;
  int id;
  float peso;
  int idA, idB;
  Grafo *grafo;
  Vertice *vert1;
  Vertice *vert2;

  cin >> nvertices;
  grafo = new Grafo(nvertices, *argv[4], *argv[5], *argv[3]);


  return 0;
}
