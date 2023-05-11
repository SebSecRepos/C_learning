#include <stdio.h>


int main()
{

    char c;                      // un caracter
    char nombre[] = "sebastián"; //muchos caracteres se define como un array de caracteres 
    short s;                     //
    int i;                       // entero >0, <0, 0
    unsigned int ui;             //entero >0
    long l;                      // entero de mayor tamaño
    float f;                     // decimal finito
    double d;  //
    long double ld;  //
    int array [ 20 ];  //
    int *ptr = array;  //



    //Metodos a usar, size of 'dato' y sizeof( 'typodedato' )
    //Con printf(), podemos poner texto y parametros, con % interpolamos parámetros
    //se puede epecificar como se verá el parametro por ej %ld, mostrará un entero, %s sera texto
    //Lo que será el parámetro se define por posición por ej:

    // printf( "el nombre es:%s El apellido es %s, "sebastian", "belettieri"  )
    // printf( "el tamaño de un char es de:%ld %s" , sizeof( char ), "bytes"  )

    //En el primer espacio podemos colocar el texto con interpolaciones y en el resto
    //los datos que serán interpolados en orden



    // printf(
    //     "sizeof c =  %ld sizeof(char) = %ld",
    //     sizeof c, sizeof( char )
    
    // );

    printf( "\n el nombre es:%s \n El apellido es %s \n", "sebastian", "belettieri"  );
    printf( "\n el tamaño de un char es de:%ld %s \n" , sizeof( char ), "bytes"  );
    return (0);
}