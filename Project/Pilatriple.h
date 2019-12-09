#include <stdlib.h>
#ifndef _Pilatriple
#define _Pilatriple


typedef struct
{
    int tamanopila;
    float *Pilatriple;
    int posiciones[6];


}pilatriple;

pilatriple* IniciarPila();
void Push(pilatriple *,int, int);
void Verificarespacio(pilatriple *,int);
float Pop(pilatriple *,int);
int Size (pilatriple *,int);
short isEmpty(pilatriple *, int);
float Peek(pilatriple *,int);




#endif // _Pilatriple
