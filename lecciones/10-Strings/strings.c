#include<stdio.h>

int main(){
    
    char nombre[7];
    char apodo[11];
    
    char apellido1[]="Belettieri"; //Al usar commillas dobles esta implícito el \0
                                   //Esto sirve para dimensionar automaticamente el tamaño del string
    char apellido2[11]={'G','o','r','o','s','t','e','g','u','i','\0'};
    //return 0;

    nombre[0]='s';
    nombre[1]='e';
    nombre[2]='b';
    nombre[3]='a';
    nombre[4]='s';
    nombre[5]='t';
    nombre[6]='i';
    nombre[7]='a';
    nombre[8]='n';
    nombre[9]='\0';
    
    strcpy(apodo, "seba");

    printf("Nombre: %s \n", nombre);
    printf("Apodo: %s \n", apodo);
    printf("Primer apellido: %s \n", apellido1);
    printf("Segundo apellid: %s \n", apellido2);

    return 0;

}

