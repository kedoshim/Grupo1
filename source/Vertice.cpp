#include "../headers/Vertice.h"

Vertice::Vertice(int id, float p, Vertice *anterior)
{
    ID = id;
    setPeso(p);
    setAnterior(anterior);
}
void Vertice::setProximo(Vertice *p)
{
    vproximo = p;
}
void Vertice::setAnterior(Vertice *a)
{
    vanterior = a;
    a->setProximo(this); // preciso do endere�o do Vertice que estou trabalhando agora. n sei c ta certo
}
void Vertice::setPeso(float p)
{
    peso = p;
}
int Vertice::getID()
{
    return ID;
}
Vertice* Vertice::getAnterior()
{
    return vanterior;
}
Aresta* Vertice::getAresta()
{
    return aresta;
}
Vertice *Vertice::getProximo()
{
    return vproximo;
}
