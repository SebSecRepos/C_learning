#include<stdio.h>

int main()
{
                //punteros
    int * pInt = 0;
    char * pChar = 0;
   float * pFloat = 0;   //Mostrará nil ya que la dirección es 0, pero no será un error de tipo
                        //Violación de segmente, debido a que mostramos la dirección apuntada                        
                        //Pero no el contenido de la dirección apuntada ej: *pInt === contenido

    printf("La dirección a la que apunta pInt = %p \n", pInt);
    printf("La dirección a la que apunta pChar = %p \n", pChar);
    printf("La dirección a la que apunta pFloat = %p \n", pFloat);

    /* Al incrementarse la dirección apuntada, la dirección se incrementará en la cantidad de bytes que
       Ocupa cada tipo de dato en memoria, ejemplo...
    */

    pInt++;     //Al ser INT (4 bytes) El resultado del incremento será 0x4 Como dirección de memoria
    pChar++;    //Al ser CHAR (1 byte) El resultado del incremento será 0x1 Como dirección de memoria
    pFloat++;   //Al ser FLOAT (4 bytes) El resultado del incremento será 0x4 Como dirección de memoria

    printf("\n");
   
    printf("La dirección a la que apunta pInt = %p \n", pInt);
    printf("La dirección a la que apunta pChar = %p \n", pChar);
    printf("La dirección a la que apunta pFloat = %p \n", pFloat);


    return(0);
}