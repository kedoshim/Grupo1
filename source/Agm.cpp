#include "../headers/Agm.h"
#include "../headers/Vertex.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

Agm::Agm(){}
Agm::~Agm(){}

void Agm::insereVertice(Vertex* v) { // Insere vertice passando id
    this->nosAgm.push_back(v);
}

void Agm::insereAresta(Edge* a) { // Insere aresta passando id do vertice de origem, vertice alvo, e o peso
    this->arestasAgm.push_back(a);
}
