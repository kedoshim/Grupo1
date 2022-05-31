#include <bits/stdc++.h>
#include "../headers/Graph.h"

/*
argv[1] = entrada;
argv[2] = saida;
argv[3] = direcionado;
argv[4] = aresta ponderada;
argv[5] = nó ponderado
*/

int main(int argc, char **argv)
{
    /* if(argc != 6){
        std::cout << "Numero errado de argumentos" << std::endl;
        return -1;
    } */

    Graph *g = new Graph(argv);

    g->imprimeAdjacentes();

    return 0;
}