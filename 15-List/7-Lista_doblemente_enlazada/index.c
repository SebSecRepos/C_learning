#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

struct info
{
    int dni;
    char sexo;
    char *nombre;
};
struct nodo
{
    struct nodo *psig;
    struct nodo *pant;
    struct info *Info;
};

int InsertarNodo(struct nodo **, struct info *);
int MostrarLista( struct nodo * );

struct info * GenerarNodo(int, char, char*);

int main(){

    srandom( time(NULL) );
    struct nodo *pinicio=0;
    int i=0;

    for ( i = 5; i > 0; i--)
    {
        printf("Ingrese número\n");
        InsertarNodo(&pinicio, GenerarNodo(random()%100,'M',0));
    }
    printf("Lista llena\n");
    MostrarLista(pinicio);
    return 0;
}

int InsertarNodo(struct nodo **ppIni, struct info *dato){

    struct nodo *aux = *ppIni;
    struct nodo *aux2 = *ppIni;

    if(*ppIni == NULL){

        (*ppIni)= (struct nodo *) malloc(sizeof(struct nodo));

        (*(*ppIni)).psig=NULL;
        (*(*ppIni)).pant=NULL;
        (*(*ppIni)).Info=dato;

        return 0;
    }else{

        while ( (aux != NULL) && ( (*aux).Info->dni ) > (*dato).dni )
        {
            aux2=aux;
            aux=(*aux).psig;
        }

        if (aux == *ppIni){
            (*(*ppIni)).pant=( struct nodo * ) malloc(sizeof(struct nodo));
            //pini tiene enlazado pant
            //pero pant no tiene enlazado su siguiente y su anterior

            (*(*ppIni)).pant->psig=(*ppIni); 
            (*(*ppIni)).pant->pant=NULL; 

            (*ppIni)=(*(*ppIni)).pant;  //El primer nodo ahora es el anterior

            (*(*ppIni)).Info=dato; //Cargamos la info del primer nuevo nodo
        }else{
            (*aux2).psig=(struct nodo *) malloc(sizeof(struct nodo));
            if(aux != NULL){ //si el último no es null
                (*aux).pant=(*aux2).psig;

            }
        }
        
        // aux2 = anteúltimo   -->

        // <---  aux =  último

        // el sig del anteúltimo =>  el nuevo nodo " malloc"
        // el anterior de aux =  

    }

}