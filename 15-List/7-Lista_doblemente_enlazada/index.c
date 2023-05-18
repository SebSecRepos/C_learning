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

        while ( (aux != NULL) )
        {
            aux2=aux;           //aux2 queda en el anterior
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
            
            //aux2 ---> anteúltimo
            //aux  ---> último



            (*aux2).psig=(struct nodo *) malloc(sizeof(struct nodo));
            //El siguiente de aux2 ---> nuevo nodo malloqueado
            
            //Si aux es no null(No es el último), el nuevo nodo quedará entre medio de de pant y paux
            
            if( aux != NULL ){
                (*aux).pant=(*aux2).psig;

                //El anterior de aux  ---> nuevo nodo malloqueado
                //en este if es necesario especificarlo ya que aux no es null
            }

            //Si aux si es null, al agregarlo como siguiente al nuevo nodo estaremos finalizando la lista
            //y no es necesario enlazarlo como en el if ya que es null
            //quedando el nuevo nodo al final de la lista
            (*(*aux2).psig).pant=aux2;
            (*(*aux2).psig).psig=aux;
        
        }
        

    }

}

struct info * GenerarNodo(int n, char l, char* pl){

}