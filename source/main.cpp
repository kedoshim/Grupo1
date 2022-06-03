#include <bits/stdc++.h>
#include "../headers/Graph.h"

/*
argv[1] = entrada;
argv[2] = saida;
argv[3] = direcionado;
argv[4] = aresta ponderada;
argv[5] = nó ponderado
*/

void menu(Graph* g){
    char input;
    printf("\n1 - Fecho transitivo direto deste vertice\n");
    printf("\n2 - Fecho transitivo indireto deste vertice\n");
    printf("\n3 - Coeficiente de agrupamento local do vertice\n");
    printf("\n4 - Coeficiente de agrupamento medio do grafo\n");
    printf("\n5 - Caminho menimo entre estes dois vertices usando algoritmo de Djkstra\n");
    printf("\n6 - Caminho menimo entre estes dois vertices usando algoritmo de Floyd\n");
    printf("\n7 - Arvore Geradora Minima sobre o subgrafo vertice-induzido por X usando o algoritmo de Prim\n");
    printf("\n8 - Arvore Geradora Minima sobre o subgrafo vertice-induzido por X usando o algoritmo de Kruskal\n");
    printf("\n9 - Arvore dada pela ordem de caminhamento em profundidade a partir de ne dado paremetro, destacando as arestas de retorno\n");
    printf("\n\nPressione 0 para sair\n");
    while(input!='1'&&input!='2'&&input!='3'&&input!='4'&&input!='5'&&input!='6'&&input!='7'&&input!='8'&&input!='9'&&input!='0')
      scanf(" %c",&input);
    switch(input){
      case '1':
        g->function();
        break;
      case '2':
        g->function();
        break;
      case '3':
        g->function();
        break;
      case '4':
        g->function();
        break;
      case '5':
        g->function();
        break;
      case '6':
        g->function();
        break;
      case '7':
        g->function();
        break;
      case '8':
        g->function();
        break;
      case '9':
        g->function();
        break;
      case '0':
        return;  
    }
    menu(g);
}

int main(int argc, char **argv)
{
    /* if(argc != 6){
        std::cout << "Numero errado de argumentos" << std::endl;
        return -1;
    } */



    Graph *g = new Graph(argv);

    g->imprimeAdjacentes();

    menu(g);

    return 0;
}