#include<stdio.h>


int main()
{
    int numero=10;
    int *Pnumero=&numero;
    
    printf("\nEL contenido de número antes de cambiar = %d\n",numero);

    (*Pnumero)++;   //ahí número es 11, utilizamos paréntesis para hacer abreviaturas
    *Pnumero=54;    //ahí número es 54

    printf("\nEL contenido de número después de cambiar = %d\n",numero);

    //Nunca tocamos la variable número solo el puntero
    printf("\nNunca tocamos la variable número solo el puntero, ahora vemos el valor desde el puntero\n");

    printf("\nEl número mostrado desde el puntero es: %d", *Pnumero);


    return(0);
}