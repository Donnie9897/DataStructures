#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int tam = 5;

typedef struct
{
    int posicion;
    int otrapos;
    int *pila;
    int tamano;
} Pila;



Pila *start();
void verificar(Pila *pila);
void Push(Pila *pila, int valor);
int pop(Pila *pila);
short isEmpty(Pila *pila);

int main()
{

    int var,i,cantidad = 0;
    Pila* miPila = start(miPila);


    do
    {
        printf("\nIngrese un valor ");
        scanf("%d",&var);

        if(var >= 0)
        {
            Push(miPila,var);
            cantidad++;
        }

    }while(var >= 0);

    for(i=0;i<cantidad;i++)
    {
        var = pop(miPila);
        printf("%d ",var);

    }



    return 0;
}

Pila *start()
{
    Pila *nuevapila = (Pila*)malloc(sizeof(Pila));
    nuevapila->posicion = 0;
    nuevapila->otrapos = 0;
    nuevapila->tamano = tam;
    nuevapila->pila = (int*)calloc(tam,sizeof(int));

    return nuevapila;
}

void verificar(Pila *pila)
{
    if(pila->posicion + 1 < pila->tamano)
        return;

    pila->pila = (int*)realloc(pila->pila, pila->tamano + tam);
    pila->tamano = pila->tamano+ tam;

}


void Push(Pila *pila, int valor)
{
    verificar(pila);


    *(pila->pila+pila->posicion) = valor;
    pila->posicion++;

}

int pop(Pila *pila)
{
    int valor = *(pila->pila+pila->otrapos);
    pila->otrapos++;

    return valor;

}


short isEmpty(Pila *pila)
{
    return pila -> posicion == 0;
}

