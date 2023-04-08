#include<stdio.h>
#include<string.h>

//Archivos Texto: Es información volcada de la ram al disco rígido en formato ascii con elementos de 8 bits
// Por tanto podemos ver los elementos de 8bits con un editor de texto.  

//Archivos Binarios: Es información que también se vuelca de la ram al disco rígido, pero en el mismo formato en el
//que se encuentra estando en la memoria (No es humanamente legible) se necesita un editor hexadecimal.

int main()
{
    FILE *aFile;

    aFile = fopen("mitexto.txt", "w");

    char texto[]="Contenido del texto\n";

//1° param Cadena, 2° param tamaño cada/elemento de cadena, 3°param largo cadena, 4°param el puntero
    if ( aFile != 0 ){
        
        fwrite(texto, sizeof(char), strlen(texto), aFile); 
    }
    else
    {
        printf("Problemas al abrir el archivo\n");
    }

    fclose(aFile);

    return 0;
}