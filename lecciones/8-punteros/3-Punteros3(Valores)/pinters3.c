#include<stdio.h>

int main()
{                   //Declaración Punteros
   int * pInt = 0;
   char * pChar = 0;
   float * pFloat = 0;
                    //Declaración e inicialización variables
   int  nota = 10;
   char asistencia = 'p';
   float peso = 60.12;
                    //Apuntes
   pInt = &nota;
   pChar = &asistencia;
   pFloat = &peso;


   printf("El valor de pInt = %d \n", *pInt);
   printf("El valor de pChar = %d \n", *pChar);
   printf("El valor de pFloat = %f \n", *pFloat);

   printf("\n");

   printf("\nLa dirección a la que apunta pInt = %p", pInt);
   printf("\nLa dirección a la que apunta pChar = %p", pChar);
   printf("\nLa dirección a la que apunta pFloat = %p", pFloat);

   printf("\n \n");

   printf("EL tamaño de pInt es = %lu \n", sizeof(pInt));
   printf("EL tamaño de pChar es = %lu \n", sizeof(pChar));
   printf("EL tamaño de pFloat es = %lu \n", sizeof(pFloat));


   return (0);
}