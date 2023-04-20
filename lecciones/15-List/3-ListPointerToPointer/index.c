
#include <stdio.h>
#include <string.h>

struct objeto{
    int id;
    char name[10];
    int edad;
    struct objeto * pSIG;
};


void showMod(struct objeto **ppAux);
void showNoMod(struct objeto *pAux);

int main(int argc, char * argv[])
{
    struct objeto * pINI=0;
    struct objeto * pAUX=0;

    struct objeto n1;
    struct objeto n2;
    struct objeto n3;

    n1.id=1;
    n1.edad=20;
    strcpy(n1.name, "juan");
    
    n2.id=2;
    n2.edad=30;
    strcpy(n2.name, "josé");

    n3.id=3;
    n3.edad=15;
    strcpy(n3.name, "sadfds");

    n1.pSIG=&n2;
    n2.pSIG=&n3;

    pINI=&n1;
    pAUX=pINI;

    struct objeto **pToPAUX=0;  //creación puntero a puntero paux
    pToPAUX=&pAUX;

    //modes
    char nomod[]="nomod";
    char mod[]="mod";

    if(argc >=2){

        if( strcmp(argv[1], mod)==0){
            showMod(pToPAUX);  //puntero a puntero
            printf("Valor de pAUX apunta a %p --> Ha cambiado", pAUX);
        }
        else if(strcmp(argv[1], nomod)==0){
            showNoMod(pAUX);  //puntero a puntero
            printf("Valor de pAUX apunta a %p  ----> No ha cambiado", pAUX);
        }
        return 0;

    }else{
        printf("Ingrese modo parámetros\n\n");
        printf("./remove <mod> o ./remove <nomod>");
    }

}

void showMod(struct objeto **ppAux)
{
    printf("======= Modificando la lista original (MAIN) ==========\n\n");

    while (*ppAux != 0) {
        
        printf("Id: %d \n", (*(*ppAux)).id);
        printf("Nombre %s \n", (*(*ppAux)).name);
        printf("Edad %d \n\n", (*(*ppAux)).edad);

        *ppAux=(*(*ppAux)).pSIG;
    }
}
void showNoMod(struct objeto *paux)
{
    printf("======= Sin modificar lista original (Nueva instancia en funcion) ==========\n\n");

    while (paux != 0) {
        printf("Id: %d \n", (*paux).id);
        printf("Nombre %s \n", (*paux).name);
        printf("Edad %d \n\n", (*paux).edad);

        paux=(*paux).pSIG;
    }
}