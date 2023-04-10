// #include<stdio.h>
// #include <stdlib.h>
// #include<string.h>

// //Objetivo: Leer archivo de texto, guardarlo en la memoria dinámicamente, e imprimirlo en consola

// int main(){

//     FILE *aFile;
//     long aSize;
//     char *c;

//     aFile=fopen("Mitexto.txt", "r");

//     /*
//         IMPORTANTE: 
//             fseek(); Lo que hace es posicionar al puntero de un archivo
//             en la última posición de memoria correspondiente al buffer del archivo, cuando un puntero apunta
//             a cualquier elemento, siempre apunta a la primera dirección de memoria
//             Al moverlo de posición podemos recorrer el contenido del fichero.

//             ftell(); Lo que hace es devolver la cantidad de bytes desde primer byte hasta la posición del puntero
//             de un archivo abierto, recibe como parametro el puntero
//     */

//     if(aFile == NULL){
//         printf("EL archivo no existe");
//     }else{
//         fseek(aFile, 0, SEEK_END); //El puntero queda al final
//         aSize=ftell(aFile);  //ftell cuenta los bytes desde la pos 0 hasta la pos del puntero
//         rewind(aFile);      //Volvemos el puntero a la dirección inicial

//         c= (char *) malloc(sizeof(char) * aSize); //Se multiplica char "1 byte" * eltamaño de aSize 

//         if(c == NULL){
//             printf("No hay mas memoria");
//             return 1;
//         }else{

//             //Parametros fread:
//             /*
//             1: El espacio de memoria dinámica donde vamos a leer el archivo,
//             2: EL tamaño de cada elemento del archivo en bytes
//             3: El tamaño del archivo en bytes
//             4: el puntero al archivo
//             */
//             fread(c, sizeof(char), aSize, aFile);

//                 printf("%s", c);
            
//             fclose(aFile);

//         }

//         free(c);

//     }

//     return 0;
// }


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){

    FILE *aFile;
    long aSize;
    char * c;

    aFile=fopen("Mitexto.txt", "r");

    if(aFile == NULL){
        printf("EL archivo no existe");
    }else{
        fseek(aFile, 0, SEEK_END);
        aSize=ftell(aFile);
        rewind(aFile);
        
        c= (char *) malloc( sizeof(char) * aSize );

        if(c == NULL){
            printf("NO hay mas espacio en memoria");
            return 1;
        }else{

            fread(c, sizeof(char), aSize, aFile);
            printf("%s",c);

            fclose(aFile);
            free(c);
        }
    }

    return 0;
}