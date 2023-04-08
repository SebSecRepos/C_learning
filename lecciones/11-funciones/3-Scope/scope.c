#include<stdio.h>

void incrementDecrement(int);

int main()
{
    int v=15;
    printf("\nEl valor de la variable V antes de incrementarse: %d\n", v);
    incrementDecrement( v );
    printf("\nEl valor de la variable V después de incrementarse: %d\n", v); //err seguirá igual!
    return 0;
}

void incrementDecrement(int v)
{
    printf("\nEl valor de la variable V antes de incrementarse dentro de la función: %d\n", v); //err seguirá igual!
    v++;
    printf("\nEl valor de la variable V después de incrementarse dentro de la función: %d\n", v); //err seguirá igual!
}