#include<stdio.h>

int main()          
{

    int vector[5];  //<tipo de dato> <nombre> [<tamaño>]; ----> (El array ocupa 4x5 bytes de espacio --> 20 bytes)
                    //Cada elemento int ocupa 4 bytes y las posiciones son 5, se multiplican esos factores

    vector[0]=1;
    vector[1]=2;
    vector[2]=3;
    vector[3]=4;
    vector[4]=5;


    int i=0;
    for(i=0;i<5;i++){
        printf("vector[%d] = %d\n",i, vector[i]);
    }

    printf("\nEL tamaño del vector es: %lu bytes", sizeof(vector));


    return(0);
}