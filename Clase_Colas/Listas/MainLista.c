#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"


int main()
{
    Nodo *pila;
    pila = IniciarPila(pila);

    Push(pila,23);
    Push(pila,24);
    Push(pila,22);

    printf("%.2f ",Pop(pila));

    printf("%.2f ",Pop(pila));

    printf("%.2f ",Pop(pila));





    return 0;
}
