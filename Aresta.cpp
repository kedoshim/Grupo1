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
    a.setNextAB(idA,this);
    b.setNextAB(idB,this);

}

Aresta* Aresta::getNextAB(int id) //recebe o id do vertice raiz e devole a próxima aresta ligada a esse id
{
    if(id==idA)
        return nextA;
    else if(id==idB)
        return nextB;
    else{
        printf("ERROR. SEM ID VALIDO\n");
    }
}
