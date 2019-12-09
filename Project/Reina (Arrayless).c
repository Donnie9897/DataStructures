#include <stdio.h>
#include <stdlib.h>

int main()
{

    const int FIL = 8, COL = 8;
    int i, j;
    int pfil,pcol;

    printf("Escriba la posicion en que quiere a la reina \n");
    scanf("%d %d", &pfil,&pcol);

    printf("\n");

    for(i=0; i<FIL; i++)
    {
        for(j=0; j<COL; j++)
        {

            if(i == pfil && j == pcol)
                printf("R ");

            else if(i == pfil || j == pcol)
                printf("* ");


            else if(i-j == pfil-pcol)
                printf("* ");

            else if(i+j == pfil+pcol)
                printf("* ");

            else
                printf("0 ");

        }

        printf("\n");
    }


    return 0;
}

