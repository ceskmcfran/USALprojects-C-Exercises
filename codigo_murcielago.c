/*Programa:"codigo_murcielago.c".
Autor:Francisco Blázquez Matías.
Curso:Primero de GII del grupo B3.
Fecha: 25/10/2014.
Descripción: Codifica dígito a dígito un número entero positivo de hasta 4 cifras
   utilizando el siguiente código
        Valor del dígito: 9  8  7  6  5  4  3  2  1  0
        Código asociado : M  U  R  C  I  E  L  A  G  O

Copyright:
*/

#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>

void descomponer(int, int *, int *, int *, int *);
int codificacion(int);

int main (void){

    int unidades, decenas, centenas, millares, temp, num;
    char murcielago [5];

    do{

        printf("Escribe el precio a codificar:  ");
        scanf("%d", &num);

    }while((num <= 0)||(num > 9999));

    descomponer(num, &unidades, &decenas, &centenas, &millares);

    murcielago[0] = codificacion(millares);
    murcielago[1] = codificacion(centenas);
    murcielago[2] = codificacion(decenas);
    murcielago[3] = codificacion(unidades);
    murcielago[4] = '\0';

    printf("\nEl valor codificado es: %s\n", murcielago);



system("pause");
return 0;
}

//--------------------------------------

void descomponer(int num, int *u, int *d, int *c, int *m){

    int temp;

        *m = num / 1000;
        temp = num % 1000;

        *c = temp / 100;
        temp = temp % 100;

        *d = temp / 10;
        *u = temp % 10;

}

//---------------------------------------

int codificacion(int digito){

    char codigo;

    switch (digito){

        case  9 : codigo = 'M'; break;
        case  8 : codigo = 'U'; break;
        case  7 : codigo = 'R'; break;
        case  6 : codigo = 'C'; break;
        case  5 : codigo = 'I'; break;
        case  4 : codigo = 'E'; break;
        case  3 : codigo = 'L'; break;
        case  2 : codigo = 'A'; break;
        case  1 : codigo = 'G'; break;
        case  0 : codigo = 'O'; break;
     }

return(codigo);

}
