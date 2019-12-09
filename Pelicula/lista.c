#include <stdlib.h>
#include "Lista.h"

Lista* InicializarLista()
{
    Lista *nuevaLista = (Lista*)malloc(sizeof(Lista));
    nuevaLista->Cantidad = 0;
    nuevaLista->Cabeza = (Nodo*)malloc(sizeof(Nodo));
    nuevaLista->Cabeza->data.Id = -1;
    nuevaLista->Cabeza->siguiente=nuevaLista->Cabeza;
    nuevaLista->Cabeza->anterior=nuevaLista->Cabeza;
    return nuevaLista;
}

void AgregarPelicula(Peliculaslide elemento, Nodo *despues)
{
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->data = elemento;
    nuevo->siguiente = despues->siguiente;
    nuevo->anterior = despues;
    despues->siguiente->anterior = nuevo;
    despues = nuevo;
}

Nodo* BuscarporID(Lista *listadoPeliculas,int id)
{
    Nodo *nodoActual = listadoPeliculas ->Cabeza->siguiente;

    while(nodoActual->data.Id != -1)
    {
        if(nodoActual->data.Id == id)
            return nodoActual;

        nodoActual = nodoActual->siguiente;
    }
    return NULL;
}

void EliminarPelicula(Lista *listadoPeliculas,Nodo *aEliminar)
{
    if(aEliminar->data.Id == -1)
        return;
    aEliminar->anterior->siguiente = aEliminar->siguiente;
    aEliminar->siguiente->anterior = aEliminar->anterior;
    free(aEliminar);
}

void InsertarPelicula(Lista*,Peliculaslide);

Nodo* Buscarporanyo(Lista *listadoPeliculas,int anyo)
{
    Nodo *nodoActual = listadoPeliculas->Cabeza->siguiente;

    while(nodoActual->data.Id != -1)
    {
        if(nodoActual->data.anyo > anyo)
            return nodoActual->anterior;

        nodoActual=nodoActual->siguiente;
    }
    return nodoActual->anterior;
}
Nodo* CopiaNodo(Nodo *original)
{
    Nodo *copia = (Nodo*)malloc(sizeof(Nodo));

    copia->data = original->data;
    copia->anterior = original->anterior;
    copia->siguiente = original->siguiente;

    return copia;
}
void Intercambiar(Nodo *primero,Nodo *segundo)
{
    Nodo *auxPrimero = CopiaNodo(primero);

    primero->anterior->siguiente = segundo;
    primero->anterior=segundo->anterior;
    primero->siguiente->anterior = segundo;
    primero->siguiente = segundo->siguiente;
    segundo->siguiente = auxPrimero->siguiente;
    segundo->anterior->siguiente = primero;
    segundo->anterior = auxPrimero->siguiente;
    primero->siguiente->anterior = primero;

    free(auxPrimero);
}



Lista* OrdenarPeliculaSeleccion(Lista *listadoPeliculas)
{
    Nodo *nodoActual = listadoPeliculas->Cabeza->siguiente;
    Nodo *nodoMenor;
    Nodo *Temporal;

    while(nodoActual->data.Id != -1)
    {
        nodoMenor = nodoActual;
        Temporal = nodoActual->siguiente;
        while (Temporal->data.Id != -1)
        {
            if(Temporal->data.anyo < nodoMenor->data.anyo)
            {
                nodoMenor = Temporal;
            }
            Temporal= Temporal->siguiente;

        }
        Intercambiar(nodoActual,nodoMenor);
        nodoActual = nodoActual->siguiente;
    }
}
