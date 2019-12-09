#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <conio.c>
#include "Lista.h"


typedef enum
{
    Salir = 0,
    Agregar = 1,
    Modificar,
    Eliminar,
    Insertar,
    Explorar,
    Buscar,
    Ordenar


} eSeleccionMenu;

void MostrarMarco();
void MostrarMarco3Columnas();
eSeleccionMenu MostrarMenu();
void CapturarPelicula(Lista *, Nodo*,short);
void ExplorarPeliculas(Lista*,Nodo*);
void MostrarPEliculaEnColumna(Peliculaslide,int);
void MostrarSinopsis(int col,int fil,int limite, char *texto);
void ModificarPelicula(Lista*);
void BorrarPelicula(Lista*);
void BuscarPeliculaPorAnyo(Lista*);
Nodo* BuscarporID(Lista*,int);
void OrdenarPeliculasPorAnyo(Lista*);
const int COL2 = 26,COL3 = 52;

int main()
{

    Lista *listadoPeliculas = InicializarLista();
    eSeleccionMenu opcionActual;

    do
    {
        opcionActual = MostrarMenu();

        switch(opcionActual)
        {
        case Agregar:
            CapturarPelicula(listadoPeliculas,NULL, 1);
            break;
        case Modificar:
            ModificarPelicula(listadoPeliculas);
            break;
        case Eliminar:
            BorrarPelicula(listadoPeliculas);
            break;
        case Insertar:
            CapturarPelicula(listadoPeliculas,NULL, 1);
            break;
        case Explorar:
            ExplorarPeliculas(listadoPeliculas,NULL);
            break;
        case Buscar:
            BuscarPeliculaPorAnyo(listadoPeliculas);
            break;
        case Ordenar:
            OrdenarPeliculasPorAnyo(listadoPeliculas);
            break;

        }
    }
    while(opcionActual != Salir);

    gotoxy(40,24);
    return 0;
}

void MostrarMarco()
{
    int i;
    system("cls");
    printf("%c",201);

    for(i = 0; i < 47; i++)
        printf("%c",205);
    printf("%c\n",187);
    for(i = 0; i < 29; i++)
        printf("%c\t\t\t\t\t\t%c\n",186,186);

    printf("%c",200);
    for(i = 0; i < 47; i++)
        printf("%c",205);
    printf("%c",188);

}
eSeleccionMenu MostrarMenu()
{
    int seleccion;
    do
    {
        MostrarMarco();
        gotoxy(13,3);
        printf("Gesti%cn de Pel%cculas",162,161);
        gotoxy(5,7);
        printf("1:Agregar una pel%ccula al final",161);
        gotoxy(5,9);
        printf("2:Modificar una pelicula dado un ID");
        gotoxy(5,11);
        printf("3:Eliminar una pelicula dado un ID");
        gotoxy(5,13);
        printf("4:Agregar una pelicula en orden de ano");
        gotoxy(5,15);
        printf("5:Explorar las peliculas registradas");
        gotoxy(5,17);
        printf("6:Buscar una pelicula por ano");
        gotoxy(5,19);
        printf("7:Ordenar pelicula por ano");
        gotoxy(5,22);
        printf("0:Salir de la aplicacion");

        fflush(stdin);
        _setcursortype(0);
        seleccion = getch() - 48;
    }
    while (seleccion < 0 || seleccion > 7);

    _setcursortype(1);
    return seleccion;
}

