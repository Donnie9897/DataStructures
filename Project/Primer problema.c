#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Solucion
Para este problema, luego de crear el arreglo, se crea en el registro tres posicines, la primera empieza desde 0 y llega hasta
un tercio del tamaño del arreglo, para luego la segunda posicion empieza donde queda la primera y recorre otro tercio del
arreglo, ya para la ultima igual, empieza donde quedo la segunda y termina hasta el final, si se empizan a sacar valores
la posicion vuelvo a 0 para rellenar lo vacio.
*/


typedef struct
{
    float *elementos;
    int posicion;
    int posicion2;
    int posicion3;
    int primerind;
    int tamano;
    int cantidadele;

} Pila;

const int tam = 40;

Pila* Iniciar();
void verificacion(Pila *pila);
void Push(Pila *pila,float valor);
float pull(Pila *pila);
short isEmpty(Pila *pila);
void push2(Pila *pila,float valor);

int main()
{

    Pila *puntero;
    puntero = Iniciar(puntero);
    float valor;
    int cantidad = 0;


    do
    {
        printf
        ("\nIngrese un valor (1/3 del arreglo se llenara) ");
        scanf("%f",&valor);

        if(valor > 0)
        {
            Push(puntero,valor);
            cantidad++;
        }

    }
    while(cantidad < tam / 3);

    do
    {
        printf
        ("\nIngrese un valor (1/3 del arreglo se llenara) ");
        scanf("%f",&valor);

        if(valor > 0)
        {
            Push(puntero,valor);
            cantidad++;
        }

    }
    while(cantidad < tam/3);



    printf("\n\n");

    while(!isEmpty(puntero))
    {
        valor = pull(puntero);
        printf("%.2f ",valor);
        cantidad++;
    }
    printf("\n\n");


    return 0;
}

Pila* Iniciar()
{
    Pila *newstack = (Pila*)malloc(sizeof(Pila));
    newstack->posicion = 0;
    newstack->tamano = tam;
    newstack->elementos = (float*)malloc(tam*sizeof(float));


    return newstack;
}

void verificacion(Pila *pila)
{
    if(pila->posicion > pila->tamano)
        return;

    pila->elementos = (float*)realloc(pila->elementos, pila->tamano + tam);
    pila->tamano = pila->tamano + tam;

}

void Push(Pila *pila,float valor)
{
    verificacion(pila);

    if(pila->posicion > pila->tamano)
    {
        pila->posicion = 0;
        ///se ha llenado
    }

    if(pila->posicion == pila->tamano/3)
    {
        push2(pila,valor);
        printf("Se ha llenado la primera pila ");
    }
    *(pila->elementos + pila->posicion) = valor;

    pila->posicion++;
}

void push2(Pila *pila,float valor)
{
    verificacion(pila);

    if(pila->posicion < pila->tamano/3)
        return;
    pila->posicion2 = pila->posicion;

    *(pila->elementos + pila->posicion2) = valor;

    pila->posicion2++;

    if(pila->posicion2 == pila->tamano/3)
    {
        push3(pila,valor);
        printf("Se ha llenado la segunda pila");
    }

}

void push3(Pila *pila,float valor)
{
    verificacion(pila);

    if(pila->posicion2 < pila->tamano/3)
        return;

    pila->posicion3 = pila->posicion2;

    *(pila->elementos + pila->posicion2) = valor;

    pila->posicion3++;

    if(pila->posicion3 == pila->tamano/3)
    {
        push3(pila,valor);
        printf("Se ha llenado la segunda pila");
    }

}




float pull(Pila *pila)
{
    float retorno;

    retorno = *(pila->elementos + pila->posicion-1);
    pila->posicion--;

    return retorno;
}

short isEmpty(Pila *pila)
{
    return pila -> posicion == 0;
}
