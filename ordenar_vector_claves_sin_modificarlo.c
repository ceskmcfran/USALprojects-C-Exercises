/*Programa:"ordenar_vector_claves_sin_modificarlo.c".
Autor:Francisco Blázquez Matías.
Curso:Primero de GII del grupo B3.
Fecha: 29/11/2014.
Descripción: Ordena un vector de enteros sin modificar el original mediante un vector de punteros.
Copyright:
*/

#define DIM 15
#include<stdio.h>
#include<stdlib.h>
#define LIMI 1000
#define LIMS 7000


int main (void){

    int igual;
    int vect[DIM] = {};
    int i, j, k;
    int *p[DIM];

    printf("Introduce las %d claves enteras (entre %d y %d) y que no se repitan.\n\n", DIM, LIMI, LIMS);

    for(i=0; i < DIM; i++){

        igual = 0;

        do{

            printf("Clave numero[%d]:  ", i+1);
            scanf("%d", &vect[i]);

            if((vect[i] < 1000)||(vect[i] > 7000)){

                printf("\nLa clave introducida no esta entre los limites establecidos (%d y %d)\nEscribela otra vez\n\n", LIMI, LIMS);

            }

            for(j=i-1; j >= 0; j--){

                if(vect[i] == vect[j]){

                    printf("\nHa introducido repetida la clave numero[%d]\nEscribala otra vez\n\n", i+1);
                    printf("Clave numero[%d]:  ", i+1);
                    scanf("%d", &vect[i]);
                    igual == 1;

                }
            }

        }while((vect[i] < 1000)||(vect[i] > 7000)||(igual =! 1));

    }

    k=0;

    for(j=1000; j<=7000; j++){
        for(i=0; i<DIM; i++){

            if(j==vect[i]){

                p[k]= &vect[i];
                k++;

            }

        }
    }

    system("cls");
    printf("El vector de claves es:\n{");

    for(i=0;i<DIM; i++){

         printf(" %d ", vect[i]);

    }

    printf("}\n\n");
    printf("El vector de claves ordenado es:\n{");

    for(i=0; i<DIM; i++){

        printf(" %d ", *p[i]);

    }

    printf("}\n\n");

system("pause");
return 0;
}
