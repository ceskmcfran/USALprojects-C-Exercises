/*Programa:"descomponer_int_cifras.c".
Autor:Francisco Blázquez Matías.
Curso:Primero de GII del grupo B3.
Fecha: 18/10/2014.
Descripción: Descomposición de un número entero en sus cifras
Copyright:
*/


#include<stdio.h>
#include<stdlib.h>


int main (void){

    int num, temp, unidades, decenas, centenas, unimill;

    printf("Escriba un numero de cuatro cifras que quiera descomponer:\n");
    scanf("%d", &num);

    printf("\nEl numero introducido es:.....%d\n\n", num);
    printf("La descomposicion por la derecha sera:\n");

    unidades = num % 10;
    temp = num / 10;

    printf("Unidades:....................%d\n", unidades);

    decenas = temp % 10;
    temp = temp / 10;

    printf("Decenas:.....................%d\n", decenas);

    centenas = temp % 10;
    unimill = temp / 10;

    printf("Centenas:....................%d\n", centenas);
    printf("Unidades de millar:..........%d\n\n", unimill);

    printf("----------------------------------------------\n\n");

    printf("La descomposicion por la izquierda sera:\n");

    unimill = num / 1000;
    temp = num % 1000;

    printf("Unidades de millar:..........%d\n", unimill);

    centenas = temp / 100;
    temp = temp % 100;

    printf("Centenas:....................%d\n", centenas);

    decenas = temp / 10;
    unidades = temp % 10;

    printf("Decenas:.....................%d\n", decenas);
    printf("Unidades:....................%d\n\n", unidades);



system("pause");
return 0;
}
