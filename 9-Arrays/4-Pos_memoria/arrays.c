#include<stdio.h>


int main(){

    int vector[5];
    int i=0;
    int * pInt=0;

    pInt=&(vector[0]);

    printf("==== Muestra de memoria desde puntero ====\n");
    for(i=0;i < 5; i++)
    {   
        printf("Dirección vector[%d] = %p ----> + 4 bytes ---> Dec %d \n", i, pInt, pInt);
        pInt++;
    }

    printf("\n\n==== Muestra de memoria desde vector ====\n");
    for(i=0;i < 5; i++)
    {   
        printf("Dirección vector[%d] = %p ----> + 4 bytes ---> Dec %d \n", i, &(vector[i]), &(vector[i]));
        pInt++;
    }

    return 0;
}