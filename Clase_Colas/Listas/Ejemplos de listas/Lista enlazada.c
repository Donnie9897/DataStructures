#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dato;
    struct Nodo *siguiente;
} Nodo;

Nodo *primero = NULL;
Nodo *ultimo = NULL;
int cantidad = 0;

Nodo *IniciarNodo(int dato);
void InsertarInicio(int dato);
void InsertarFinal(int dato);
void InsertarMedio(int dato, int);
void Imprimir();

int main()
{


    InsertarInicio(71);
    InsertarInicio(72);
    InsertarMedio(80,2);
    InsertarFinal(88);
    InsertarFinal(89);
    Imprimir();


    return 0;
}



void InsertarInicio(int dato)
{
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = dato;

    if(nuevo != NULL)
    {
        //nuevo->siguiente = primero;
        primero = nuevo;
        nuevo->siguiente = NULL;
        ultimo = nuevo;
        cantidad++;
    }

}


void InsertarFinal(int dato)
{
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = dato;


    if(primero != NULL)
    {
        // while(nuevo->siguiente != NULL)
        //  nuevo = nuevo->siguiente;

        ultimo->siguiente = nuevo;
        nuevo->siguiente = NULL;
        ultimo = nuevo;
        cantidad++;

    }

    return 0;
}


void InsertarMedio(int dato,int posicion)
{
    Nodo *temp = (Nodo*)malloc(sizeof(Nodo));
    temp->dato = dato;
    int i;
    Nodo *aux;
    Nodo *aux2;
    aux = primero;

    for(i=1;i<posicion;i++)
    {
        aux2 = aux;
        aux = aux->siguiente;
    }


    temp->siguiente = aux;
    aux2->siguiente = temp;





}

void Imprimir()
{
    Nodo *aux = primero;

    while(aux != NULL)
    {
        printf("%d ",aux->dato);
        aux = aux->siguiente;
    }

}
