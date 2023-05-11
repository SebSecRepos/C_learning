#include<stdio.h>
#include<stdlib.h>


int main()
{

    int vector[5];
    int i=0;
    
    int * pInt=0;

    pInt=vector;      //Al apuntar al nombre del array sucede lo siguiente..

                     /*El puntero queda apuntando a la dirección de memoria del primer
                       elemento del array, por lo que al incrementar el punter ( pInt++ )
                       la dirección de memoria a la que apunta sera el elemento de la siguiente posición
                       del array  
    Sería lo mismo que hacer esto
    pInt=&(vector[0]);

                     */


    *pInt=33;   //Le damos valor a la primera posición
    pInt++;    //Incrementamos la dirección de memoria a la que apunta quedando en la 2da posición del array
    *pInt=-22; //Al valor de la segunda posición le asignamos -22
               // EL mismo proceso con las siguientes posiciones....
    pInt++;
    *pInt=6;
    pInt++;
    *pInt=-45;
    pInt++;
    *pInt=99;

    //reinicializamos pInt al inicio
    pInt=vector;

    for(i=0; i<5; i++)
    {
        //reccorriendo con vector[] 
        //printf("Vector[%d] = %d \n",i,vector[i]);
        
        //recorriendo con puntero
        printf("Vector[%d] = %d \n",i,*(pInt++));
    }


    return 0;
}