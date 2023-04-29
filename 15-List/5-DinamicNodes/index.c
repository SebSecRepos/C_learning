#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct nodo
{
    char nombre[10];
    int edad;
    struct nodo * psig;

};

void show(struct nodo * pINI);
void linkFinal(struct nodo * pINI, struct nodo * pADD);
void add(struct nodo ** pINI);

//AL PASAR UNA DIRECCIÓN DE MEMORIA A UNA FUNCION, EL PARAMETRO EQUIVALE A UN PUNTERO
//AL PASAR UNA DIRECCIÓN DE MEMORIA DE UN PUNTERO A UNA FUNCION EL PARAMETRO EQUIVALE A UN PUNTERO A PUNTERO

int main()
{
    struct nodo * pINI=0;

    add(&pINI);
    show(pINI);

    return 0;
}

void show(struct nodo * pINI){

    while (pINI != 0)
    {
        printf("\n Nombre: %d \n", (*pINI).edad);
        printf("\n Nombre: %s \n", (*pINI).nombre);

        pINI=(*pINI).psig;
    }
};



//n1 = nodo

//pINI ---> apunta direc memoria n1
// ppINI ---> apunta direc memoria de pINI

// * == CONTENIDO 

// (*ppINI) == pINI --> apunta direc memoria n1

// (*(*ppINI)) == n1 --> NODO

void add(struct nodo ** ppINI){

    if ((*ppINI)==0)
    {
        (*ppINI)=(struct nodo *) malloc( sizeof(struct nodo) );
        (*(*ppINI)).psig=0;

        printf("\n Ingrese Nombre:\n");
        scanf("%s", (*(*ppINI)).nombre);

        printf("\n Ingrese edad:\n");
        scanf("%d", &(*(*ppINI)).edad);
    }else
    {s


    }
};
