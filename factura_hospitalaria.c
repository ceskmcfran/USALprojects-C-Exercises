/*Programa:"factura_hospitalaria.c".
Autor:Francisco Blázquez Matías.
Curso:Primero de GII del grupo B3.
Fecha: 25/10/2014.
Descripción:
Copyright:
*/


#include<stdio.h>
#include<stdlib.h>


int main (void){

    char nombre [50];
    int dia, mes, ano, diasing, diasfact, diasdeduc, temp;
    float costedia, costecons, costemed, costediv, costetotdias, costetot, deducdia, deducporc, deducseg, deducmed, deductot, tot;

    printf("===========================================================\n");
    printf("            CALCULO DE FACTURA HOSPITALARIA\n");
    printf("===========================================================\n\n");
    printf("DATOS DEL PACIENTE\n");
    printf("   Nombre:  ");
    gets(nombre);
    printf("   Fecha de ingreso:\n");
    printf("\tDia:  ");
    scanf("%d", &dia);
    printf("\tMes:  ");
    scanf("%d", &mes);
    printf("\tAno:  ");
    scanf("%d", &ano);
    printf("   Numero de dias ingresado:  ");
    scanf("%d", &diasing);

    printf("\n\nCOSTES\n");
    printf("   Coste por dia..........................:  ");
    scanf("%f", &costedia);
    printf("   Coste consultas........................:  ");
    scanf("%f", &costecons);
    printf("   Coste medicamentos.....................:  ");
    scanf("%f", &costemed);
    printf("   Costes diversos........................:  ");
    scanf("%f", &costediv);

    printf("\n\nDEDUCCIONES\n");
    printf("    Deduccion diaria del Seguro...............:  ");
    scanf("%f", &deducdia);
    printf("    Porcentaje deduccion ayuda medicamentos...:  ");
    scanf("%f", &deducporc);

    temp = diasing / 4;
    diasfact = diasing - temp;

    costetotdias = costedia * diasfact;
    costetot = costetotdias + costecons + costemed + costediv;

    if(costemed > 90){

        deducmed = -((deducporc * costemed) / 100);

    }

    else{

        deducmed = 0;

    }

    if(diasing >= 3){

        diasdeduc = - (diasing - 2);
        deducseg = (diasdeduc * deducdia);
        deductot = deducmed + deducseg;

    }

    else {

        diasdeduc = 0;
        deducseg = 0;
        deducmed = 0;
        deductot = 0;

    }

    tot = costetot + deductot;

    if (tot >= 0){

        tot = tot;

    }

    else {

        tot = 0;

    }


    system("cls");
    printf("===========================================================\n");
    printf("                FACTURA HOSPITALARIA\n");
    printf("===========================================================\n\n");
    printf("PACIENTE....................: %s \n", nombre);
    printf("INGRESO.....................: %d/%d/%d\n", dia, mes, ano);
    printf("DIAS INGRESADO..............: %d\n\n", diasing);

    printf("DIAS FACTURADOS.....................:\t%d\n", diasfact);
    printf("COSTE TOTAL DIAS ESTANCIA...........:\t%.2f\n", costetotdias);
    printf("COSTE TOTAL.........................:\t%.2f\n\n", costetot);

    printf("DIAS DEDUCCION SEGURO...............:\t%d\n", diasdeduc);
    printf("DEDUCCION SEGURO....................:\t%.2f\n", deducseg);
    printf("DEDUCCION POR MEDICAMENTOS..........:\t%.2f\n", deducmed);
    printf("DEDUCCION TOTAL.....................:\t%.2f\n\n", deductot);

    printf("TOTAL A PAGAR.......................:\t%.2f\n\n", tot);




system("pause");
return 0;
}
