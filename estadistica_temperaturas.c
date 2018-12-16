/*Programa:"".
Autor:Francisco Blázquez Matías.
Curso:Primero de GII del grupo B3.
Fecha: //.
Descripción:
Copyright:
*/


#include<stdio.h>
#include<stdlib.h>
#define LIMINF -99
#define LIMSUP 99

int main (void){

    char salir;
    float temp;
    float cant = 0, media = 0, tot_pos = 0, tot_neg = 0, tot_cero = 0;

    do{


        printf("Escriba temperaturas en grados centigrados para hacer su estadistica\n");
        printf("\nPARA TERMINAR TIENES QUE ESCRIBIR UN NUMERO MAYOR A 99 O MENOR A -99\n\n");
        printf("Escribe la temperatura:  ");
        scanf("%f", &temp);


        while((temp > LIMINF)&&(temp < LIMSUP)){

            cant++;
            media += temp;

            if(temp > 0){

                tot_pos++;

            }

            else if(temp < 0){

                    tot_neg++;

                }
                else{

                    tot_cero++;
                }



            printf("Escribe la temperatura:  ");
            scanf("%f", &temp);

        }

        media /= cant;

        printf("El numero de temperaturas introducidas es:............%.f\n", cant);
        printf("La media de las temperaturas introducidas es:.........%f\n", media);
        printf("El numero de temperaturas por encima de cero es:......%.f\n", tot_pos);
        printf("El numero de temperaturas por debajo de cero es:......%.f\n", tot_neg);
        printf("Veces que se introdujo el valor cero:.................%.f\n", tot_cero);

        system("pause");

        do{

            system("cls");
            printf("Salir del programa(S/N)");
            fflush(stdin);
            scanf("%c", &salir);
            salir = toupper(salir);
            system("cls");

        }while((salir != 'S')&&(salir != 'N'));

    }while(salir != 'S');

system("pause");
return 0;
}
