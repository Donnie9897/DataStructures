#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAYOR 100


int buscador(int);


int main()
{

    int primos[MAYOR];
    int cantidad;
    int inicial;
    int incremento;

    printf("Digite la cantidad de primos requerida ");
    scanf("%d",&cantidad);

    do
    {
    if(cantidad<=0)
    {
        printf("\nLa cantidad debe ser mayor que 0 ");
        scanf("%d",&cantidad);
    }
    }while(cantidad<=0);

        printf("\nDigite el incremento deseado ");
        scanf("%d",&incremento);

    do
    {
    if(incremento<=0)
    {
        printf("\nEl incremento no puede ser menor que 0  ");
        scanf("%d",&incremento);
    }
    }while(incremento<=0);

        printf("\nDigite el n%cmero con el que desea iniciar ",163);
        scanf("%d",&inicial);

    do
    {
    if(inicial<=1)
    {
        printf("\nEl n%cmero inicial debe ser mayor que 1  ",163);
        scanf("%d",&inicial);
    }
    }while(inicial<=1);

    cantidad += inicial + incremento + 1;

    llamadoprim(primos,inicial,incremento,cantidad);



    return 0;
}

void llamadoprim(int arr[],int ini,int inc, int n)
{
    int cont = 2;
    int i = 0;
    int lim=ini+n*inc;

    for(cont;cont<=MAYOR;cont++)
    {
       if(buscador(cont))
       {
           arr[i] = cont;
           i++;

           if(i == n )
            break;
       }

    }
      for(ini = ini-2; ini < n; ini += inc)
          printf("\n%d ",arr[ini+1]);
}



int buscador(int cont)
{
   int numinf = (int)sqrt(cont);
   int operate = 2;

   if ( cont == 1 )
      return 0;
   for ( operate; operate <= numinf; operate++ )
      if ( cont % operate == 0 )
         return 0;

   return 1;
}
