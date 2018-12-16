/*Programa:"invertir_cadena_caracteres.c".
Autor:Francisco Blázquez Matías.
Curso:Primero de GII del grupo B3.
Fecha: 18/11/2014.
Descripción: Lee una cadena de caracteres y la invierte.
Copyright:
*/


#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define LIM 80


int main (void){

    char opcion; //Opción del menu
    char cadpri[LIM] = ""; //Cadena principal que se lee por teclado
    char cadinv[LIM] = ""; //Cadena invertida
    int i; //Contador
    int dim1; //Tamaño de cadpri[]

    do{ //MENU

        i = 0;

        system("cls");

        printf("=========================================================\n");
        printf("                MAXIMOS Y MINIMOS DE MATRICES\n");
        printf("=========================================================\n\n");
        printf(" a) Introducir cadena de caracteres\n");
        printf(" b) Invertir cadena de caracteres\n");
        printf(" c) Mostrar ambas cadenas\n\n");
        printf(" s) Salir\n\n");
        printf("Introduzca la opcion deseada:  ");
        scanf("%c%*c", &opcion);

        switch(opcion){

            case 'a':


                system("cls");

                do{

                    printf("Introduzca la cadena de caracteres:  ");
                    scanf("%[^\n]%*c", cadpri);

                    dim1 = strlen(cadpri);

                    if(dim1 > LIM){

                        printf("\nIntroduzca una cadena de menos de 100 caracteres\n");
                        system("pause");
                        system("cls");

                    }

                }while(dim1 >  LIM);
                system("pause");
                break;

            case 'b': //INVERTIR CADENA DE CARACTERES

                system("cls");

                i=0;

                while(cadpri[i] != '\0'){

                    cadinv[dim1 - 1 - i] = cadpri[i];
                    i++;

                }
                cadinv[dim1] = '\0';
                printf("La cadena ha sido invertida\n\n");
                system("pause");
                break;

            case 'c': //IMPRIMIR CADENAS

                printf("\n\nLa cadena de caracteres escrita es: \n%s", cadpri);
                printf("\n\nLa cadena de caracteres invertida es: \n%s\n\n", cadinv);
                system("pause");
                break;

        }

    }while(opcion != 's');

system("pause");
return 0;
}
