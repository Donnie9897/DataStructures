#include <stdlib.h>
#ifndef _Lista
#define _Lista




typedef struct Nodo
{
    float data;
    struct Nodo *siguiente;
}Nodo;

typedef struct
{
    Nodo *tope;
    int cantidad;

}Pila;

Pila* IniciarPila();

float Pop(Pila*);

void Push(Pila*,float);

short isEmpty(Pila*);

float Peek(Pila*);


#endif // _Lista
