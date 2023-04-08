#include<stdio.h>



int main()
{

    int numeros[20];
    int *ptr = numeros;

    printf("===== Tipos de datos 32 bits =====\n");
    printf("\n Un char ocupa %ld bytes en memoria \n"
            "\n Un short ocupa %ld bytes en memoria \n"
            "\n Un int ocupa %ld bytes en memoria \n"
            "\n Un unsigned int ocupa %ld bytes en memoria \n"
            "\n Un long ocupa %ld bytes en memoria \n"
            "\n Un float ocupa %ld bytes en memoria \n"
            "\n Un double ocupa %ld bytes en memoria \n"
            "\n Un long double ocupa %ld bytes en memoria \n"
            "\n Un int array ocupa %ld bytes en memoria \n"
            "\n Un puntero ocupa %ld bytes en memoria \n",
            sizeof(char),
            sizeof(short),
            sizeof(int),
            sizeof(unsigned int),
            sizeof(long),
            sizeof(float),
            sizeof(double),
            sizeof(long double),
            sizeof(numeros),
            sizeof(ptr)
    
    );


    return(0);
}