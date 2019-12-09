#include <stdio.h>
#include <stdlib.h>




#define COL 8
#define FIL 8




void main(int FIL, int COL)
{

    char matriz[COL][FIL];
    int i,j;
    int pfil,pcol;

    printf("Escriba la posicion en que quiere a la reina \n");
    scanf("%d %d", &pfil,&pcol);

    pfil -= 1;
    pcol -= 1;
    printf("\n");

    for(i=0;i<FIL;i++)
    {
        for(j=0;j<COL;j++)
        {
            if(i == pfil && j == pcol)
                printf("* ");

            else if(i-j == pfil-pcol || i+j == pfil+pcol)

        }
    }



     for(i=0; i<FIL; i++)
    {
        for(j=0; j<COL; j++)
            printf("%c ",matriz[i][j]);


        printf("\n");
    }



    return 0;
}

