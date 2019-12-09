#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *perros;
    int *gatos;
    int primerindp;
    int primerindg;
    int ultimoindp;
    int ultimoindg;
    int tamano;
    int cantidad;
} Refugio;

const int tama = 30;


Refugio* Inicializar();
void EncolarAnimal(Refugio *cola, int numero);
int DecolarAnimal(Refugio *cola, int numero);
void tamano(Refugio* cola);
void Verificar(Refugio *cola);
short isEmpty(Refugio *cola);

int main()
{

    Refugio *dogs;
    Refugio *cats;
    int i = 0, cantidad = 0, numero;
    char resp = 's';

    dogs = Inicializar(dogs);
    cats = Inicializar(cats);

    do
    {

        printf("Ingrese un numero par para agregar un perro y uno impar para agregar un gato ");
        scanf("%d",&numero);

        if(numero%2 == 0)
        {
            EncolarAnimal(dogs,numero);
            cantidad++;
            printf("\n");
        }

        else
        {
            EncolarAnimal(cats,numero);
            cantidad++;
            printf("\n");
        }
    }
    while(cantidad < 5);

    printf("\n\n");

    printf("Oprima G para sacar un gato y P para sacar un perro");
    resp = getch();

    printf("\n\n");

    if(resp == 'g')
    {
        numero = DecolarAnimal(cats,1);
        printf("\nGato #%d = %d", i+1,numero);

    }

    if(resp == 'p')
    {
        numero = DecolarAnimal(dogs,2);
        printf("\nPerro #%d = %d", i+1,numero);
    }



    return 0;
}

Refugio* Inicializar()
{
    Refugio *cola = (Refugio*)malloc(sizeof(Refugio));
    cola->primerindp = 0;
    cola->primerindg = 0;
    cola->ultimoindp = -1;
    cola->ultimoindg = -1;
    cola->tamano = tama;
    cola->perros = (int*)calloc(tama,sizeof(int));
    cola->gatos = (int*)calloc(tama,sizeof(int));
    cola->cantidad = 0;

    return cola;
}

void EncolarAnimal(Refugio *cola, int numero)
{
    cola->ultimoindp++;
    cola->ultimoindg++;

    if(numero%2 == 0)
    {
        *(cola->perros + cola->ultimoindp) = numero;
        cola->ultimoindp++;
        cola->cantidad++;
        return;
    }

    else
        *(cola->gatos + cola->ultimoindg) = numero;
    cola->ultimoindg++;
    cola->cantidad++;

}

int DecolarAnimal(Refugio *cola,int numero)
{
    int animal;

    if(isEmpty(cola))
        return 0;


    if(numero%2 == 0)
    {
        animal = *(cola->perros + cola->primerindp);
        cola->primerindp++;
        cola->cantidad--;
        return animal;
    }

    else
        animal = *(cola->gatos + cola->primerindg);
    cola->primerindg++;
    cola->cantidad--;
    return animal;

}

short isEmpty(Refugio *cola)
{
    return cola->cantidad == 0;
}

void tamano(Refugio *cola)
{
    return cola->cantidad;
}




