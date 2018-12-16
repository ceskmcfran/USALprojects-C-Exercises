/*Programa:"invertir_vector.c".
Autor:Francisco Blázquez Matías.
Curso:Primero de GII del grupo B3.
Fecha: 18/11/2014.
Descripción:
Copyright:
*/


#include<stdio.h>
#include<stdlib.h>
#define LIM 100


int main (void){

    int listapri[LIM];
    int listainv[LIM];
    int i, dim1;

    printf("Programa en el cual se pide un vector y se le da la vuelta al vector escrito\n\n");

    do{

    printf("Escriba la longitud del vector a utilizar (entre 0 y 100):  ");
    scanf("%d", &dim1);

    }while((dim1 <= 0)||(dim1 > LIM));

    for(i = 0; i < dim1; i++){

        printf("\nIntroduzca el elemento %d:  ", i+1);
        scanf("%d", &listapri[i]);

    }

    for(i = 0; i < dim1; i++){

        listainv[dim1 - 1 - i] = listapri[i];

    }

    printf("\n\nEl vector normal y el invertido seran:");

    printf("\n(");

    for(i = 0;i < dim1; i++){

        printf(" %d ", listapri[i]);

    }

    printf(")\n");
    printf("(");

    for(i = 0;i < dim1; i++){

        printf(" %d ", listainv[i]);

    }

    printf(")\n\n");

system("pause");
return 0;
}
