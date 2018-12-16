/*Programa:"conversion_arabigo_romano.c".
Autor:Francisco Blázquez Matías.
Curso:Primero de GII del grupo B3.
Fecha: 25/10/2014.
Descripción:
Copyright:
*/

//TIENE UN ERROR AL SACAR LA VARIABLE numrom POR PANTALLA, YA QUE SACA UNOS DIGITOS Y LETRAS ANTES.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ANIOMIN 1
#define ANIOMAX 3000

int main (void){

    int num;
    char numrom [25];
    int unidad, decena, centena, millar;
    int temp;

    printf("Escribe el numero a convertir en romano:  ");
    scanf("%d", &num);

    if((num > ANIOMAX) || (num < ANIOMIN)) {

        printf("\nEl ano tecleado no es correcto\n");

    }

    else {

        millar = num / 1000;
        temp = num % 1000;

        centena = temp / 100;
        temp = temp % 100;

        decena = temp / 10;
        unidad = temp % 10;



    switch (millar){

        case 1:

            strcpy(numrom, "M");
            break;

        case 2:

            strcpy(numrom, "MM");
            break;

        case 3:

            strcpy(numrom, "MMM");
            break;

        case 0:

            break;

    }

    switch (centena){

        case 0:

            break;

        case 1:

            strcat(numrom, "C");
            break;

        case 2:

            strcat(numrom, "CC");
            break;

        case 3:

            strcat(numrom, "CCC");
            break;

        case 4:

            strcat(numrom, "CD");
            break;

        case 5:

            strcat(numrom, "D");
            break;

        case 6:

            strcat(numrom, "DC");
            break;

        case 7:

            strcat(numrom, "DCC");
            break;

        case 8:

            strcat(numrom, "DCCC");
            break;

        case 9:

            strcat(numrom, "CM");
            break;

    }

    switch (decena){

        case 0:

            break;

        case 1:

            strcat(numrom, "X");
            break;

        case 2:

            strcat(numrom, "XX");
            break;

        case 3:

            strcat(numrom, "XXX");
            break;

        case 4:

            strcat(numrom, "XL");
            break;

        case 5:

            strcat(numrom, "L");
            break;

        case 6:

            strcat(numrom, "LX");
            break;

        case 7:

            strcat(numrom, "LXX");
            break;

        case 8:

            strcat(numrom, "LXXX");
            break;

        case 9:

            strcat(numrom, "XC");
            break;

    }

    switch (unidad){

        case 0:

            break;

        case 1:

            strcat(numrom, "I");
            break;

        case 2:

            strcat(numrom, "II");
            break;

        case 3:

            strcat(numrom, "III");
            break;

        case 4:

            strcat(numrom, "IV");
            break;

        case 5:

            strcat(numrom, "V");
            break;

        case 6:

            strcat(numrom, "VI");
            break;

        case 7:

            strcat(numrom, "VII");
            break;

        case 8:

            strcat(numrom, "VIII");
            break;

        case 9:

            strcat(numrom, "IX");
            break;

    }

    printf("El numero en romano es: %s \n", numrom);

    }
system("pause");
return 0;
}
