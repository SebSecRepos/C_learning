#include<stdio.h>

int main()
{
    //4 arrays de char(strings)
    char l1[]="hola";       //["h", "o", "l", "a"]      ---> 4 bytes  (4 direcciones de memoria)
    char l2[]="mundo";      //["m", "u", "n", "d", "o"] -----> 5 bytes (5 direcciones de memoria) 
    char l3[]="que";        //["q", "u", "e"]           ----> 3 bytes   (3 direcciones de memoria)
    char l4[]="tal";        //["t", "a", "l"]           ----> 3 bytes   (3 direcciones de memoria)

// 1 array de punteros de arrays tipo char(strings)
    char *pChars[4];     

    pChars[0]=&(l1);    //pchar[0] ocupa desde l1[0] hasta l1[3]
    pChars[1]=&(l2);
    pChars[2]=&(l3);  
    pChars[3]=&(l4);        

    //Para mostrar el contenido utilizamos solo el array de punteros, 

                                                                                                                                        //                          Puntero                    No puntero       
                                                                                                                                        //           1°Letra %c    Dirección%p  ult letra%c   dirección%p   cadena completa%s
    printf("\npChars[0] \n \t - Desde ----> (\"%c\"): %p (Referencia de puntero) \n \t - Hasta ----> (\"%c\"): %p \n \t - Su contenido es: %s \n \n",pChars[0][0] , pChars[0], pChars[0][3], &pChars[0][3], pChars[0]);
    printf("\npChars[1] \n \t - Desde ----> (\"%c\"): %p (Referencia de puntero) \n \t - Hasta ----> (\"%c\"): %p \n \t - Su contenido es: %s \n \n",pChars[1][0] , pChars[1], pChars[1][4], &pChars[1][4], pChars[1]);
    printf("\npChars[2] \n \t - Desde ----> (\"%c\"): %p (Referencia de puntero) \n \t - Hasta ----> (\"%c\"): %p \n \t - Su contenido es: %s \n \n",pChars[2][0] , pChars[0], pChars[0][2], &pChars[0][2], pChars[2]);
    printf("\npChars[3] \n \t - Desde ----> (\"%c\"): %p (Referencia de puntero) \n \t - Hasta ----> (\"%c\"): %p \n \t - Su contenido es: %s \n \n",pChars[3][0] , pChars[3], pChars[3][2], &pChars[1][2], pChars[3]);


    return 0;
}