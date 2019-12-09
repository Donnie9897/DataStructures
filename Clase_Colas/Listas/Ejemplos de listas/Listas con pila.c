#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int tamanopila;
    struct nodo* siguiente;
    int dato;
    int Posicionactual;

}Nodo;

const int tama = 10;


Nodo *primer = NULL;
Nodo *ultimo = NULL;

void Agregar(Nodo *nodo);
Nodo* IniciarNodo(Nodo *nodo, int numero);
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
    int i, cantidad = 2, numero, nuevoValor, total = 0;

    cabecera = (Nodo*)malloc(sizeof(Nodo));
    cabecera->dato = 11;
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

    Nodo *it = cabecera;

    while(it != NULL)
    {
        printf("%d ",it->dato);
        it = it->siguiente;
    }

/*
    MostrarEncabezadoHistograma();
    while(!isEmpty(cabecera))
    {
        cantidad++;
        nuevoValor = Pop(cabecera);
        MostrarElementoHistograma(cantidad,nuevoValor,nuevoValor/total*100);
    }
    MostrarPieHistograma(cantidad,total);
*/
    return 0;
}



void Agregar(Nodo *nodo)
{
    nodo->siguiente = NULL;

    if(primer == NULL)
    {
        primer = nodo;
        ultimo = nodo;
    }

    else
    {
        ultimo->siguiente = nodo;
        ultimo = nodo;
    }

}

Nodo* IniciarNodo(Nodo* nodo, int numero)
{
    Nodo *apuntador;
    apuntador = (Nodo*)malloc(sizeof(Nodo));
    apuntador->dato = numero;
    Agregar(apuntador);

    return apuntador;

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
