#include<stdio.h>

//EJEMPLO DE ACCESO A MEMORIA NO CONTROLADO !PELIGRO
                                
//Con el argv[posicion] puede acceder al contenido de los elementos del array
// la variable firstCharMemory  no debería, ya que su scope es de este programa
//a diferencia que el array argv que es un argumento que viene de afuera

int main( int argc, char *argv[] )  
{
    char *firstCharMemory=&(argv[0][0]); //Dirección del primer char del primer elemento del array
                                        //Si accedemos por fuera del while a su valor sera segmentation fault
    while( 1 ){
        if(*firstCharMemory == '\0'){
            printf("\n");
        }                          
                                        //Pero dentro del while podremos ver el contenido
        printf("%c", *firstCharMemory); //vemos el contenido 
        firstCharMemory++;              // Incrementamos su posicion en memoria, indiscriminadamente
    }  

/*  Una comprobación para evitar esto, seria la condicion *firstCharMemory != '\0'                         
    Dentro del while, esto provocaría que el while deje de iterar si la cadena llego a su fin
*/

    return 0;
}