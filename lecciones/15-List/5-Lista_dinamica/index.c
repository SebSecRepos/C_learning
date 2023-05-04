#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct nodo{
    char nombre[10];
    struct nodo *pSIG;
    int id;
};

void show(struct nodo *pINI);
void linkFinal(struct nodo *pINI, struct nodo *toLink);
void add(struct nodo **pINI);

int main(){

    struct nodo * pINI=0;

    add(&pINI);
    add(&pINI);
    add(&pINI);
    add(&pINI);
    add(&pINI);
    show(pINI);
    return 0;
}

void show(struct nodo *pINI){

    while (pINI != 0)
    {
        printf("\nEl nombre es: %s\n",(*pINI).nombre);
        printf("El id es:%d\n",(*pINI).id);

        pINI=(*pINI).pSIG;
    }
}
//  nodo    ---> estructura = 0
// pINI     ---> Puntero a direccion de memoria nodo
// ppINI    ---> Puntero a direccion de memoria de pINI

//(*ppINI)      --->contenido de ppINI = pINI
//(*(*ppINI))   ---> contenido del contenido de ppINI = nodo


void add(struct nodo **ppINI){

    struct nodo * paux=(*ppINI);

    if ((*ppINI) == 0)
    {
        (*ppINI)=(struct nodo *) malloc( sizeof(struct nodo) );

        (*(*ppINI)).id=1;
        printf("\nIngrese el nombre: \n");
        scanf("%s", (*(*ppINI)).nombre);
        (*(*ppINI)).pSIG=0;

    }else{
        
        while ((*paux).pSIG != 0)
        {
            paux=(*paux).pSIG;
        }
        
        (*paux).pSIG=(struct nodo *) malloc( sizeof(struct nodo) ); //El siguiente de paux ya no será 0, será un nuevo nodo vacío
        
        (*paux).pSIG->id=(*paux).id+1;  //Le agregamos un id al nodo vacio
        
        paux=(*paux).pSIG;              //transformamos paux en el nuevo nodo
        
        printf("\nIngrese el nombre: \n");
        scanf("%s", (*paux).nombre);
        
        (*paux).pSIG=0;
    }
    

}