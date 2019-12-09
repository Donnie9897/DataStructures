#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    struct nodo* siguiente;
    int dato;

} Nodo;

const int tama = 10;

Nodo *primer = NULL;
Nodo *aux = NULL;



void Push(int numero);
void Listado();
void MostrarEncabezadoHistograma();
void MostrarElementoHistograma(int,int,float);
void MostrarPieHistograma(int,int);


int main()
{
    int numero, i = 0;
    Nodo *puntero;
    float total = 0, cantidad = 0;


    do
    {
        printf("Ingrese un numero ");
        scanf("%d",&numero);

        if(numero>0)
        {
            Push(numero);
            total += numero;
            cantidad++;
        }


    }while(numero > 0);

    printf("\n\n");

//    Listado();

    MostrarEncabezadoHistograma();

    //while(cantidad>0)
    //{

    aux = primer;

        while(cantidad > 0)
        {
            i++;
            MostrarElementoHistograma(i,aux->dato,total);
            aux = aux->siguiente;
            cantidad--;

        }

    //}
    MostrarPieHistograma(i,total);






    return 0;
}

/*Push como pila*/
void Push(int numero)
{
    aux = (Nodo*)malloc(sizeof(Nodo));
    aux->dato = numero;
    if(primer == NULL)
    {
        primer=aux;
        aux->siguiente = NULL;
    }

    else
    {
        aux->siguiente = primer;
        primer = aux;
    }
}
/*Push como cola*/
void Push(int numero)
{
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = numero;

    if(primer == NULL)
    {
        primer=nuevo;
        primer->siguiente = NULL;
        ultimo = nuevo;
    }

    else
    {
        ultimo->siguiente = nuevo;
        nuevo->siguiente = NULL;
        ultimo = nuevo;
    }
}












/*Listado como pila*/
void Listado(Nodo *nodo)
{
    printf("Datos dentro de la pila ");
    aux = primer;

    while(aux != NULL)
    {
        printf("%d ",aux->dato);
        aux=aux->siguiente;

    }
    printf("NULL");

}


/*Listado como cola*/
void Listado(Nodo *nodo)
{
    printf("Datos dentro de la pila ");
    ultimo = primer;

    while(ultimo != NULL)
    {
        printf("%d ",ultimo->dato);
        ultimo=ultimo->siguiente;

    }
    printf("NULL");

}

/*UN LISTADO*/
/*
void Listado(Nodo *nodo)
{
    printf("Datos dentro de la pila ");
    aux = primer;

    while(aux != NULL)
    {
        printf("%d ",aux->dato);
        aux=aux->siguiente;

    }
    printf("NULL");

}
*/
