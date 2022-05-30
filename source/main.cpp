#include <iostream>
#include <fstream>
#include "../headers/Grafo.h"

using namespace std;

int main(int argc, char **argv) /*argv[1]=input; argv[2]=output; argv[3]==grafo direcionado; argv[4]==aresta ponderada; argv[5]==vertice ponderado*/
{

  if (argc != 6)
  {
    cout << "Numero errado de argumentos" << endl;
    cout << "Favor executar do seguinte modo:" << endl;
    cout << "./Grupo1 'arquivo de entrada' 'arquivo de saida' 'O grafo eh direcionado?(0/1)' 'As arestas sao ponderadas?(0/1)' 'Os vertices sao ponderados?(0/1)'" << endl;
    return 1;
  }

  ifstream arquivo;
  string linha, stringVertices = "";
  string param = "";
  int numArestas = 0;

  arquivo.open(argv[1]);

  if (arquivo.is_open())
  {

    while (getline(arquivo, linha))
    {
      if (stringVertices == "")
        stringVertices = linha;
      else
        param += linha + '\n';

      numArestas++;
    }
  }
  else
    cout << "Nao foi possivel abrir o arquivo. " << endl;

  /* cout << "Numero de nos: " << stringVertices << endl;
  cout << "Parametros: " << endl;
  cout << param; */

  int nvertices = stoi(stringVertices);

  Grafo *grafo = new Grafo(nvertices, stoi(argv[4]), stoi(argv[5]), stoi(argv[3])); // argumentos precisam ser int

  return 0;
}

/* void setVertices(string param, Grafo *grafo, int nvertices)
{
  string a = "", b = "", c = "";
  int *listaID = (int *)calloc(nvertices, sizeof(int)), id = 1, cont = 0, contE = 0;

  for (auto i : param)
  {

    if (i == ' ')
    {
      contE++;
      continue;
    }

    if (contE == 0)
    {
      a += i;
      continue;
    }

    if (contE == 1)
    {
      b += i;
      continue;
    }

    if (contE == 2)
    {
      c += i;
      continue;
    }

    if (i == '\n')
      contE = 0;

    if (listaID[stoi(a)] == 0 && a != "")
    {
      listaID[stoi(a)] = id;
      id++;
    }

    if (listaID[stoi(b)] == 0 && b != "")
    {
      listaID[stoi(a)] = id;
      id++;
    }

    grafo->setAresta(listaID[stoi(a)], listaID[stoi(b)], 0, 0);
    a = b = c = "";
  }
} */