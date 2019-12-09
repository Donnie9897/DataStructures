#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define ENTER 13

#define HL              196   /// ─
#define VL              179   /// │
#define IQS             218   /// ┌
#define DQS             191   /// ┐
#define IQI             192   /// └
#define DQI             217   /// ┘
#define CUAD            219   /// █
#define SCUAD           254   /// ■
#define ESPC            32    /// ' '





void limpiar(void);
void dados(int dado);

int main()
{


    char tecla,resp = 's';
    int dado1, dado2, suma, suma2;
    int jugadas = 0,victorias = 0, derrotas = 0;;

    srand(time(NULL));

    printf("********************************************\n");
    printf("\tBienvenido al juego de Craps\n");
    printf("\n\n");

    do
    {

        printf("Presione ENTER para lanzar los dados.\n");
        tecla = getch();

    }
    while(tecla != ENTER);

    if(tecla == ENTER)
    {

        dado1 = aleatorio(1,6);
        dado2 = aleatorio(1,6);
        suma = dado1 + dado2;
        dados(dado1);
        dados(dado2);
        printf("Resultado = %d",suma);
        jugadas++;
        printf("\njugadas = %d ",jugadas);
        printf("\n\n");

        if(suma == 7 || suma == 11)
            printf("FELICIDADES, ganaste a la primera al sacar %d ",suma);


        if(suma == 2 || suma == 3 || suma == 12)
            printf("Lo siento, has perdido en tu primera jugada. ");

        do
        {
            do
            {
                printf("Desea seguir jugando?  (S)i o (N)o");
                resp = getch();
                printf("\n\n");

            }
            while(resp != 's' && resp != 'n');


            if(resp == 's')
            {
                limpiar();
                printf("********************************************\n");

                do
                {

                    printf("\nPresione ENTER para lanzar los dados.\n");
                    tecla = getch();

                }
                while(tecla != ENTER);

                if(tecla == ENTER)
                {
                    dado1 = aleatorio(1,6);
                    dado2 = aleatorio(1,6);
                    suma2 = dado1 + dado2;
                    printf("Dado 1 = %d \n",dado1);
                    printf("Dado 2 = %d \n",dado2);
                    printf("Resultado = %d",suma2);
                    jugadas++;
                    printf("\njugadas = %d ",jugadas);
                    printf("\n\n");
                }

                if(suma2 == suma)
                {
                    printf("\nFelicidades, has ganado al igualar tu primera jugada.");
                    victorias++;
                }
                else if(suma2 == 7)
                {
                    printf("\nLo siento, has perdido por no igualar tu primera jugada.");
                    derrotas++;
                }
            }
            else
                limpiar();

        }
        while(tolower(resp) == 's');

    }



    printf("********************************************\n");
    printf("Partidas jugadas = %d ",jugadas);
    printf("\nVictorias = %d ",victorias);
    printf("\nDerrotas = %d ",derrotas);



    return 0;
}

int aleatorio(int a, int b)
{
    return rand() % (b-a+1) + a;
}

void limpiar(void)
{
    system("cls");
    Sleep(500);
}
void dados(int dado)
{
    int x = 2, y = 5;

    switch(dado)
    {
    case 1:
        gotoxy(x,y++);printf("%c%c%c%c%c",IQS,HL,HL,HL,DQS);
        gotoxy(x,y++);printf("%c%c%c%c%c",VL,ESPC,ESPC,ESPC,VL);
        gotoxy(x,y++);printf("%c%c*%c%c",VL,ESPC,ESPC,ESPC,VL);
        gotoxy(x,y++);printf("%c%c%c%c%c",VL),ESPC,ESPC,ESPC,VL;
        gotoxy(x,y++);printf("%c%c%c%c%c",IQI,HL,HL,HL,DQI);
        break;

    case 2:
        gotoxy(x,y++); printf("%c%c%c%c%c",IQS,HL,HL,HL,DQS);
        gotoxy(x,y++); printf("%c%c%c%c%c",VL,ESPC,ESPC,ESPC,VL);
        gotoxy(x,y++); printf("%c%c*%c%c",VL,ESPC,ESPC,ESPC,VL);
        gotoxy(x,y++); printf("%c%c%c%c%c",VL),ESPC,ESPC,ESPC,VL;
        gotoxy(x,y++); printf("%c%c%c%c%c",IQI,HL,HL,HL,DQI);
        break;

    case 3:
        gotoxy(x,y++); printf("%c%c%c%c%c",IQS,HL,HL,HL,DQS);
        gotoxy(x,y++); printf("%c%c%c%c%c",VL,ESPC,ESPC,ESPC,VL);
        gotoxy(x,y++); printf("%c%c*%c%c",VL,ESPC,ESPC,ESPC,VL);
        gotoxy(x,y++); printf("%c%c%c%c%c",VL),ESPC,ESPC,ESPC,VL;
        gotoxy(x,y++); printf("%c%c%c%c%c",IQI,HL,HL,HL,DQI);
        break;

    case 4:
        gotoxy(x,y++);printf("%c%c%c%c%c",IQS,HL,HL,HL,DQS);
        gotoxy(x,y++);printf("%c%c%c%c%c",VL,ESPC,ESPC,ESPC,VL);
        gotoxy(x,y++);printf("%c%c*%c%c",VL,ESPC,ESPC,ESPC,VL);
        gotoxy(x,y++);printf("%c%c%c%c%c",VL),ESPC,ESPC,ESPC,VL;
        gotoxy(x,y++);printf("%c%c%c%c%c",IQI,HL,HL,HL,DQI);
        break;

    case 5:
        gotoxy(x,y++);printf("%c%c%c%c%c",IQS,HL,HL,HL,DQS);
        gotoxy(x,y++);printf("%c%c%c%c%c",VL,ESPC,ESPC,ESPC,VL);
        gotoxy(x,y++);printf("%c%c*%c%c",VL,ESPC,ESPC,ESPC,VL);
        gotoxy(x,y++);printf("%c%c%c%c%c",VL),ESPC,ESPC,ESPC,VL;
        gotoxy(x,y++);printf("%c%c%c%c%c",IQI,HL,HL,HL,DQI);
        break;

    case 6:
        gotoxy(x,y++);printf("%c%c%c%c%c",IQS,HL,HL,HL,DQS);
        gotoxy(x,y++);printf("%c%c%c%c%c",VL,ESPC,ESPC,ESPC,VL);
        gotoxy(x,y++);printf("%c%c*%c%c",VL,ESPC,ESPC,ESPC,VL);
        gotoxy(x,y++);printf("%c%c%c%c%c",VL),ESPC,ESPC,ESPC,VL;
        gotoxy(x,y++);printf("%c%c%c%c%c",IQI,HL,HL,HL,DQI);
        break;



    }





}
