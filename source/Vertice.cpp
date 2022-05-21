#include "../headers/Vertice.h"

Vertice::Vertice(int id, float p, Vertice *anterior)
{
    ID = id;
    setPeso(p);
}
void Vertice::aumentaGrau(int i)
{
    if (i > 0)
        grauOut++;
    else
        grauIn++;
}

void Vertice::setProximo(Vertice *p)
{
    vproximo = p;
}

void Vertice::setAnterior(Vertice *a) // pro primeiro vértice, tava dando erro, pq n tem como buscar o próximo de um nullptr
{
    vanterior = a;
    if (a != nullptr)
        a->setProximo(this); // preciso do endereco do Vertice que estou trabalhando agora. n sei c ta certo
}

void Vertice::setPeso(float p)
{
    peso = p;
}

int Vertice::getID()
{
    return ID;
}

Vertice *Vertice::getAnterior()
{
    return vanterior;
}

Aresta *Vertice::getAresta()
{
    return aresta;
}

Vertice *Vertice::getProximo()
{
    return vproximo;
}

string Vertice::getNome()
{
    return nome;
}

void Vertice::setNome(string n)
{
    nome = n;
}
