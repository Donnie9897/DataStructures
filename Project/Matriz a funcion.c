#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void llenar(int filas, int columnas, int matr[filas][columnas]);
void mostrar(int filas, int columnas,int matr[filas][columnas]);
void transponer(int filas, int columnas, int matr[filas][columnas]);

int main()
{

   int FIL = 3, COL = 3;
   int matriz[FIL][COL];
   int i,j;

    llenar(FIL,COL,matriz);
    mostrar(FIL,COL,matriz);
    printf("\n");
    transponer(FIL,COL,matriz);

    return 0;
}

void llenar(int filas, int columnas, int matr[filas][columnas])
{
    int i, j;

    for(i=0;i<filas;i++)
    {
        for(j=0;j<columnas;j++)
        {
            printf("Digite el valor de %d, %d: \n",i,j);
            scanf("%d",&matr[i][j]);
        }
        ///scanf("%d",(matriz+j+(i*columnas)));
    }
}

void mostrar(int filas, int columnas,int matr[filas][columnas])
{

    int i, j;

    for(i=0;i<filas;i++)
    {
       for(j=0;j<columnas;j++)
       {
           printf("%d ",matr[i][j]);
       }

       printf("\n");
    }

}

void transponer(int filas, int columnas, int matr[filas][columnas])
{
    int i,j;


    for(i=0;i<filas;i++)
    {
        for(j=0;j<columnas;j++)
            printf("%d ",matr[j][i]);

        printf("\n");
    }
}
