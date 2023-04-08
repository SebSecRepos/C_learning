#include<stdio.h>
#include<stdlib.h>


int main()
{

    int *pInt=0;

    pInt=malloc(sizeof(int));       //reservamos 4bytes en memoria
    printf("Ingrese un número\n");
    scanf("%d", pInt);      //modifica el contenido de el espacio en memoria al que apunta, pero no la direccion en memoria
    printf("\nDirección en memoria  %p \n", pInt);
    printf("\nValor %d", *pInt);

    free(pInt);
    return 0;
}