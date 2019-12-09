#include <stdio.h>
#include <stdlib.h>
#include "Monticulo.h"

int main()
{
    Heap* miHeap;
    miHeap = Inicializar(1);

    int n, k, i, j;
    float numero;
    printf("Digite la cantidad de elementos deseada ");
    scanf("%d",&n);

    float lista[n];
    printf("\nIngres el (k)esimo menor numero que desea buscar ");
    scanf("%d",&k);

    for(i=0;i<n;i++)
    {

        printf("\nIngrese el numero  ");
        scanf("%f",&lista[i]);
        Insertar(miHeap, lista[i]);

    }

    for(j=0;j<k-1;j++)
    {
        Poll(miHeap);
    }


    printf("\n\nEl (k)esimo menor numero es %.2f ",GetTop(miHeap));












/*
    for(int i=0;i<10;i++)
    {
        Insertar(miHeap, lista[i]);
    }

    printf("Top: %.2f\n\n",GetTop(miHeap));

    while(!isEmpty(miHeap))
    {
        printf("%.2f\n", Poll(miHeap));
    }
    */
    return 0;
}
