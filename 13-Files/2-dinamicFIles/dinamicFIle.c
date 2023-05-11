#include<stdio.h>
#include <stdlib.h>
#include<string.h>

//Objetivo: Leer archivo de texto, guardarlo en la memoria dinámicamente, e imprimirlo en consola

/*  Variables: Puntero a archivo, puntero a char, long tamañoarchivo.
    1: Abrir el archivo en modo lectura

    --Comprobamos que el puntero exista---

    2- Mover el puntero a la ultima posicion de memoria del archivo (fseek)
    3- Definir la variable de tamaño con ftell(punteroarchivo)
    4- Volvemos al puntero al inicio del archivo con rewind(punteroarchivo)

    5- El puntero char asigna la memoria dinámica con malloc (multiplicamos tamaño del archivo por la minima unidad de memoria)
        De esta forma la memoria dinámica se ajusta al tamaño del archivo
    --- Comprobamos  que el puntero de memoria dinámica exista ---

    6- Realizamos la lectura del archivo con fread(1, 2, 3, 4);
    7- Mostramos el contenido de la dirección de memoria dinámica
    8- Cerramos con fclose()
    9- liberamos la memoria dinámica con free()

*/

int main(){

    FILE *aFile;
    long aSize;
    char *c;

    aFile=fopen("Mitexto.txt", "r");

    /*
        IMPORTANTE: 
            fseek(); Lo que hace es posicionar al puntero de un archivo
            en la última posición de memoria correspondiente al buffer del archivo, cuando un puntero apunta
            a cualquier elemento, siempre apunta a la primera dirección de memoria
            Al moverlo de posición podemos recorrer el contenido del fichero.

            ftell(); Lo que hace es devolver la cantidad de bytes desde primer byte hasta la posición del puntero
            de un archivo abierto, recibe como parametro el puntero
    */

    if(aFile == NULL){
        printf("EL archivo no existe");
    }else{
        fseek(aFile, 0, SEEK_END); //El puntero queda al final
        aSize=ftell(aFile);  //ftell cuenta los bytes desde la pos 0 hasta la pos del puntero
        rewind(aFile);      //Volvemos el puntero a la dirección inicial

        c= (char *) malloc(sizeof(char) * aSize); //Se multiplica char "1 byte" * eltamaño de aSize 

        if(c == NULL){
            printf("No hay mas memoria");
            return 1;
        }else{

            //Parametros fread:
            /*
            1: El espacio de memoria dinámica donde vamos a leer el archivo,
            2: EL tamaño de cada elemento del archivo en bytes
            3: El tamaño del archivo en bytes
            4: el puntero al archivo
            */
            fread(c, sizeof(char), aSize, aFile);

                printf("%s", c);
            
            fclose(aFile);

        }

        free(c);

    }

    return 0;
}


/*  Variables: Puntero a archivo, puntero a char, long tamañoarchivo.
    1: Abrir el archivo en modo lectura

    --Comprobamos que el puntero exista---

    2- Mover el puntero a la ultima posicion de memoria del archivo (fseek)
    3- Definir la variable de tamaño con ftell(punteroarchivo)
    4- Volvemos al puntero al inicio del archivo con rewind(punteroarchivo)

    5- El puntero char asigna la memoria dinámica con malloc (multiplicamos tamaño del archivo por la minima unidad de memoria)
        De esta forma la memoria dinámica se ajusta al tamaño del archivo
    --- Comprobamos  que el puntero de memoria dinámica exista ---

    6- Realizamos la lectura del archivo con fread(1, 2, 3, 4);
    7- Mostramos el contenido de la dirección de memoria dinámica
    8- Cerramos con fclose()
    9- liberamos la memoria dinámica con free()

*/

