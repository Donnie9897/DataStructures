#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int tamanopila;
    int dato;
    struct nodo *siguiente;
    struct nodo *cabeza;
    int Posicionactual;

}Nodo;
/*
typedef struct
{
    Nodo *cabeza;
}lista;
*/
const int tama = 10;


Nodo* Inicializar();
Nodo* IniciarNodo(Nodo *nodo, int numero);
void Push(Nodo *nodo, int numero);
void Verificarespacio(Nodo*);
int Pop(Nodo *nodo);
Nodo *creanodo(void);
short isEmpty(Nodo *nodo);

void MostrarEncabezadoHistograma();
void MostrarElementoHistograma(int,float,float);
void MostrarPieHistograma(int,float);

int main()
{

    Nodo *cabecera = NULL;
    Inicializar(cabecera);
    int i, cantidad = 2,numero, nuevoValor, total = 0;

    cabecera = (Nodo*)malloc(sizeof(Nodo));
    cabecera->dato = 11;
    cabecera->siguiente = cabecera->dato;
    //cabecera = IniciarNodo(cabecera,6);
    //cabecera = IniciarNodo(cabecera,7);

    do
    {
        printf("Digite un valor (-1 para terminar):");
        scanf("%d",&nuevoValor);


        if(nuevoValor >=0)
        {
         cabecera->dato = nuevoValor;
         //cabecera->sig = cabecera;
         IniciarNodo(cabecera,nuevoValor);
         total += nuevoValor;
         //cantidad++;
        }
    }while(nuevoValor >=0 );


    for(i=0;i<cantidad;i++)
    {
        printf("%d ",Pop(cabecera));
    }


    MostrarEncabezadoHistograma();
    while(!isEmpty(cabecera))
    {
        cantidad++;
        nuevoValor = Pop(cabecera);
        MostrarElementoHistograma(cantidad,nuevoValor,nuevoValor/total*100);
    }
    MostrarPieHistograma(cantidad,total);

    return 0;
}


Nodo* Inicializar()
{
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->tamanopila = 10;
    nuevo->Posicionactual = 0;

    return nuevo;

}

Nodo* IniciarNodo(Nodo* nodo, int numero)
{
    Nodo *apuntador;
    apuntador = (Nodo*)malloc(sizeof(Nodo));
    apuntador->dato = numero;
    apuntador->siguiente = NULL;

    apuntador->siguiente = apuntador->cabeza;
    apuntador->cabeza = apuntador;
    //apuntador->tamanopila++;
    //apuntador->Posicionactual++;
    return apuntador;

}


void Push(Nodo *nodo, int numero)
{
    Nodo *nodito = IniciarNodo(nodito,numero);

    nodito->siguiente = nodito->cabeza;
    nodito->cabeza = nodito;

}

void InsertarFinal(Nodo *nodo, int numero)
{
    Nodo *nodito = IniciarNodo(nodito,numero);
    Nodo *puntero = nodo->cabeza;


}


int Pop(Nodo *nodo)
{
    return nodo->dato;
}


void MostrarEncabezadoHistograma()
{
    system("cls");
    printf("HISTOGRAMA\n\n");
    printf("No.:\tValor:\tProporci%cn:\n",162);
}
void MostrarElementoHistograma(int secuencia,float valor,float proporcion)
{
    int cantidadCaracteres = (int)proporcion;
    printf("%d\t%.2f\t",secuencia,valor);

    while(cantidadCaracteres-- > 0)
        printf("%c",254);

    printf("%.2f%%\n",proporcion);

}
void MostrarPieHistograma(int cantidad,float total)
{
    printf("Se han mostrado %d elementos. Total : %.2f", cantidad,total);
}


short isEmpty(Nodo *nodo)
{
    return nodo -> Posicionactual == 0;
}
