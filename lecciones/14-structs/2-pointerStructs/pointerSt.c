#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct estru
{
    char c1;
    char c2;
    int num;
};


int main() 
{
    struct estru e1;
    struct estru * pEstru=NULL; 
    pEstru=&e1;

    printf("La sumatoria de los campos es %ld\n", (sizeof(char)+sizeof(char)+sizeof(int)));
    printf("El tamaño de la estructura es %ld\n", sizeof(*pEstru));

    pEstru->c1='A';
    pEstru->c2='B';
    pEstru->num=5;

    //Posibles sintaxis para acceder a los campo de un puntero a estructura:
    /*
        punter->campo        (Sintaxis arrow)
        (*puntero).campo     (SIntaxis clásica)
    */

    printf("C1: %c\nC2: %c\nnum: %d ", pEstru->c1, pEstru->c2, pEstru->num);

    return (0);
}