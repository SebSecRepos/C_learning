#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct nodo{
    char nombre[10];
    int edad;
    struct nodo *pSIG;
};

void addNode(struct nodo**ppINI);
void freeList(struct nodo**ppINI);
void showLista(struct nodo*pINI);
void showListAge(struct nodo*pINI, int minimunAge);


int main(){
    struct nodo *pINI=0;

    addNode(&pINI);
    addNode(&pINI);
    showLista(pINI);
    showListAge(pINI, 18);
    freeList(&pINI);
    showLista(pINI);

    return 0;
}
void addNode(struct nodo**ppINI){

    if( (*ppINI)==0 ){
        
        (*ppINI)=(struct nodo*) malloc( sizeof(struct nodo));
        (*(*ppINI)).pSIG=0;

        printf("\n Ingrese nombre: \n");
        scanf("%s",(*(*ppINI)).nombre);
        printf("\n Ingrese la edad de %s:\n", (*(*ppINI)).nombre);
        scanf("%d",&(*(*ppINI)).edad);

    }else{
        struct nodo *paux=0;
        paux=(*ppINI);

        while ( (*paux).pSIG != 0 )
        {
            paux=(*paux).pSIG;
        }
        (*paux).pSIG=(struct nodo*) malloc(sizeof(struct nodo));
        paux=(*paux).pSIG;

        printf("\n Ingrese nombre: \n");
        scanf("%s",(*paux).nombre);
        printf("\n Ingrese la edad de: %s\n", (*paux).nombre);
        scanf("%d",&(*paux).edad);

        (*paux).pSIG=0;
    }
}
void freeList(struct nodo**ppINI){

    if ((*ppINI) == 0)
    {
        printf("La lista ya ha sido vaciada");
    }else{

        struct nodo * pactual=0;
        struct nodo * psiguiente=0;

        pactual=(*ppINI);

        while (pactual != 0)
        {
            psiguiente=(*pactual).pSIG;
            free(pactual);
            pactual=psiguiente;
        }
        
        (*ppINI)=0;

    }
    

}
void showLista(struct nodo*pINI){

    if ( pINI==0 )
    {
        printf("\n La lista esta vacía \n");
    }else{
        while (pINI !=0)
        {
            printf("\n El nombre es: %s\n", (*pINI).nombre);
            printf(" La edad es: %d\n", (*pINI).edad);

            pINI=(*pINI).pSIG;
        }
    }
}
void showListAge(struct nodo*pINI, int minimunAge){

    if( pINI == 0 ){
        printf("\nLa lista esta vacia\n");
    }else{

        printf("\nLos elementos con edades mayores a %d son\n", minimunAge);
        
        while (pINI != 0 )
        {
            if( (*pINI).edad > minimunAge ){
                printf("\nNombre: %s\n", (*pINI).nombre);
                printf("Edad de %s: %d \n", (*pINI).nombre,(*pINI).edad);
            }

            pINI=(*pINI).pSIG;
        }
    }
}
