#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* Solucioncita:
Para la solucion de este problema, se crearann dos listas, o colas, una para los perros y otra para los gatos, donde se
van a ingresar los animales uno por uno (o sea, como si fuera una cantidad) estos seran enviados al un monticulo el cual
es un Maxheap, que devolvera al mayor de ellos para su adopcion
*/
typedef struct
{
    int altura;
    int tamano;
    int posicionActual;
    short esMin;
    float* elemento;
    int indperro;
    int indgato;
    int anos;


} Monti;


const int tam = 80;


Cola* InicializarCola();
Monti* Inicializar(short esMin);
void encolarperro(Cola *cola,float elemento);
float desencolarperro(Cola *cola);
void encolargato(Cola *cola,float elemento);
float desencolargato(Cola *cola);
void VerificarEspacio(Monti* heap);
void Insertar(Monti* heap, float elemento);
int IndicePadre(int indice);
int IndiceHijoIzquierdo(Monti* heap, int indice);
int IndiceHijoDerecho(Monti* heap, int indice);
void Swap(float* desde, float* hasta);
void HeapifyUp(Monti* heap, int indice);
void HeapifyDown(Monti* heap, int indice);
float GetTop(Monti* heap);
float Poll(Monti* heap);
short isEmpty(Monti* heap);

int main()
{

    Monti* mimonti;
    mimonti = Inicializar(0);
    float lista[10] = {5,10,20,35,2,8,15,100,9,1};

    int *perros;
    int *gatos;
    int i,j, perro1,gato1;
    int anos;

    perros = InicializarCola();
    gatos = InicializarCola();

    do
    {
        printf("Se crear%c la lista de perros, digite numero por numero los mismos ",160);
        scanf("%d",&valor);

        push(perros,perro1);



    }
    while(cantidad < tama - 80);

    for(int i=0; i<10; i++)
    {
        Insertar(mymonti, perro1);
    }

    printf("Top: %.2f\n\n",GetTop(miHeap));

    while(!isEmpty(miHeap))
    {
        printf("%.2f\n", Poll(miHeap));
    }


    return 0;
}

Cola* InicializarCola()
{
    Cola *nuevacola = (Cola*)malloc(sizeof(Cola));
    nuevacola->tamano= tam;
    nuevacola->primerInd = 0;
    nuevacola->ultimoInd = -1;
    nuevacola->elemento = (float*)calloc(tam,sizeof(float));
    nuevacola->cantidad = 0;

    return nuevacola;
}
void encolarperro(Cola *cola,float elemento)
{
    VerificarEspacio(cola);

    cola->ultimoIndice++;

    if(cola->ultimoIndice > cola->tamano)
        cola->ultimoIndice = 0;

    //cola->elementos+cola->ultimoIndice = (float*)malloc(sizeof(float));
    *(cola->elementos+cola->ultimoIndice) = elemento;
    cola->ultimoIndice++;
    cola->cantidad++;
}

void VerificarEspacio(Cola *cola)
{
    int i;
    if(TamanoCola(cola) < cola->tamano)
        return;

    float *nuevoEspacio = (float*)malloc(cola->tamano * 2);

    i = cola->primerIndice;
    while(i != cola->primerIndice)
    {
        *(nuevoEspacio++) = *(cola->elementos + i++);

        if(i == cola->tamano)
            i = 0;

    }

    float desencolarperro(Cola *cola)
    {
        if(isEmpty(cola))
            return 0;

        float respuesta = *(cola->elementos + cola->primerIndice);

        cola->primerIndice++;
        if(cola->primerIndice >= cola->tamano)
            cola->primerIndice = 0;

        cola->cantidad--;

        return respuesta;
    }

    void encolargato(Cola *cola,float elemento)
    {

    }

    float desencolargato(Cola *cola)

    short isEmpty(Cola *cola)
    {
        return cola->cantidad == 0;
    }

    float getFront(Cola *cola)
    {
        if(isEmpty(cola))
            return 0;

        return *(cola->elementos + cola->primerIndice);
    }


















///El monticulo
    Heap* Inicializar(short esMin)
    {
        const int altura = 10;
        Heap* nuevoHeap = (Heap*)malloc(sizeof(Heap));
        nuevoHeap->altura = altura;
        nuevoHeap->tamano = pow(2, altura) - 1;
        nuevoHeap->esMin = esMin;
        nuevoHeap->posicionActual = 0;
        nuevoHeap->elementos = (float*)calloc(nuevoHeap->tamano, sizeof(float));
        return nuevoHeap;
    }

    void VerificarEspacio(Heap* heap)
    {
        if(heap->posicionActual < heap -> tamano)
            return;

        heap->altura++;
        heap->tamano = pow(2, heap->altura);
        heap->elementos = (float*)realloc(heap->elementos, heap->tamano*(sizeof(float)));
    }

    void Insertar(Heap* heap, float elemento)
    {
        VerificarEspacio(heap);

        *(heap->elementos + heap->posicionActual++) = elemento;
        HeapifyUp(heap, heap->posicionActual - 1);
    }

    int IndicePadre(int indice)
    {
        int result = (indice-1)/2;
        return result < 0 ? 0: result;
    }

    int IndiceHijoIzquierdo(Heap* heap, int indice)
    {
        int result = (indice*2+1);
        return result < heap->posicionActual ? result : -1;
    }

    int IndiceHijoDerecho(Heap* heap, int indice)
    {
        int result = (indice*2+2);
        return result < heap->posicionActual ? result : -1;
    }

    void Swap(float* desde, float* hasta)
    {
        float burbuja = *desde;
        *desde = *hasta;
        *hasta = burbuja;
    }

    void HeapifyUp(Heap* heap, int indice)
    {
        if(indice == 0)
            return;
        int indicePadre = IndicePadre(indice);
        if(heap->esMin && *(heap->elementos + indicePadre) < *(heap->elementos+indice))
            return;
        if(!heap->esMin && *(heap->elementos + indicePadre) > *(heap->elementos+indice))
            return;

        Swap(heap->elementos + indicePadre, heap->elementos + indice);

        HeapifyUp(heap, indicePadre);
    }

    void HeapifyDown(Heap* heap,int indice)
    {
        int indiceMenor = IndiceHijoIzquierdo(heap, indice);
        int indiceDerecho = IndiceHijoDerecho(heap, indice);

        if(indiceMenor < 0)
            return;

        if(indiceDerecho >= 0 && *(heap->elementos+indiceMenor) > *(heap->elementos+indiceDerecho))
            indiceMenor = indiceDerecho;

        ///El padre te devuelve el indice del padre del elemento en que estas
        if(!(heap->esMin) && *(heap->elementos+indice) < *(heap->elementos+indiceMenor))
            return;

        Swap(heap->elementos+indice,heap->elementos+indiceMenor);
        HeapifyDown(heap, indiceMenor);
    }

    float GetTop(Heap* heap)
    {
        return *(heap->elementos);
    }

    float Poll(Heap* heap)
    {
        if(heap->posicionActual == 0)
        {
            return *(heap->elementos);
        }

        float raiz = GetTop(heap);

        Swap(heap->elementos, heap->elementos + --(heap->posicionActual));

        HeapifyDown(heap, 0);

        return raiz;
    }


    short isEmpty(Heap* heap)
    {
        return heap->posicionActual == 0;
    }
