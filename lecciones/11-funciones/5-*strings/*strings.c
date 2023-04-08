#include<stdio.h>

int main(){ //Programando el %s

/*¡¡¿¿¿ POR QUE AL MOSTRAR EL PUNTERO POR EJ: pChars[0] DE CADA POSICIÓN INICIAL PODEMOS VER UNA CADENA COMPLETA ???!

- Esto sucede por que al pasarle un puntero al %s (string), lo que hace es a partir de esa posición de memoria recorre 
cada posición de memoria contigua y muestra su contenido hasta que encuentra '\0' en el contenido de la última posición      
Es como si la función %s hiciera un loop por los espacios de memoria contiguos a la posición de memoria proporcionada y 
mostrase su contenido. 
El siguiente ejemplo muestra como funciona el %s respecto a punteros:
*/

    char palabra[]="buenosdias";    //Palabra

    char * p1=&(palabra[0]);   //puntero a la direccion de memoria de la primer letra

    char final='\0';

    while( *p1 != final ){        //si el contenido del puntero es diferente de '\0' (empty character)

        printf("[%c]", *p1);    //mostramos el caracter

        p1++;                   //incrementamos el puntero a una posicion de memoria contigua    

    }   //Llegará un punto el el contenido del puntero sea '\0' (final de la cadena) y se terminará el loop

    return 0;

/*
    De esta manera funciona printf("Contenido de %s", palabra)
*/
}


 