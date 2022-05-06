#include "Vertice.h"


Vertice::Vertice(int id,float p)
{
    ID=id;
    setPeso(p);
}
Vertice::Vertice(int id,float p, Vertice* anterior)
{
    ID=id;
    setPeso(p);
    setAnterior(anterior);

}
void Vertice::setProximo(Vertice* p)
{
    vproximo=p;
}
void Vertice::setAnterior(Vertice* a)
{
    vanterior=a;
    a->setProximo(this);//preciso do endereço do Vertice que estou trabalhando agora. n sei c ta certo
}
void Vertice::setPeso(float p)
{
    peso=p;
}
int Vertice::getID()
{
    return ID;
}
Vertice* Vertice::getProximo()
{
    return vproximo;
}
