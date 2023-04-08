#include<stdio.h>

void presentacion();
float promedio(int, int, int);

int main()
{
    float media=0;
    media=promedio(7,6,8);
    presentacion();

    printf("El promedio es: %.2f \n", media);
    return 0;
}

void presentacion()
{
    printf("\n==== Menu de funcines ====\n\n");
}


float promedio(int a, int b, int c)
{
    float result=0;
    result=a+b+c;
    result=result/3;
    return result;
}

