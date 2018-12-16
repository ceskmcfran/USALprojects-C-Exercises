/*Programa:"lectura_de_elementos_matriz_con_punteros.c".
Autor:Francisco Blázquez Matías.
Curso:Primero de GII del grupo B3.
Fecha: 29/11/2014.
Descripción:
Copyright:
*/

#define FIL 10
#define COL 10
#include<stdio.h>
#include<stdlib.h>

int main (void){

    int f,c;
    double mat[FIL][COL];

    for(f=0; f<FIL; f++){
        for(c = 0; c < COL; c++){

            printf("Elemento [%d][%d]:  ", f, c);
            scanf("%lf", *(mat+f)+c);

        }
    }



system("pause");
return 0;
}
