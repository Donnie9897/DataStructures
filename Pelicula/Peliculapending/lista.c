#include <stdlib.h>
#include "Lista.h"

Lista* Inicializar()
{
    Lista *Nuevalista = (Lista*)malloc(sizeof(Lista));
    Nuevalista->Cantidad = 0;
    Nuevalista->Cabeza = (NODO*)malloc(sizeof(NODO));
    Nuevalista->Cabeza->data.Id = -1;
    Nuevalista->Cabeza->siguiente = Nuevalista->Cabeza;
    Nuevalista->Cabeza->anterior = Nuevalista->Cabeza;

    return Nuevalista;
}

void AgregarPelicula(Lista*listado,Pelicula elemento)
{
    NODO *nuevo = (NODO*)malloc(sizeof(NODO));
    nuevo->data = elemento;
    nuevo->siguiente = listado->Cabeza;
    nuevo->anterior = listado->Cabeza->anterior;
    listado->Cabeza->anterior->siguiente = nuevo;
    listado->Cabeza->anterior = nuevo;
}


void EliminarPelicula(Lista *listadopeliculas,NODO *aEliminar)
{
    if(aEliminar->data.Id == -1)
        return;

    aEliminar->anterior->siguiente = aEliminar->siguiente;
    aEliminar->siguiente->anterior = aEliminar->anterior;
    free(aEliminar);

}

NODO* BuscarporId(Lista *listadoPeliculas,int id)
{
    NODO *nodoactual = listadoPeliculas->Cabeza->siguiente;

    while(nodoactual->data.Id != -1)
    {
        if(nodoactual->data.Id == id)
            return nodoactual;

        nodoactual = nodoactual->siguiente;

    }

    return NULL;
}

