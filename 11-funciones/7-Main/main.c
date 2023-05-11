#include<stdio.h>
#include<string.h>

                //array de punteros de arrays tipo char
int main(int argc, char *argv[])
{
   int i=1;
   for( i=1; i<argc; i++ )
   {
    char initChar=argv[i][0]; 
    char * initCharMemory=&(argv[i][0]);


    char * currentMemory=initCharMemory;
    char detect_finish='o';
    char lastChar;
    printf( "\n argv[%d] \n \t Palabra: ", i );

    printf("\"");               //Mostramos con un loop la palabra y detectamos el último caracter
        while( detect_finish != '\0' )
        {
            printf("%c", *currentMemory );
            currentMemory++;
            detect_finish=*currentMemory;

            if( detect_finish != '\0' ){
                lastChar=detect_finish;
            }
        }
    printf("\"");

    printf( "\n\n \t Desde ---> \"%c\" : %p (Referencia del puntero) \n \t ", initChar, initCharMemory  );
    printf("\n \t Hasta ---> \"%c\" : %p \n \n", lastChar, currentMemory );

   }

    return 0;
}