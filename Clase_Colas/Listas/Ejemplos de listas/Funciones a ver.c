w#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int dato;
    struct Nodo *siguiente;
}Nodo;

typedef struct Nodo nodo;

Nodo *crearPila(Nodo *pila);
int pilaVacia(nodo *pila);
Nodo *top(Nodo *pila);
Nodo *push(int valor,Nodo *pila);
Nodo *pop(Nodo *pila);
void imprimir(Nodo *pila);


int main()
{

    Nodo *pila;
    int valor,cantidad = 0,i;

    pila = crearPila(pila);

    do
    {
        printf("Digite un numero ");
        scanf("%d",&valor);

        if(valor > 0)
        {
            pila = push(valor,pila);
            cantidad++;
        }

        printf("\n");

    }while(valor > 0);

    printf("\n\n");

    while(!pilaVacia(pila))
    {
        pila = pop(pila);
        printf("Tope = %d\n",top(pila)->dato);
        imprimir(pila);
    }



    return 0;
}


Nodo *crearPila(Nodo *pila)
{
    return pila = NULL;
}

int pilaVacia(nodo *pila)
{
    if(pila == NULL)
        return 1;

    return 0;
}

Nodo *top(Nodo *pila)
{
    return pila;
}

Nodo *push(int valor,Nodo *pila)
{
    Nodo *nuevoNodo;

    nuevoNodo = (Nodo*)malloc(sizeof(Nodo));

    if(nuevoNodo != NULL)
    {
        nuevoNodo->dato = valor;
        nuevoNodo->siguiente = pila;
        pila = nuevoNodo;
    }

    return pila;
}

Nodo *pop(Nodo *pila)
{
    Nodo *aux;

    if(!pilaVacia(pila))
    {
        aux = pila;
        pila = pila->siguiente;
        free(aux);
    }

    return pila;
}

void imprimir(Nodo *pila)
{
    Nodo *auxi;

    auxi = pila;
    printf("contenido de la pila\n----------\n");

    while(auxi != NULL)
    {
        printf("%d\n",auxi->dato);
        auxi = auxi->siguiente;
    }

    printf("-----------");
}


