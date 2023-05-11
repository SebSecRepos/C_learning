#include<stdio.h>

void Incrementator(int *);

int main()
{
    int v=5;
    int * pV=&v;

    printf("\nEl valor de v pre func de Incremento %d \n", v);

    Incrementator(pV);

    printf("\nEl valor de v post func de Incremento %d \n", v);
    return 0;
}


void Incrementator(int * pV)
{
    //printf("\nEl valor de v preIncremento en la func %d \n", *pV);
    (*pV)++;
    //printf("\nEl valor de v postIncremento en la func %d \n", *pV);
}