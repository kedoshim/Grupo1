#include <iostream>
#include "Aresta.h"

Aresta::Aresta(int tail,int head,float p, int direcionado)
{
    Aresta* a;
    Aresta* b;
    a=UltimaAresta(tail);
    b=UltimaAresta(head);
    idA=tail;
    idB=head;
    peso=p;
    a->setNextAB(idA,this);
    b->setNextAB(idB,this);

}

Aresta* Aresta::getNextAB(int id) //recebe o id do vertice raiz e devolve a próxima aresta ligada a esse id
{
    if(id==idA)
        return nextA;
    else if(id==idB)
        return nextB;
    else{
        printf("ERROR. SEM ID VALIDO\n setNextAB a:%d b:%d id:%d \n",idA,idB,id);
    }
}

void Aresta::setNextAB(int id,Aresta* endereco) //recebe o id do vertice raiz e define a próxima aresta ligada a esse vertice
{
    if(id==idA)
        nextA=endereco;
    else if(id==idB)
        nextB=endereco;
    else{
        printf("ERROR. SEM ID VALIDO\n setNextAB a:%d b:%d id:%d \n",idA,idB,id);
    }
}
