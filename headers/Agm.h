#ifndef AGM_H_INCLUDED
#define AGM_H_INCLUDED
#include "Vertex.h"
#include <list>
#include <vector>
#include <algorithm>

class Agm{
    public:
        Agm();
        ~Agm();

        std::list<Edge*> arestasAgm; // lista com arestas do grafo   
        std::list<Vertex*> nosAgm; //lista com nos do grafo    

        void insereVertice(Vertex* v); // Insere vertice passando id    
        void insereAresta(Edge* a); // Insere aresta passando id do vertice de origem, vertice alvo, e o peso

};
#endif //AGM_H_INCLUDED