void CapturarPelicula(Lista *listado, Nodo *aModificar,short enOrden)
{
    short generosSeleccionados[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int seleccion,i,j = 0;
    Peliculaslide nuevaPelicula;
    system("cls");
    MostrarMarco();
    gotoxy(3,3);
    if(aModificar == NULL)
        printf("Agregando nueva pelicula al final de la lista");
    else
        printf("Modificando pelicula existente");
    gotoxy(3,8);
    printf("Id:");
    if(aModificar != NULL)
    {
        printf("%d",aModificar->data.Id);
        nuevaPelicula.Id = aModificar->data.Id;
    }
    else
        scanf("%d",&nuevaPelicula.Id);
    gotoxy(3,9);
    printf("Titulo:");
    nuevaPelicula.Titulo = (char*)malloc(100);
    fflush(stdin);
    gets(nuevaPelicula.Titulo);
    gotoxy(3,10);
    printf("A%co:",164);
    scanf("%d",&nuevaPelicula.anyo);
    do
    {
        gotoxy(3,11);
        printf("Seleccione una clasificacion: \n\t\t");
        gotoxy(3,13);
        printf("1: G(proposito general)\n");
        gotoxy(3,15);
        printf("2: PG(supervision parental)\n");
        gotoxy(3,17);
        printf("3: PG-13(no apta para menores de 13 anos)\n");
        gotoxy(3,19);
        printf("4: R(restringido para mayor de edad)\n");
        gotoxy(3,21);
        printf("5: NC-17(solo adultos)\n");
        gotoxy(3,23);
        printf("Seleccione: ");
        seleccion = getch() - 48;
    }
    while (seleccion < 1 || seleccion > 5);
    nuevaPelicula.clasificacion= (char*)calloc(6,sizeof(char));
    switch(seleccion)
    {
    case 1:
        strcpy(nuevaPelicula.clasificacion,"G");
        break;
        printf("Id:");
        scanf("%d",&nuevaPelicula.Id);
    case 2:
        strcpy(nuevaPelicula.clasificacion,"PG");
        break;
    case 3:
        strcpy(nuevaPelicula.clasificacion,"PG-13");
        break;
    case 4:
        strcpy(nuevaPelicula.clasificacion,"R");
        break;
    case 5:
        strcpy(nuevaPelicula.clasificacion,"NC-17");
        break;
    }
    gotoxy(3,24);
    printf("Calificacion:");
    scanf("%f",&nuevaPelicula.calificacion);
    gotoxy(3,25);
    printf("Duracion:(minutos)");
    scanf("%f",&nuevaPelicula.Duracion);

    do
    {
        do
        {
            gotoxy(50,7);
            printf("Seleccione los generos de la pelicula:\n");
            gotoxy(50,8);
            printf("1:Accion\n");
            gotoxy(50,9);
            printf("2:Aventura\n");
            gotoxy(50,10);
            printf("3:Comedia\n");
            gotoxy(50,11);
            printf("4:Drama\n");
            gotoxy(50,12);
            printf("5:Terror\n");
            gotoxy(50,13);
            printf("6:Musical\n");
            gotoxy(50,14);
            printf("7:Ciencia ficcion\n");
            gotoxy(50,15);
            printf("8:Suspenso\n");
            gotoxy(50,16);
            printf("9:Infantil\n");
            gotoxy(50,17);
            printf("0:Salir\n\n");
            gotoxy(50,18);
            printf("Seleccione: ");
            fflush(stdin);
            seleccion = getch() - 48;
        }
        while(seleccion < 0 || seleccion > 9);

        if (seleccion != 0 && generosSeleccionados[seleccion - 1] > 0)
        {
            generosSeleccionados[seleccion -1 ] = 0;
            j--;
        }
        else if (seleccion != 0 && generosSeleccionados[seleccion - 1] <= 0)
        {
            generosSeleccionados[seleccion -1 ] = 1;
            j++;
        }
    }
    while (seleccion != 0);

    nuevaPelicula.CantidadGeneros = j;
    nuevaPelicula.Generos = (char**)malloc(sizeof(char*)*j);
    for(i=0,j = 0; i<9; i++)
    {
        if (generosSeleccionados[i])
        {
         j++;
//            nuevaPelicula.Generos = (char**)malloc(sizeof(char*));
            *(nuevaPelicula.Generos+j) = (char*)calloc(20,sizeof(char));
            switch(i)
            {
            case 0:
                strcpy(*(nuevaPelicula.Generos+j),"Accion");
                break;
            case 1:
               strcpy(*(nuevaPelicula.Generos+j),"Aventura");
               break;
            case 2:
                strcpy(*(nuevaPelicula.Generos+j),"Comedia");
                break;
            case 3:
                strcpy(*(nuevaPelicula.Generos+j),"Drama");
                break;
            case 4:
                strcpy(*(nuevaPelicula.Generos+j),"Terror");
                break;
            case 5:
                strcpy(*(nuevaPelicula.Generos+j),"Musical");
                break;
            case 6:
                strcpy(*(nuevaPelicula.Generos+j),"Ciencia ficcion");
                break;
            case 7:
                strcpy(*(nuevaPelicula.Generos+j),"Suspenso");
                break;
            case 8:
                strcpy(*(nuevaPelicula.Generos+j),"Infantil");
                break;
            }
        }
    }

    printf("\tSinopsis:");
    nuevaPelicula.Sinopsis = (char*)malloc(200);
    fflush(stdin);
    gets(nuevaPelicula.Sinopsis);

    if(aModificar == NULL && !enOrden)
        AgregarPelicula(nuevaPelicula);

    else if(aModificar == NULL && enOrden)
    {
        Nodo *despues = BuscarPeliculaPorAnyo(lsitado,nuevaPelicula.anyo);
        AgregarPelicula(nuevaPelicula,despues);

    }
    else
    {
        aModificar->data = nuevaPelicula;
    }
}
void MostrarMarco3Columnas()
{
    int i;
    system("cls");
    printf("%c",201);

    for(i = 0; i < 24; i++)
        printf("%c",205);
    printf("%c",203);

    for(i = 0; i < 25; i++)
        printf("%c",205);
    printf("%c",203);

    for(i = 0; i < 25; i++)
        printf("%c",205);
    printf("%c\n",187);

    for(i = 2; i < 24; i++)
    {
        gotoxy(0,i);
        printf("%c",186);
        gotoxy(COL2,i);
        printf("%c",186);
        gotoxy(COL3,i);
        printf("%c",186);
        gotoxy(78,i);
        printf("%c\n",186);
    }
    printf("%c",200);

    for(i = 0; i < 24; i++)
        printf("%c",205);
    printf("%c",202);

    for(i = 0; i < 25; i++)
        printf("%c",205);
    printf("%c",202);

    for(i = 0; i < 25; i++)
        printf("%c",205);
    printf("%c\n",188);
}

void ExplorarPeliculas(Lista *listado, Nodo *aConsultar)
{
    char seleccion;

    Nodo *nodoActual;
    if (aConsultar == NULL)
           nodoActual = listado->Cabeza->siguiente;
    else
        nodoActual = aConsultar;

    do
    {
        MostrarMarco3Columnas();

        if(nodoActual->data.Id == -1)// if(listado->Cantidad == 0)
        {
            printf("No hay peliculas registradas");
            break;
        }
        MostrarPEliculaEnColumna(nodoActual->data,2);
        if(nodoActual->anterior->data.Id == -1)
            MostrarPEliculaEnColumna(nodoActual->anterior->anterior->data,1);
        else
            MostrarPEliculaEnColumna(nodoActual->anterior->anterior->data,1);
        if (nodoActual->siguiente->data.Id == -1)
            MostrarPEliculaEnColumna(nodoActual->siguiente->siguiente->data,3);
        else
            MostrarPEliculaEnColumna(nodoActual->siguiente->siguiente->data,3);
        fflush(stdin);
        gotoxy(1,25);
        printf("X: para salir. A:anterior. D:Siguiente.");
        seleccion = getch();
        if (tolower(seleccion)=='a')
        {
            nodoActual=nodoActual->anterior;
            if(nodoActual->data.Id == -1)
                nodoActual = nodoActual->anterior;
        }
        else if(tolower(seleccion)== 'd')
        {
            nodoActual = nodoActual->siguiente;
            if(nodoActual->data.Id == -1)
                nodoActual = nodoActual->siguiente;
        }
    }
    while(tolower(seleccion != 'x'));
}

void MostrarPEliculaEnColumna(Peliculaslide aMostrar,int numeroColumna)
{
    int colActual,i=0,LIMCOLUMNA = 24;
    if(numeroColumna==1)
        colActual = 0;
    else if (numeroColumna == 2)
        colActual = COL2;
    else
        colActual = COL3;

    gotoxy(colActual + 1,3);
    printf("%.3d - %.*s\n",aMostrar.Id,LIMCOLUMNA,aMostrar.Titulo);

    gotoxy(colActual + 1,5);
    printf("%d\n%.1f/10\n%.1fmins.",aMostrar.anyo,aMostrar.calificacion,aMostrar.Duracion);
    gotoxy(colActual + 1,7);
    printf("Clasif.:%.20s",aMostrar.clasificacion);
    gotoxy(colActual + 1,9);
    while(i < aMostrar.CantidadGeneros) // o EOF;
    {
        printf("%.*s",LIMCOLUMNA,*(aMostrar.Generos+i));
        i++;
        gotoxy(colActual + 1,9+i);
    }
    gotoxy(colActual + 1,10+i);
    MostrarSinopsis(colActual+1,10+i,LIMCOLUMNA,aMostrar.Sinopsis);
}

void MostrarSinopsis(int col,int fil,int limite, char *texto)
{
    int i=0,tamano = strlen(texto);
    char *nuevoTexto = (char*)malloc(sizeof(char*));
    while(tamano>0)
    {
        gotoxy(col,fil+i);
        printf("%.*s",limite,texto);
        nuevoTexto = strcpy(nuevoTexto,nuevoTexto+limite);

        i++;
        tamano -= limite;
    }
    gotoxy(col,fil+i);
}

void ModificarPelicula(Lista *listadoPeliculas)
{
    int idPelicula;
    Nodo *nodoActual;
    system("cls");
    MostrarMarco();
    gotoxy(10,3);
    printf("Modificando pelicula existente.");
    gotoxy(5,7);
    printf("Digite el ID:");
    scanf("%d",&idPelicula);
    nodoActual = BuscarporID(listadoPeliculas,idPelicula);

    if (nodoActual == NULL)
    {
        gotoxy(5,9);
        printf("Esta pelicula no existe. Presione cualquier tecla para continuar");
        fflush(stdin);
        getch();
        return;
    }
    CapturarPelicula(listadoPeliculas,nodoActual);
}

void BorrarPelicula(Lista *listadoPeliculas)
{
    int idPelicula;
    Nodo *nodoActual;
    system("cls");
    MostrarMarco();
    gotoxy(10,3);
    printf("Eliminar pelicula existente.");
    gotoxy(5,7);
    printf("Digite el ID:");
    scanf("%d",&idPelicula);
    nodoActual = BuscarporID(listadoPeliculas,idPelicula);

    if (nodoActual == NULL)
    {
        gotoxy(5,9);
        printf("Esta pelicula no existe. Presione cualquier tecla para continuar");
        fflush(stdin);
        getch();
        return;
    }
    EliminarPelicula(listadoPeliculas,nodoActual);
}

void BuscarPeliculaPorAnyo(Lista *listadoPeliculas)
{
    int anyo;
    Nodo *nodoActual;
    system("cls");
    MostrarMarco();
    gotoxy(10,3);
    printf("Buscando pelicula por anyo existente.");
    gotoxy(5,7);
    do
    {
        printf("Digite el anyo:");
        scanf("%d",&anyo);
        if (anyo<0)
                printf("El anyo no puede ser negativo.");
    }while (anyo<0);

    nodoActual = Buscarporanyo(listadoPeliculas,anyo);

    if (nodoActual == -1)
    {
        gotoxy(5,9);
        printf("La lista esta vacia. Presione cualquier tecla para continuar");
        fflush(stdin);
        getch();
        return;
    }
}

void OrdenarPeliculasPorAnyo(Lista *listadoPeliculas)
{
//    Nodo* uno = listadoPeliculas->Cabeza->siguiente;
//    Nodo* dos = listadoPeliculas->Cabeza->anterior;
//
//    printf("\n%d - %s // %d - %s\n",uno->data.Id,uno->data.Titulo,dos->data.Id,dos->data.Titulo);
//
//    Intercambiar(uno, dos);
//    uno = listadoPeliculas->Cabeza->siguiente;
//    dos = listadoPeliculas->Cabeza->anterior;
//
//    printf(" %d - %s // %d - %s\n",uno->data.Id,uno->data.Titulo,dos->data.Id,dos->data.Titulo);
//    fflush(stdin);
//    getch();

    OrdenarPeliculaSeleccion(listadoPeliculas);
}
