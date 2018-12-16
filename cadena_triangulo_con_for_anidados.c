/*Programa:"".
Autor:Francisco Blázquez Matías.
Curso:Primero de GII del grupo B3.
Fecha: //.
Descripción:
Copyright:
*/


#include<stdio.h>
#include<stdlib.h>


int main (void){

    const char BLANCO = ' ';
    char car[10];
    int altura, i, j;

    printf("Teclee algo con lo que construir la piramide:  ");
    scanf("%s", &car);
    printf("\nTeclee la altura de la piramide:  ");
    scanf("%d", &altura);

    for(i = 1;i <= altura; i++){

        for(j = 1;j <= altura; j++){

            printf("%c", BLANCO);

        }

        for(j = 1; j <= i; j++){

            printf("%s", car);

        }

        printf("\n");

    }

system("pause");
return 0;
}
