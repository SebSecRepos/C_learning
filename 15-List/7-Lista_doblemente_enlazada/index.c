// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>

// struct info
// {
//     int id;
//     char nombre[10];
// };
// struct nodo
// {
//     struct nodo *psig;
//     struct nodo *pant;
//     struct info *Info;
// };

// int InsertarNodo(struct nodo **, struct info *);
// int MostrarLista( struct nodo * );
// void freeList(struct nodo **pINI);

// int main(){

//     struct nodo *pinicio=0;
//     int i=0;

//     for ( i = 0; i < 2; i++)
//     {
//         struct info *pNewInfo= (struct info*) malloc(sizeof(struct info));
//         pNewInfo->id=i;

//         printf("\n Ingrese nombre: \n");
//         scanf("%s", pNewInfo->nombre);
//         InsertarNodo(&pinicio, pNewInfo);
//     }
//     MostrarLista(pinicio);
//     return 0;
// }

// int InsertarNodo(struct nodo **ppIni, struct info *dato){

//     struct nodo *aux = *ppIni;
//     struct nodo *aux2 = *ppIni;

//     if(*ppIni == NULL){

//         (*ppIni)= (struct nodo *) malloc(sizeof(struct nodo));

//         (*(*ppIni)).psig=NULL;
//         (*(*ppIni)).pant=NULL;
//         (*(*ppIni)).Info=dato;

//         return 0;
//     }else{

//         while ( (aux != NULL) )
//         {
//             aux2=aux;           //aux2 queda en el anterior
//             aux=(*aux).psig;
//         }

//         if (aux == *ppIni){
//             (*(*ppIni)).pant=( struct nodo * ) malloc(sizeof(struct nodo));
//             //pini tiene enlazado pant
//             //pero pant no tiene enlazado su siguiente y su anterior

//             (*(*ppIni)).pant->psig=(*ppIni); 
//             (*(*ppIni)).pant->pant=NULL; 

//             (*ppIni)=(*(*ppIni)).pant;  //El primer nodo ahora es el anterior

//             (*(*ppIni)).Info=dato; //Cargamos la info del primer nuevo nodo
//         }else{
            
//             //aux2 ---> anteúltimo
//             //aux  ---> último



//             (*aux2).psig=(struct nodo *) malloc(sizeof(struct nodo));
//             //El siguiente de aux2 ---> nuevo nodo malloqueado
            
//             //Si aux es no null(No es el último), el nuevo nodo quedará entre medio de de pant y paux
            
//             if( aux != NULL ){
//                 (*aux).pant=(*aux2).psig;

//                 //El anterior de aux  ---> nuevo nodo malloqueado
//                 //en este if es necesario especificarlo ya que aux no es null
//             }

//             //Si aux si es null, al agregarlo como siguiente al nuevo nodo estaremos finalizando la lista
//             //y no es necesario enlazarlo como en el if ya que es null
//             //quedando el nuevo nodo al final de la lista
//             (*(*aux2).psig).pant=aux2;
//             (*(*aux2).psig).psig=aux;
//             (*(*aux2).psig).Info=dato;
//         }
        

//     }

// }


// int MostrarLista( struct nodo * pINI ){

//     if( pINI == NULL ){

//         printf("\nLa lista esta vacía \n");
//         return 0;
//     }else{
//         while ( pINI != NULL)
//         {
//             printf("\nEl nombre es: %s \n",(pINI->Info)->nombre);
//             printf("El id de %s es: %d \n",(pINI->Info)->nombre, (pINI->Info)->id);

//             pINI=pINI->psig;
//         }
//         return 0;
        
//     }
// }

// void freeList(struct nodo **pINI){

//     if( *pINI == NULL ){

//         printf("La lista ha sido vaciada");
//     }else{

//         struct nodo *pactual=*pINI;
//         struct nodo *psiguiente=0;

//         while (pactual != NULL )
//         {
//             psiguiente=pactual->psig;
//             free(pactual);
//             pactual=psiguiente;
//         }

//         (*pINI)=0;
//     }
// }



#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct info
{
    int id;
    char nombre[10];
};
struct nodo
{
    struct nodo *psig;
    struct nodo *pant;
    struct info *Info;
};

void freeList(struct nodo **pINI);
void addNode(struct nodo ** pINI, struct info *data);
void showList(struct nodo* pINI);
struct info* createData(int i);
void removeNode(struct nodo ** pINI, int n);

int main(){

    struct nodo * pINI=0;
    int i=0;

    for ( i = 0; i < 3; i++)
    {
        addNode(&pINI, createData(i));
    }
    
    showList(pINI);
    printf("\n \n----- Borramos un nodo -----\n");
    removeNode(&pINI, 0);
    showList(pINI);
    freeList(&pINI);
    printf("\n \n----- Liberamos memoria -----\n");
    showList(pINI);
}

void showList(struct nodo* pINI){

    if (pINI == NULL)
    {
        printf("\nNo hay elementos en la lista \n");
    }else{

        while (pINI != NULL)
        {
            printf("\nNombre: %s, id: %d", (pINI->Info)->nombre, (pINI->Info)->id);
            pINI=pINI->psig;
        }
    }
}

struct info* createData(int i){

    struct info * data = (struct info *) malloc(sizeof(struct info ));
    data->id=i;

    printf("\n Ingrese el nombre \n");
    scanf("%s",data->nombre);

    return data;
}

void addNode(struct nodo ** pINI, struct info *data){

    if( (*pINI) == NULL ){

        (*pINI)=(struct nodo * ) malloc( sizeof( struct nodo ) );
        (*pINI)->Info=data;
        (*pINI)->pant=NULL;
        (*pINI)->psig=NULL;

    }else{ //SI no esta vacía la lista, el nuevo nodo va al final
        struct nodo *paux=(*pINI);
        struct nodo *paux2=0;

        while ( paux->psig != NULL)
        {
            paux2=paux;
            paux=paux->psig;
        }
        
        paux->psig = (struct nodo *) malloc(sizeof(struct nodo ));
        (paux->psig)->Info=data;
        (paux->psig)->psig=NULL;
        (paux->psig)->pant=paux;
        paux=paux->psig;
    }
    
};

void removeNode( struct nodo **pINI, int n ){

    struct nodo * paux=(*pINI);

    while ( (paux->Info)->id != n ) //recorremos la lista hasta que su id sea el del nodo que queremos remover
    {
        paux=paux->psig;
    }

    
}




void freeList(struct nodo **pINI){

    if( (*pINI) == NULL ){
        printf("\n La lista ya ha sido vaciada\n");
    }else{

        struct nodo *current=(*pINI);
        struct nodo *next=0;

        while ( current != NULL)
        {
            next=current->psig;
            free(current->Info);
            free(current);
            current=next;
        }

        (*pINI)=NULL;
    }
}


