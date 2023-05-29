#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct info{
    int id;
    char nombre[10];
}; typedef struct info DATA;

struct nodo{
    struct nodo * next;
    DATA *data;
}; typedef struct nodo SLL;


void addNode( SLL **pINI, DATA *newData );
DATA * newInfo( int i );
void removeNode( SLL **pINI, int i );
void showList( SLL *pINI);
void freeList( SLL **pINI);


int main(int argc, char * argv[])
{
    int * cantidad=(int *) malloc( sizeof(int) );

    printf("\n---- Ingrese la cantidad de nodos a crear ----\n");
    scanf("%d", cantidad);


    SLL * pINI=0;
    for (int i = 0; i < *cantidad; i++)
    {
        addNode(&pINI, newInfo(i));
    }
    free(cantidad);

    system("clear");
    printf("\n------Se muestra la lista -------\n");
    showList(pINI);

    char remove;

    printf("\n¿Desea remover un nodo? <y> <n>\n");
    scanf(" %c",&remove);

    if (remove == 'y')
    {
        int * idDelete=(int *) malloc( sizeof(int) );
        printf("\nIngrese id a eliminar\n");
        scanf("%d",idDelete);
        removeNode(&pINI, *idDelete);
        printf("\n------Se remueve el %d -------\n", *idDelete);
        showList(pINI);
    }else if(remove == 'n'){
        printf("\nSaliendo..\n");
        return 0;
    }else{

        printf("\n [!]Opcion inválida..\n");
        return 1;
    }
    freeList(&pINI);
    printf("\n------Se libera la lista-------\n");
    showList(pINI);
    
    return 0;
}

DATA * newInfo( int i ){
    DATA * newData= (DATA *) malloc( sizeof(DATA) );

    newData->id=i;
    printf("\nIngrese el nombre: \n");
    scanf("%s", newData->nombre);
    return newData;
}


void addNode( SLL **pINI, DATA *newData )  //Los nuevos van al final de la lista
{
    while (*pINI != NULL)
    {
        pINI=&(*pINI)->next; //recorremos la lista con un puntero a puntero
    }
    
    *pINI=(SLL*) malloc( sizeof(SLL) );
    (*pINI)->data=newData;
}


void showList( SLL *pINI){

    if (pINI == NULL)
    {
        printf("\n La lista esta vacía \n");
    }else{
        printf("\n[\n");
        while (pINI != NULL)
        {
        printf("\t{\n");
            printf("\n\t\tNombre: \"%s\",", (pINI->data)->nombre);
            printf("\n\t\tId: \"%d\",\n", (pINI->data)->id);
            pINI=pINI->next;
        printf("\t},\n");
        }
        printf("\n]\n");
    }
}



void removeNode( SLL **pINI, int i ){

    while ( ((*pINI)->data)->id != i )
    {
        pINI=&(*pINI)->next;
    }
    
    SLL * target = *pINI;  //Puntero a parte, que apunta al objetivo
    *pINI=(*pINI)->next;   //El apuntador del nodo anterior al objetivo, apuntará al siguiente del objetivo
                           //Puenteando al objetivo y quitándolo de la lista 
    free(target->data);    //Se libera la data del objetivo
    free(target);          //Se libera el nodo 
}


void freeList( SLL **pINI){
    SLL * actual=*pINI;
    SLL * siguiente=0;

    while (actual != NULL)
    {
        siguiente=actual->next;
        free(actual->data);     //Se libera la data
        free(actual);           //Se libera el nodo
        actual=siguiente;
    }

    *pINI=0;
}