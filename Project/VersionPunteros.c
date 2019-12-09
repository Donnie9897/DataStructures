#include <stdlib.h>
#include <stdio.h>

#ifndef _mainVersionPunteros
#define _mainVersionPunteros
#endif // _mainVersionPunteros


void mainPunteros(int pfil, int pcol)
{

    const int FIL = 8, COL = 8;
    int **tablero;
    int i, j;


    for(i=0; i<FIL; i++)
    {
        for(j=0; j<COL; j++)
        {
            if(i == pfil && j == pcol)
                printf("* ");

            else if(i-j == pfil-pcol || i+j == pfil+pcol)

            }
    }

}
