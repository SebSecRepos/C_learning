#include <stdio.h>
#include <string.h>


struct nodo
{
    int id;
    char nombre[10];
    int edad;
    struct nodo *pSig;
};

void show(struct nodo * paux);

int main()
{
    struct nodo n1;
    struct nodo n2;
    struct nodo n3;

    struct nodo * pAUX=0;
    struct nodo * pINI=0;

    n1.id=1;
    strcpy(n1.nombre, "juan");
    n1.edad=20;
    n1.pSig=0;

    n2.id=2;
    strcpy(n2.nombre, "jose");
    n2.edad=25;
    n2.pSig=0;

    n3.id=3;
    strcpy(n3.nombre, "maría");
    n3.edad=30;
    n3.pSig=0;

    pAUX=&n1;   
    pINI=pAUX;   

    n1.pSig=&n2;
    n2.pSig=&n3;
    
    printf("\n\n Lista sin cortar \n\n");
    show( pAUX );

    printf("\n\n Lista sin nodo 2 \n\n");

    n1.pSig=&n3;
    show( pAUX );
    

    return 0;
}

void show(struct nodo * paux){
    while (paux !=0) {
        printf("ID: %d\n", (*paux).id);
        printf("Nombre: %s\n", (*paux).nombre);
        printf("Edad: %d\n\n", (*paux).edad);

        paux=(*paux).pSig;
    }
}