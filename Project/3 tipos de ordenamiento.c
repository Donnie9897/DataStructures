#include <stdio.h>
#include <stdlib.h>

void captam(int*);
void valores(int*, int*);
void mostrar(int*,int*);
void OrdenarInsercion(int*,int*);
void OrdenarBurbuja(int *arreglo, int *tam);
void OrdenarSeleccion(int *arreglo, int *tam);

int main()
{


    int tama;
    int *arreglo;
    captam(&tama);
    arreglo = (int*)calloc(tama,sizeof(int));
    valores(arreglo,tama);
    mostrar(arreglo,&tama);
    //OrdenarInsercion(arreglo,&tama);
    //OrdenarBurbuja(arreglo,&tama);
    OrdenarSeleccion(arreglo,&tama);
    printf("\n");
    mostrar(arreglo,&tama);



    return 0;
}


void captam(int *tama)
{
    do
    {
        printf("Ingrese el tama%co (positivo) del arreglo ",164);
        scanf("%d", tama);

    }
    while(*tama<=0);
}

void valores(int *arreglo, int *tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        printf("\nIngrese el valor %d del arreglo ",i+1);
        scanf("%d",(arreglo+i));

    }
}

void mostrar(int *arreglo,int *tam)
{
    int i;

    for(i=0; i<*tam; i++)
    {
        printf("%d \n",*(arreglo+i));

    }

}

void OrdenarInsercion(int *arreglo, int *tam)
{
    int i,j,valorActual;

    for(i = 0; i<*tam; i++)
    {
        valorActual = *(arreglo+i);
        j=i-1;
        while(j>=0 && *(arreglo+j) > valorActual)
        {
            *(arreglo+j+1) = *(arreglo + j);
            j--;

        }

        *(arreglo+j+1) = valorActual;
    }



}

void OrdenarBurbuja(int *arreglo, int *tam)
{
    int i,j;
    int *aux;

    for(i=0;i<*tam;i++)
    {
        for(j=0;j<*tam-1;j++)
        {
            if(*(arreglo+j+1) < *(arreglo+j))
            {
                aux = *(arreglo+j+1);
                *(arreglo+j+1) = *(arreglo+j);
                *(arreglo+j) = aux;
            }

        }
    }
}

void OrdenarSeleccion(int *arreglo, int *tam)
{
    int i,j,aux,min;

    for(i=0;i<*tam;i++)
    {
        min = i;
        for(j=i+1;j<*tam;j++)
        {
            if(*(arreglo+j)<*(arreglo + min))
                min = j;
        }
        aux = *(arreglo+i);
        *(arreglo+i) = *(arreglo+min);
        *(arreglo+min) = aux;
    }

}
