#include <stdlib.h>
#include <stdio.h>
#include "Clase.h"
#include <conio.c>


int main()
{



   Cola *puntero;
   puntero = InicializarCola(puntero);
   float numero, otra;

   enqueue(puntero,2);
   enqueue(puntero,8);
   enqueue(puntero,7);

   for(otra=0;otra<3;otra++)
   {
        numero = dequeue(puntero);
        printf("%.2f ",numero);

   }


    return 0;
}
