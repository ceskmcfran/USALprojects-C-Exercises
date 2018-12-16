/*Programa:"conversor_pesetas_euros.c".
Autor:Francisco Blázquez Matías.
Curso:Primero de GII del grupo B3.
Fecha: 4/11/2014.
Descripción:
Copyright:
*/


#include<stdio.h>
#include<stdlib.h>
#define VALOREURO 166.386

int main (void){

    float imp_pta, imp_eur;
    char opcion;
    int salir = 0;

    do{

        system("cls");
        printf("==================================================\n");
        printf("        CONVERSOR PESETAS A EUROS\n");
        printf("==================================================\n");
        printf("\na) De pesetas a euros\n");
        printf("b) De euros a pesetas\n");
        printf("s) Salir\n\n");
        printf("Escriba la opcion deseada:  ");
        scanf("%c", &opcion);

        switch(opcion){

            case 'a':
            case 'A':

                printf("Escriba el importe en pesetas:  ");
                scanf("%f", &imp_pta);

                imp_eur = imp_pta / VALOREURO;

                printf("Su importe en euros es:  %f\n", imp_eur);
                system("pause");
                break;

            case 'b':
            case 'B':

                printf("Escriba el importe en euros:  ");
                scanf("%f", &imp_eur);

                imp_pta = imp_eur * VALOREURO;

                printf("Su importe en pesetas es:  %f\n", imp_pta);
                system("pause");
                break;

            case 's':
            case 'S':

                salir = 1;
                break;

        }

    }while(!salir);

system("pause");
return 0;
}
