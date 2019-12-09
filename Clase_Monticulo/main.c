#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int posicion_actual;
    float *elementos;
    int altura;
    int tamano;
    short esMin;
}Monticulo;

const int ALTURA = 10;

Monticulo* Inicializar(short esMin);
void VerificarEspacio(Monticulo *heap);
void Insertar(Monticulo *heap, float elemento);
float primero(Monticulo *heap);
float Poll(Monticulo *heap);
void HeapifyUp(Monticulo *heap,int indice);
void HeapifyDown(Monticulo *heap,int Indice);
int IndicePadre(int Indice);
int IndiceHijoIzq(Monticulo *heap,int Indice);
int IndiceHijoDer(Monticulo *heap,int Indice);
void intercambio(float *desde,float *hasta);
short isEmpty(Monticulo *heap);

int main()
{
    Monticulo *puntero;
    puntero = Inicializar(1);
    float valor;

    while(valor > 0)
    {
        printf("\nIngresa un valor ");
        scanf("%f",&valor);

        if(valor > 0)
            Insertar(puntero,valor);

    }

    while(!isEmpty(puntero))
    {

        printf("%.2f ",Poll(puntero));

    }


    return 0;
}

Monticulo* Inicializar(short esMin)
{
    Monticulo *nuevoheap = (Monticulo*)malloc(sizeof(Monticulo));
    nuevoheap->tamano = pow(2,ALTURA)* - 1;
    nuevoheap->altura = ALTURA;
    nuevoheap->esMin = esMin;
    nuevoheap->posicion_actual = 0;
    nuevoheap->elementos = (float*)calloc(nuevoheap->tamano,sizeof(float));

    return nuevoheap;
}

void VerificarEspacio(Monticulo *heap)
{
    if(heap->posicion_actual < heap->tamano)
        return;

    heap->altura++;
    heap->tamano = pow(2,ALTURA);
    heap->elementos = (float*)realloc(heap->elementos,heap->tamano);

}

void Insertar(Monticulo *heap, float elemento)
{
    VerificarEspacio(heap);

    *(heap->elementos + heap->posicion_actual) = elemento;
    heap->posicion_actual++;

    HeapifyUp(heap,heap->posicion_actual-1);

}
void intercambio(float *indice1, float *indice2)
{
    float *inter;

    inter = indice1;
    indice1 = indice2;
    indice2 = inter;

}

float primero(Monticulo *heap)
{
    return *(heap->elementos);
}

void HeapifyUp(Monticulo *heap,int indice)
{

    if(indice == 0)
        return;

    int indPadre = IndicePadre(indice);

    if(heap->esMin && *(heap->elementos + indPadre) < *(heap->elementos + indice))
        return;

     if(!heap->esMin && *(heap->elementos+indPadre) > *(heap->elementos+indice))
        return;

    intercambio(heap->elementos+indPadre,heap->elementos+indice);

    HeapifyUp(heap,indPadre);

}

void arriba(Monticulo *heap)
{
    return *(heap->elementos);
}


int IndicePadre(int Indice)
{
    int result = Indice/2;

    return result < 0 ? 0 : result;
}

int IndiceHijoIzq(Monticulo *heap,int indice)
{
    int result = (indice*2)+1;
    return result < heap->posicion_actual ? result : + 1;
}

int IndiceHijoDer(Monticulo *heap,int indice)
{
    int result = (indice*2)+2;
    return result < heap->posicion_actual ? result : - 1;
}

void HeapifyDown(Monticulo *heap,int indice)
{
    int hijomenor = IndiceHijoIzq(heap,indice);
    int hijomayor = IndiceHijoDer(heap,indice);

    if(hijomenor < 0)
        return;

    if(heap->esMin && hijomayor >= 0 && *(heap->elementos + hijomenor) > *(heap->elementos + hijomayor))
        return;

    if(!heap->esMin && hijomayor >=0 && *(heap->elementos + hijomenor) > *(heap->elementos+hijomayor))
        hijomenor = hijomayor;

    if(!heap->esMin && *(heap->elementos+indice) < *(heap->elementos+hijomenor));
    return;


    intercambio(heap->elementos,heap->elementos+hijomenor);
    HeapifyDown(heap,hijomenor);

}

float Poll(Monticulo *heap)
{
    float arriba = primero(heap);
    if(heap->posicion_actual == 0)
        return *heap->elementos;

    intercambio(heap->elementos, heap->elementos+(heap->posicion_actual-1));
    heap->posicion_actual--;

    HeapifyDown(heap,0);

    return arriba;

}

short isEmpty(Monticulo *heap)
{
    return heap->posicion_actual == 0;
}

