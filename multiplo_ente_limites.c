/*Programa:"multiplo_entre_limites.c".
Autor:Francisco Blázquez Matías.
Curso:Primero de GII del grupo B3.
Fecha: 1/11/2014.
Descripción: Realiza todos los multiplos entre unos limites,
Copyright:
*/


#include<stdio.h>
#include<stdlib.h>
#define LIMS 30000
#define LIMI 0

int main (void){

    int lim1, lim2, num;
    float suma = 0;
    int cuantos = 0, temp, i;


    printf("Introduce los limites entre los que quieres que salgan los multiplos (Maximo entre 0 y 30000)\n\n");

    do{

        printf("Introduzca limite inferior:  ");
        scanf("%d", &lim1);

    }while((lim1 < LIMI)||(lim1 > LIMS));

    do{

        printf("\nIntroduzca el limite superior(entre 0 y 30000):  ");
        scanf("%d", &lim2);

    }while((lim2 < LIMI)||(lim2 > LIMS));

    if(lim2 < lim1){

        temp = lim1;
        lim1 = lim2;
        lim2 = temp;

    }

    do{

        printf("\nIntroduzca el numero a investigar:  ");
        scanf("%d", &num);

    }while((num < lim1)||(num > lim2));

    for(i = lim1; i <= lim2; i++){

       if ( !(i % num) )
         { cuantos++;
           suma += i;
           printf("%8d", i);
         }
    }
  printf("\n");
  printf("Numeros presentados %d\n", cuantos);
  printf("Valor de su suma %g\n", suma);

  printf("\n");



system("pause");
return 0;
}
