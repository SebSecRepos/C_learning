
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SinglyLinkedList
{

    int value;
    struct SinglyLinkedList *next;
    struct SinglyLinkedList *prev;
};
typedef struct SinglyLinkedList SLL; // alias SinglyLinkedList  --> SLL

void addNode(SLL **pINI, int n)
{

    if ((*pINI) == NULL)
    {

        (*pINI) = (SLL *)malloc(sizeof(SLL));
        (*pINI)->value = n;
        (*pINI)->next = NULL;
    }
    else
    { // SI no esta vacía la lista, el nuevo nodo va al final
        SLL *paux = (*pINI);
        SLL *paux2 = 0;

        while (paux->next != NULL)
        {
            paux2 = paux;
            paux = paux->next;
        }

        paux->next = (SLL *)malloc(sizeof(SLL));
        (paux->next)->value = n;
        (paux->next)->next = NULL;
        (paux->next)->prev = paux;
        paux = paux->next;
    }
};

void showList(SLL *pINI)
{

    if (pINI == NULL)
    {
        printf("\nNo hay elementos en la lista \n");
    }
    else
    {

        while (pINI != NULL)
        {
            printf("\n NUmero: %d", pINI->value);
            pINI = pINI->next;
        }
    }
}

void removeLinusWay(SLL **p, int value)
{

    while ((*p)->value != value)
    {
        p = &(*p)->next; // Puntero a puntero del siguiente nodo, si no fuera puntero a puntero estaríamos
    }                   //creando en p un nuevo apuntador sin poder modificar el apuntador original del nodo
    SLL *target = *p; // objetivo encontrado, puntero al nodo a eliminar

    //*p ahora es el puntero que apunta al objetivo
    // Este mismo puntero es el elemento (siguiente) que pertenece al nodo  anterior
    // Entonces al apuntar *p al siguiente del objetivo, saltamos al objetivo dejándolo fuera

    //Si no hubieramos usado un puntero doble, no hubiesemos podido acceder al apuntador siguiente de cada
    //nodo, si no que hubiesemos creado un puntero nuevo sin poder modificar el objeto apuntador siguiente de cada nodo

    *p = target->next; // puntero al siguiente del objetivo
                       // p no apunta al objetivo si no a su siguiente
                       // el anterior de target

    free(target);
}

int main()
{

    SLL *pINI = NULL;

    for (int i = 0; i < 3; i++)
    {
        addNode(&pINI, i);
    }
    showList(pINI);
    printf("\n\n----Nodo removido----\n");
    removeLinusWay(&pINI, 1);
    showList(pINI);
    return 0;
}
