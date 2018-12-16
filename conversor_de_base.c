/*Programa:"conversor_de_base.c".
Autor:Francisco Blázquez Matías.
Curso:Primero de GII del grupo B3.
Fecha: 25/10/2014.
Descripción:
Copyright:
*/


#include<stdio.h>
#include<stdlib.h>


int main (void){

    int num, opcion;

    printf("======================================\n");
    printf("        MENU DE CONVERSOR DE BASE\n");
    printf("======================================\n");
    printf("\n\n1) De decimal a octal y hexadecimal.");
    printf("\n2) De octal a decimal y hexadecimal.");
    printf("\n3) De hexadecimal a octal y decimal.");
    printf("\notro) Salir\n\n");

    printf("Escribe la opcion a escoger:   ");
    scanf("%d", &opcion);

    switch (opcion){

        case 1:

            system("cls");
            printf("Escribe el numero a cambiar:  ");
            scanf("%d", &num);

            printf("Decimal...........%d\n", num);
            printf("Octal.............%o\n", num);
            printf("Hexadecimal.......%X\n", num);;
            break;

        case 2:

            system("cls");
            printf("Escribe el numero a cambiar:  ");
            scanf("%o", &num);

            printf("Decimal...........%d\n", num);
            printf("Octal.............%o\n", num);
            printf("Hexadecimal.......%X\n", num);
            break;

        case 3:

            system("cls");
            printf("Escribe el numero a cambiar:  ");
            scanf("%X", &num);

            printf("Decimal...........%d\n", num);
            printf("Octal.............%o\n", num);
            printf("Hexadecimal.......%X\n", num);
            break;

        default:

            break;
    }

system("pause");
return 0;
}
