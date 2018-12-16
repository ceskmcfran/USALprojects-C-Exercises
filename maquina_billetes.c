/*Autor: Francisco Blázquez Matías.
Fecha: 22/10/2014
Descripción: Programa que cambia billetes deteriorados por billetes nuevos*/

#include<stdio.h>
#include<stdlib.h>

int main (void){

    int quin, dosc, cien, cincuent, veint, diez, cinco, tot;
    int quin1, dosc1, cien1, cincuent1, veint1, diez1, cinco1, temp;

    printf("MAQUINA DE CAMBIO DE BILLETES\n");
    printf("================================\n\n");
    printf("Se solicitara el numero de billetes introducidos\n");
    printf("Se calculara el importe total introducido y se redistribuira en la menor cantidad\n");
    system("pause");

    system("cls");

    printf("INTRODUZCA EL NUMERO DE BILLETES COMO LE INDICA A CONTINUACION:");
    printf("\nBilletes de 500(euros):  ");
    scanf("%d", &quin);
    printf("\nBilletes de 200(euros):  ");
    scanf("%d", &dosc);
    printf("\nBilletes de 100(euros):  ");
    scanf("%d", &cien);
    printf("\nBilletes de 50(euros):  ");
    scanf("%d", &cincuent);
    printf("\nBilletes de 20(euros):  ");
    scanf("%d", &veint);
    printf("\nBilletes de 10(euros):  ");
    scanf("%d", &diez);
    printf("\nBilletes de 5(euros):  ");
    scanf("%d", &cinco);

    quin = quin * 500;
    dosc = dosc * 200;
    cien = cien * 100;
    cincuent = cincuent * 50;
    veint = veint * 20;
    diez = diez * 10;
    cinco = cinco * 5;

    tot = quin + dosc + cien + cincuent + veint + diez + cinco;

    printf("\n\nEl total de sus euros introducidos es:  %d", tot);

    quin1 = tot / 500;
    temp = tot % 500;

    dosc1 = temp / 200;
    temp = temp % 200;

    cien1 = temp / 100;
    temp = temp % 100;

    cincuent1 = temp / 50;
    temp = temp % 50;

    veint1 = temp / 20;
    temp = temp % 20;

    diez1 = temp / 10;
    temp = temp % 10;

    cinco1 = temp / 5;
    temp = temp % 5;

    printf("\n\nNUMERO DE BILLETES A ENTREGAR:");
    printf("\nBilletes de 500(euros):  %d", quin1);
    printf("\nBilletes de 200(euros):  %d", dosc1);
    printf("\nBilletes de 100(euros):  %d", cien1);
    printf("\nBilletes de 50(euros):  %d", cincuent1);
    printf("\nBilletes de 20(euros):  %d", veint1);
    printf("\nBilletes de 10(euros):  %d", diez1);
    printf("\nBilletes de 5(euros):  %d\n", cinco1);


    system("pause");
    return 0;
}
