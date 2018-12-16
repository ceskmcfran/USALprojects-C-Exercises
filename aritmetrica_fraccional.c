/*Programa:"aritmetrica_fraccional.c".
Autor:Francisco Blázquez Matías.
Curso:Primero de GII del grupo B3.
Fecha: 21/2/2015.
Descripción: El usuario elige una operacion y dos fracciones y se realiza la operacion.
Copyright:
*/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct fraccion{

    int num;
    int den;

};


void leer_fraccion(struct fraccion *);
void mostrar_fraccion(struct fraccion);
struct fraccion suma(struct fraccion, struct fraccion);
struct fraccion resta(struct fraccion, struct fraccion);
struct fraccion multiplicacion(struct fraccion, struct fraccion);
struct fraccion division(struct fraccion, struct fraccion);


int main(void){

    struct fraccion f1, f2;
    char operador;

    printf("Introduzca la primera fraccion: \n\n");
    leer_fraccion(&f1);
    printf("\n\n\nIntroduzca la segunda fraccion:  \n\n");
    leer_fraccion(&f2);

    do{

    system("cls");
    printf("\nElige un operador(+,-,/,*):  ");
    scanf("%c", &operador);

    printf("\n\n");

    }while((operador != '+')&&(operador != '-')&&(operador != '*')&&(operador != '/'));

    if(operador == '+'){

        mostrar_fraccion(suma(f1, f2));
        system("pause");

    }
        else if(operador == '-'){

            mostrar_fraccion(resta(f1, f2));
            system("pause");

        }
            else if(operador == '*'){

                mostrar_fraccion(multiplicacion(f1, f2));
                system("pause");

            }
            else if(operador == '/'){

                mostrar_fraccion(division(f1, f2));
                system("pause");

            }


system("pause");
return 0;
}



void leer_fraccion(struct fraccion *a){

    printf("Introduzca el numerador: ");
    scanf("%d", &a->num);
    printf("Introduzca el denominador: ");
    scanf("%d", &a->den);

}

void mostrar_fraccion(struct fraccion a){

    printf("Numerador: %d\n", a.num);
    printf("Denominador: %d\n", a.den);

}

struct fraccion suma(struct fraccion a, struct fraccion b){

    struct fraccion c;

    c.num = (a.num * b.den) + (b.num * a.den);
    c.den = a.den * b.den;

    return c;

}

struct fraccion resta(struct fraccion a, struct fraccion b){

    struct fraccion c;

    c.num = (a.num * b.den) - (b.num * a.den);
    c.den = a.den * b.den;

    return c;

}

struct fraccion multiplicacion(struct fraccion a, struct fraccion b){

    struct fraccion c;

    c.num = a.num * b.num;
    c.den = a.den * b.den;

    return c;

}

struct fraccion division(struct fraccion a, struct fraccion b){

    struct fraccion c;

    c.num = a.num * b.den;
    c.den = a.den * b.num;

    return c;

}






