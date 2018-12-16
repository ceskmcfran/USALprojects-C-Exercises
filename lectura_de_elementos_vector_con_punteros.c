/*Programa:"lectura_de_elementos_vector_con_punteros.c".
Autor:Francisco Blázquez Matías.
Curso:Primero de GII del grupo B3.
Fecha: //.
Descripción:Lee 10 elementos introducidos por teclado mediante punteros.
Copyright:
*/

#define DIM 10
#include<stdio.h>
#include<stdlib.h>


int main (void){

    int i;
    float v[DIM];

    for(i = 0; i < DIM; i++){

        printf("Elemento[%d]:  ", i+1);
        scanf("%f", v+i);

    }

system("pause");
return 0;
}
