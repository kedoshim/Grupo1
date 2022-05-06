#include <iostream>
#include "Aresta.h"

Aresta* Aresta::getNextAB(int id)
{
    if(id==idA)
        return nextA;
    else if(id==idB)
        return nextB;
    else{
        printf("ERROR. SEM ID VALIDO\n");
    }
}
