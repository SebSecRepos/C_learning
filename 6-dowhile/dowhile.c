#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=10;

    do {
        system("clear");
        printf("\nEL valor de a es: %i \n", a);
        printf("\nIngrese un valor\n");
        scanf("%d",&a);

    }while (a!=0);

    printf("\nSaliste \n");
    return(0);
}