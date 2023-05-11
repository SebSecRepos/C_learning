#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){

    FILE *aFile;

    int num=0x2A3F88;
    char cara='G';
    float pi=3.14;

    char n='\n';

    //fwrite() 1: dir memoria, tamaño, unidades, elemento

    aFile=fopen("informacion.dat", "wb");

    if(aFile == NULL){
        printf("No existe el archivo");
        return 1;
    }else{

        fwrite(&num, sizeof(num), 1, aFile);
        fwrite(&cara,sizeof(cara), 1, aFile);
        fwrite(&pi, sizeof(pi), 1, aFile);

        fclose(aFile);
    }


    return 0;
}