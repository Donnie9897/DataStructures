#include <stdio.h>
#include <stdlib.h>
#define COL 8
#define FIL 8

int main()
{
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

            else if(i == pfil - 1 && j == pcol - 1)
                printf("* ");
            else if( i == pfil - 2 && j == pcol - 2)
                printf("* ");
            else if( i == pfil - 3 && j == pcol - 3)
                printf("* ");
            else if(i == pfil - 4 && j == pcol - 4)
                printf("* ");
            else if(i == pfil - 5 && j == pcol - 5)
                printf("* ");
            else if( i == pfil - 6 && j == pcol - 6)
                printf("* ");
            else if( i == pfil - 7 && j == pcol - 7)
                printf("* ");
            else if(i == pfil - 8 && j == pcol - 8)
                printf("* ");


            else if(i == pfil + 1 && j == pcol + 1)
                printf("* ");
            else if(i == pfil + 2 && j == pcol + 2)
                printf("* ");
            else if( i == pfil + 3 && j == pcol + 3)
                printf("* ");
            else if(i == pfil + 4 && j == pcol + 4)
                printf("* ");
            else if(i == pfil + 5 && j == pcol + 5)
                printf("* ");
            else if( i == pfil + 6 && j == pcol + 6)
                printf("* ");
            else if( i == pfil + 7 && j == pcol + 7)
                printf("* ");
            else if(i == pfil + 8 && j == pcol + 8)
                printf("* ");



            else if( i == pfil - 1 && j == pcol + 1)
                printf("* ");
            else if(i == pfil - 2  && j == pcol + 2)
                printf("* ");
            else if( i == pfil - 3 && j == pcol + 3)
                printf("* ");
            else if(i == pfil -4  && j == pcol + 4)
                printf("* ");
            else if( i == pfil - 5 && j == pcol + 5)
                printf("* ");
            else if(i == pfil - 6  && j == pcol + 6)
                printf("* ");
            else if( i == pfil - 7 && j == pcol + 7)
                printf("* ");
            else if(i == pfil - 8  && j == pcol + 8)
                printf("* ");




            else if( i == pfil + 1 && j == pcol - 1)
                printf("* ");
            else if( i == pfil + 1 && j == pcol - 1)
                printf("* ");
            else if( i == pfil + 2 && j == pcol - 2)
                printf("* ");
            else if( i == pfil + 3 && j == pcol - 3)
                printf("* ");
            else if( i == pfil + 4 && j == pcol - 4)
                printf("* ");
            else if( i == pfil + 5 && j == pcol - 5)
                printf("* ");
            else if( i == pfil + 6 && j == pcol - 6)
                printf("* ");
            else if( i == pfil + 7 && j == pcol - 7)
                printf("* ");
            else if( i == pfil + 8 && j == pcol - 8)
                printf("* ");

            else
                printf("0 ");
        }

        printf("\n");
    }

    return 0;
}
