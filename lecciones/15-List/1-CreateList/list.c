// struct nodo
// {
//     char nombre[10];
//     int edad;
//     struct nodo *pSig;
// };


// int main()
// {
//     struct nodo n1;                     //creo el nodo
//     struct nodo * pINI=0;               //puntero a estructura de tipo nodo
//     struct nodo * pAUX=0;               //puntero a estructura de tipo nodo

    
//     strcpy(n1.nombre, "juan"); //cargo nombre
//     n1.edad=4;                          //cargo edad
//     n1.pSig=0;                          //cargo psig en 0


//     pINI=&(n1);                         //El inicio apunta al nodo creado
//     pAUX=pINI;                          //se hace pAUX=pINI ya que es mas eficiente  que pAUX=&(n1) 
//                                         //pAUX queda siempre al inicio de la lista

//     while (pAUX != 0) {
//         printf("nombre: %s edad: %d\n", (*pAUX).nombre, (*pAUX).edad);
//         pAUX=(*pAUX).pSig;
//     }
//     return 0;
// }


#include <stdio.h>
#include <string.h>


struct nodo
{
    char nombre[10];
    int edad;
    struct nodo *pSig;
};


int main()
{
    struct nodo n1;                     
    struct nodo n2;                     
    struct nodo n3;    

    struct nodo * pINI=0;      //Variables de lista         
    struct nodo * pAUX=0;               

    
    strcpy(n1.nombre, "juan"); 
    n1.edad=4;                          
    n1.pSig=0;   

    strcpy(n2.nombre, "pepe"); 
    n2.edad=4;                          
    n2.pSig=0;    

    strcpy(n3.nombre, "juan2"); 
    n3.edad=40;                          
    n3.pSig=0;     
    //Al crear un nodo, su puntero siguiente siempre es 0, luego lo actualizamos


    pINI=&(n1);     //enlazamos la lista actualizando los pSig
    n1.pSig=&n2;    
    n2.pSig=&n3;
                    //n3 quedara enlazado a 0 ya que es el último
    pAUX=pINI;     //apunta a inicio pero se actualiza con el while al siguiente p      



    while (pAUX != 0) {
        printf("nombre: %s edad: %d\n", (*pAUX).nombre, (*pAUX).edad);
        pAUX=(*pAUX).pSig;
    }

    return 0;
}


