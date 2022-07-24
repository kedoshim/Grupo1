#include <bits/stdc++.h>
#include "../headers/Graph.h"
using namespace std;

/*
argv[1] = entrada;
argv[2] = saida;
argv[3] = direcionado;
argv[4] = aresta ponderada;
argv[5] = nó ponderado
*/

Graph *readArchives(char **argv);
void menu(Graph *g);

int main(int argc, char **argv)
{
  if (argc != 6)
  {
    cout << "Numero errado de argumentos" << endl;
    return -1;
  }

  Graph *g = readArchives(argv);
  g->setOutString(argv[2]);

  menu(g);

  return 0;
}

void menu(Graph *g)
{
  char input;

  int i;

  printf("1 - Fecho transitivo direto deste vertice\n");
  printf("\n2 - Fecho transitivo indireto deste vertice\n");
  printf("\n3 - Coeficiente de agrupamento local do vertice\n");
  printf("\n4 - Coeficiente de agrupamento medio do grafo\n");
  printf("\n5 - Caminho minimo entre dois vertices usando algoritmo de Djkstra\n");
  printf("\n6 - Caminho minimo entre dois vertices usando algoritmo de Floyd\n");
  printf("\n7 - Arvore Geradora Minima sobre o subgrafo vertice-induzido por X usando o algoritmo de Prim\n");
  printf("\n8 - Arvore Geradora Minima sobre o subgrafo vertice-induzido por X usando o algoritmo de Kruskal\n");
  printf("\n9 - Arvore dada pela ordem de caminhamento em profundidade a partir de um dado no, destacando as arestas de retorno\n");
  printf("\n\nPressione 0 para sair\n");

  while (input != '1' && input != '2' && input != '3' && input != '4' && input != '5' && input != '6' && input != '7' && input != '8' && input != '9' && input != '0')
    scanf(" %c", &input);
  switch (input)
  {
  case '1':
    cout << "Digite o ID do vertice: ";
    cin >> i;
    cout << endl;
    g->fechoTransitivoDireto(i);
    break;
  case '2':
    cout << "Digite o ID do vertice: ";
    cin >> i;
    cout << endl;
    g->fechoTransitivoIndireto(i);
    break;
  case '3':
    g->agrupamentoLocal();
    break;
  case '4':
      /*  g->function() */;
    break;
  case '5':
    /* g->camMinD(); */
    break;
  case '6':
    /* g->camMinF(); */
    break;
  case '7':
    cout << "\nPara essa função, é necessário um subgrafo vértice induzido" << endl;
    g->getVerticeInduzido();
    break;
  case '8':
    /* g->agmKruskal(); */
    break;
  case '9':
    g->arvoreCaminhamento();
    break;
  case '0':
    return;
  }

  menu(g);
}

Graph *readArchives(char **argv) // Função para ler o arquivo de entrada e criar o grafo
{
  ifstream archive;
  string line, stringVertex = "", temp = "";
  int nVertex;

  archive.open(argv[1]);

  if (archive.is_open())
  {

    getline(archive, stringVertex);
    Graph *graph = new Graph(stoi(stringVertex), stoi(argv[3]), stoi(argv[4]), stoi(argv[5]));
    graph->setVertex(stoi(stringVertex));

    vector<int> test;

    while (getline(archive, temp))
    {
      stringstream sTeste(temp);

      while (getline(sTeste, line, ' '))
        test.push_back(stoi(line));

      if (stoi(argv[4]) == 1)
        graph->connectVertex(graph->getVertexByID(test.at(0)), graph->getVertexByID(test.at(1)), test.at(2));
      else
        graph->connectVertex(graph->getVertexByID(test.at(0)), graph->getVertexByID(test.at(1)));

      test.clear();
    }
    return graph;
  }
  else
    cout << "Nao foi possivel abrir o arquivo." << endl;

  return nullptr;
}