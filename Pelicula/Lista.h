#include <stdlib.h>
#include <stdio.h>

#ifndef _Listah
#define _Listah
#endif // _Listah

typedef struct
{
    int Id;
    char *Titulo;
    int anyo;
    char *clasificacion;
    float calificacion;
    float Duracion;
    int CantidadGeneros;
    char **Generos;
    char *Sinopsis;
}Peliculaslide;

typedef struct sNodo
{
    Peliculaslide data;
    struct sNodo *anterior;
    struct sNodo *siguiente;
}Nodo;

typedef struct
{
    Nodo *Cabeza;
    int Cantidad;
}Lista;

Lista* InicializarLista();
void AgregarPelicula(Peliculaslide, Nodo*);
void EliminarPelicula (Lista*,Nodo*);
void InsertarPelicula(Lista*,Peliculaslide);
Nodo* BuscarporID(Lista*,int);
Nodo* Buscarporanyo(Lista*,int);
Lista* OrdenarPeliculaSeleccion(Lista*);
Nodo* CopiaNodo(Nodo*);
void Intercambiar(Nodo*,Nodo*);



