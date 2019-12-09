#include <stdlib.h>
#include <stdio.h>
#include "Clase.h"
#include <conio.c>



int main()
{
    int opcion, resp, numero, contador = 0;
    int jaula[90], i = 0;
    int *perros;
    int *gatos;
    perros = InicializarCola(perros);
    gatos = InicializarCola(gatos);

    do
    {


    printf("Encolar animal \n");
    printf("Decolar animal \n");
    printf("Mostrar animal \n");
    printf("salir \n");

    scanf("%d",&opcion);


    printf("\n");
    switch(opcion)
    {
    case 1:
        do
        {
            printf("Presione (5) para encolar un perro y (6) para encolar un gato ");
            scanf("%d",&resp);
        }while(resp != 5 && resp != 6);

        if(resp ==  5)
        {
            if(isEmpty(perros))
            {
                printf("No hay perros ");
                return;
            }
            printf("\nIngrese el perro ");
            scanf("%d",&numero);
            enqueue(perros,numero);
            jaula[i] = numero;
            i++;
            contador++;
            printf("\nHa ingresado un perro al refugio.");
        }
        else if(resp == 6)
        {
            printf("\nIngrese el gato ");
            scanf("%d",&numero);
            enqueue(gatos,numero);
            jaula[i] = numero;
            i++;
            contador++;
            printf("\nHa ingresado un gato al refugio.");
        }

        break;

    case 2:
        printf("\nDecolar Perro (5)");
        printf("\nDecolar gato (6)");
        printf("\nDecolar cualquiera (7)\n");
        scanf("%d",&resp);

        if(resp == 5)
        {
            numero = dequeue(perros);
            printf("Se muestra: %d",numero);
            contador--;
            i--;
        }

        else if(resp == 6)
        {
            numero = dequeue(gatos);
            printf("Se muestra: %d",numero);
            contador--;
            i--;
        }

        else if(resp == 7)
        {
            if(jaula[i] > jaula[i -1 ])
            {
                numero = jaula[i];
                printf("Se muestra: %d",numero);
            }
            contador--;
            i--;
        }

        break;

    case 3:
        break;

    case 4:
        break;

    }

    printf("\n\n");

    }while(opcion != 0);


}
