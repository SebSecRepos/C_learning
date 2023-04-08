#include<stdio.h>
#include <stdlib.h>

int main ()
{
    int a=99;

    while(a!=0)
    {
    system("clear");
    printf("\nEL valor de a es: %i \n", a);
    printf("\nIngrese un valor\n");
    scanf("%d",&a);
    }
    printf("Saliste..");

    return(0);
}