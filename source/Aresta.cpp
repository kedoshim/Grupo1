#include <iostream>
#include "../headers/Aresta.h"

Aresta::Aresta(int tail,int head,Aresta* endA, Aresta* endB,float p, int direcionado)
{
    Aresta* a;
    Aresta* b;
    idA=tail;
    idB=head;
    peso=p;
    endA->setNextAB(idA,this);
    endB->setNextAB(idB,this);

}

Aresta* Aresta::getNextAB(int id) //recebe o id do vertice raiz e devolve a pr�xima aresta ligada a esse id
{
    if(id==idA)
        return nextA;
    else if(id==idB)
        return nextB;
    else{
        printf("ERROR. SEM ID VALIDO\n setNextAB a:%d b:%d id:%d \n",idA,idB,id);
    }
}

void Aresta::setNextAB(int id,Aresta* endereco) //recebe o id do vertice raiz e define a pr�xima aresta ligada a esse vertice
{
    if(id==idA)
        nextA=endereco;
    else if(id==idB)
        nextB=endereco;
    else{
        printf("ERROR. SEM ID VALIDO\n setNextAB a:%d b:%d id:%d \n",idA,idB,id);
    }
}
