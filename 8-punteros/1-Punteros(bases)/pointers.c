#include <stdlib.h>
#include <stdio.h>

//Inicializar los punteros en 0
//Las direcciones de memoria se muestran como %p

//==== Muestra de datos En el string=====
/*
    %tipo (d, l, lu, p etc) ----> Ej  printf("El valor es %d")  
*/

//==== Muestra de datos En valor del printf() (Segundos parámetros)=====
/*
     variable, &obj, *puntero ----> Ej  printf("El valor es %d", valor)  

    Los más específicos son:
     - &obj -----> Apunta al bloque inicial del espacio en memoria
     - *nombrepuntero -----> Apunta al valor de lo que el puntero apunta

     - Luego también se pueden usar variables, resultados de funciones etc 

*/



int main()
{

    int * intPoint=0;         
    int nota=10;

    system("clear");

    printf("EL valor de nota es %d\n", nota);
    printf("Nota se ubica en %p\n", &nota);
    printf("Nota ocupa %lu bytes\n", sizeof(nota));

    printf("\n\nEL valor del puntero es %p\n", intPoint);
    printf("EL puntero se ubica en %p\n", &intPoint);
    printf("EL puntero ocupa %lu bytes\n", sizeof(intPoint));

            //Ejemplo de error, descomentar para verlo, (Se interrumpe el programa)
    //printf("EL valor de lo apuntado es %d bytes\n", *intPoint); //ERROR VIOLACIÓN DE SEGMENTO

    /*  A la dirección del puntero le asignamos 0 como valor, pero 0 es una dirección de memoria que no pertenece
        a una dirección de memoria asignada a nuestro programa, nosotros forzadamente le asignamos esa dirección
        de apuntado, por lo que nuestro programa trata de mostrar el contenido de esa dirección

        (-Recordar 
            - &valor, muestra la dirección
            - *puntero, muestra el valor de esa dirección
        )
    Nuestro programa no tiene permiso para acceder a esa dirección de memoria
    */

    //Ahora asignameros a intPoint, una dirección de memoria que si pertenece a nuestro programa
    //será la dirección de memoria de la variable nota.

    intPoint=&nota;  //---> Para asignar el apuntado no ponemos * ya que en ese caso estariamos modificando el valor, no el apuntado

    printf("\n\nEL valor del puntero es ahora %p\n", intPoint);
    printf("El cotenido de el puntero es %d", *intPoint);
    printf("La dirección de memoria del puntero es %p", &intPoint);

    return(0);
}