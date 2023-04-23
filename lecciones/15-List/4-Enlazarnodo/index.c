
#include <stdio.h>
#include <string.h>

struct objeto{
    int id;
    char name[10];
    int edad;
    struct objeto * pSIG;
};


void enlazarNodoAlfinal(struct objeto *inicial, struct objeto *ultimo);
void mostrarNodo(struct objeto *pAux);

int main(int argc, char * argv[])
{
    struct objeto * pINI=0;
    struct objeto * pAUX=0;

    struct objeto n1;
    struct objeto n2;
    struct objeto n3;
    struct objeto n4;

    n1.id=1;
    n1.edad=20;
    strcpy(n1.name, "juan");
    
    n2.id=2;
    n2.edad=30;
    strcpy(n2.name, "josé");

    n3.id=3;
    n3.edad=15;
    strcpy(n3.name, "shrek");

    n4.id=4;
    n4.edad=50;
    strcpy(n4.name, "victor");

    n1.pSIG=0;
    n2.pSIG=0;
    n3.pSIG=0;
    n4.pSIG=0;

    pINI=&n1;

    enlazarNodoAlfinal(pINI,&n2);  
    enlazarNodoAlfinal(pINI,&n3);  
    enlazarNodoAlfinal(pINI,&n4);  

    mostrarNodo(pINI);

    pAUX=&n2;
    
    (*pAUX).pSIG=&n4;

    printf("\n Desenganchando nodo \n");

    mostrarNodo(pINI);
}

void enlazarNodoAlfinal(struct objeto *inicial, struct objeto *nEnlazar)
{

    struct objeto * ultimo=inicial;

    while ( (*ultimo).pSIG != 0 )
    {
        ultimo=(*ultimo).pSIG;
    }

    (*nEnlazar).pSIG=0;
    (*ultimo).pSIG=nEnlazar;   //----> ultimo se convierte en anteúltimo

}

void mostrarNodo(struct objeto *pAux)
{
    printf("======= Nodos ==========\n\n");

    while (pAux != 0)
    {
        printf("------------------------\n");
        printf("\nId %d\n", (pAux)->id);
        printf("Nombre %s\n", (pAux)->name);
        printf("Edad %d\n", (pAux)->edad);
        printf("------------------------");

        pAux=(*pAux).pSIG;
    }
    
}
