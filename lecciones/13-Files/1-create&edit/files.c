#include<stdio.h>
#include<string.h>

//Crear archivo de texto, generar la cadena de caracteres y grabarla en el archivo

int main()
{
    FILE *aFIle; //Este fichero en memoria es llenado con...

    aFIle=fopen("mitexto.txt", "a");  //El contenido del archivo abierto o el contenido que vamos a ingresar
    /*Modes:
    "a": Append, concatena contenido con un espacio,
    "w": Sobreescribe contendo 
    "r": Lectur
*/

    char texto[]="Segunda cadena";

    if(aFIle != 0){
        fwrite(texto, sizeof(char), strlen(texto), aFIle);
        fclose(aFIle);
    }

    return 0;
}