#include <stdio.h>
#include <stdlib.h>
#include "Pilatriple.h"


int main()
{

    pilatriple *nueva = IniciarPila();

    float numero = 0, i;

    Push(nueva,0,22);

    Push(nueva,0,23);

    Push(nueva,1,24);

    Push(nueva,1,21);

    Push(nueva,2,20);

    Push(nueva,2,24);

    printf("%.2f ",Pop(nueva,0));

    printf("%.2f \nPrimera pila \n",Pop(nueva,0));

    printf("%.2f ",Pop(nueva,1));

    printf("%.2f \nSegunda pila \n",Pop(nueva,1));

    printf("%.2f ",Pop(nueva,2));

    printf("%.2f \nTercera pila ",Pop(nueva,2));



   return 0;
}



