#include <stdio.h>
#include <stdlib.h>










int main()
{

    int opcion;
    int secuencial = 0;
    Cola *perros;
    Cola *gatos;
    perros = inicializarCola();
    gatos = inicializarCola();

    do
    {
        printf("1: Agregar perro. \n");
        printf("2: Agregar gato. \n");
        printf("3: Sacar perro. \n");
        printf("4: Sacar gato. \n");
        printf("0: Salir. \n");
        printf("Salir.");


    }while(opcion != 0);




    switch(opcion)
    {

    case 1:
        printf("%.2f ")





        ///para ambos;
    case 5:
        if(getFront(perros) < getFront(gatos))
            printf("%.2f\n",dequeue(perros));
        else
            printf("%.2f\n",dequeue(gatos));
    }




    return 0;
}


