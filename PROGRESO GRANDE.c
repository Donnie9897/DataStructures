#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 10000


void nombrar(float arr[], int n);
float promedio(float valores[],float tar[]);
void ingrese(int val1, int val2, int val3, int val4, int n);
char letra(float promedio);


int main()
{

    float notas[MAX];
    float tareas[1000];
    char opcion[3];
    int cantidad, i, j;
    char nombre[20];
    int matricula;
    int valor1,valor2,valor3,valor4;

    printf("Digite la cantidad de evaluaciones ");
    scanf("%d",&cantidad);

    printf("Ingrese nombre del alumno: ");
    scanf("%s", nombre);

    printf("Digite la matricula de %s ", nombre);
    scanf("%d",&matricula);

    ingrese(valor1,valor2,valor3,valor4,cantidad);

    nombrar(notas,cantidad);


    printf("\n");

    printf("Nombre| ");
    printf(" Matricula|");
    printf("     P.P. | ");
    printf("     S.P. | ");
    printf("     T.P. | ");
    printf("    Tareas | ");
    printf("       Promedio| ");
    printf("        Final| ");

    printf("\n");
    printf("%1s   ",nombre);
    printf("  %2d", matricula );

    for(i=0;i<cantidad;i++)
    {

        printf(" %10.2f ", notas[i]);

    }
        printf("        %7.2f", promedio(notas,tareas));
        printf("         %7.2c", letra(promedio(notas,tareas)));

}

void nombrar(float arr[], int n)
{
    int z;

    for(z=0;z<=n;z++)
    {
        printf("  Nota 1: ");
        scanf("%f", &arr[z]);
        printf("  Nota 2: ");
        scanf("%f",&arr[z+1]);
        printf("  Nota 3 ");
        scanf("%f",&arr[z+2]);
        printf("  Tareas ");;
        scanf("%f",&arr[z+3]);
        break;
    }

}

float promedio(float valores[],float tar[])
 {
    int i;
    float suma = 0.0;

    for (i = 0; i < 4; ++i)
        suma += valores[i] + tar[i];

    return suma / 4;
 }

 char letra(float promedio)
 {
     if (promedio>=90)
        return 'A';
     else
        if(promedio>=80&&promedio<=90)
        return 'B';

 }

 void ingrese(int val1, int val2, int val3, int val4, int n)
{

    printf("\nIngrese el valor del primer parcial. ");
    scanf("%d",&val1);

    printf("\nIngrese el valor del segundo parcial. ");
    scanf("%d",&val2);

    if(n=3)
    {
    printf("\nIngrese el valor del tercer parcial. ");
    scanf("%d",&val3);
    }

    printf("\nIngrese el valor de las tareas. ");
    scanf("%d",&val4);


}
