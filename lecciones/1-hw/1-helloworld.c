#include <stdio.h>


int main(void)
{
    printf("\n holamundo \n");
    return(0);    
}

//paso0: Creamos código fuente .c
//paso1: gcc -c creamos el objeto .o
//paso2: gcc -o  nombre  ./fichero.o   Creamos el ejecutable con un nombre

//hacerlo tdo junto: gcc -c programa.c -o programa

//Definir arquitectura (usamos -m64 o -m32 )

// gcc -c -m64 programa.c -o programa64
// gcc -c -m32 programa.c -o programa32   -requiere sudo apt-get install libc6-dev-i386

