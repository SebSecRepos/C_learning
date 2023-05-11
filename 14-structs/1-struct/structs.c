#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct stru
{
    char c1;
    char c2;
    int num;
};

int main()
{

    struct stru e1;

    printf("La sumatoria de los campos vale %ld \n",(sizeof(char)+sizeof(char)+sizeof(int)));
    printf("El tamaño de la estrucutra es %ld \n\n",sizeof(struct stru));

    e1.c1='A';
    e1.c2='B';
    e1.num=5;

    printf("c1: %c \nc2: %c \nnum: %d", e1.c1, e1.c2, e1.num);

    return (0);
}