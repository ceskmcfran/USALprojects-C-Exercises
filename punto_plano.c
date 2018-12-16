/*Programa:"punto_plano.c".
Autor:Francisco Blázquez Matías.
Curso:Primero de GII del grupo B3.
Fecha: 17/2/2015.
Descripción:
Copyright:
*/

#include<math.h>
#include<stdio.h>
#include<stdlib.h>

struct punto{

    float x;
    float y;

};

void presentacion(void);
struct punto leer_punto(struct punto *);
void mostrar_punto(struct punto);
float distancia(struct punto, struct punto);
struct punto punto_medio(struct punto, struct punto);


int main(void){

    char opcion;
    struct punto p1, p2;
    float dist;

    presentacion();

    do{

        system("cls");
        printf("==============================================================\n");
        printf("\t\t\tMENU\t\t\t\n");
        printf("==============================================================\n");
        printf("a) Leer puntos\n");
        printf("b) Mostrar puntos\n");
        printf("c) Distancia entre puntos\n");
        printf("d) Punto medio entre puntos\n\n");
        printf("s) Salir\n\n");

        printf("Opcion?:  ");
        scanf("%c", &opcion);

        switch(opcion){

            case 'a':

                system("cls");
                leer_punto(&p1);
                leer_punto(&p2);
                system("pause");
                break;

            case 'b':

                system("cls");
                printf("Punto 1:\n");
                mostrar_punto(p1);
                printf("Punto 2:\n");
                mostrar_punto(p2);
                system("pause");
                break;

            case 'c':

                system("cls");
                dist = distancia(p1, p2);
                printf("La distancia entre los dos puntos es:  %f\n\n", dist);
                system("pause");
                break;

            case 'd':

                system("cls");
                mostrar_punto(punto_medio(p1, p2));
                system("pause");
                break;
        }

    }while(opcion != 's');





system("pause");
return 0;
}



void presentacion(void){

    printf("Programa que presenta por pantalla operaciones con puntos de un plano.\n\n\n");
    system("pause");

}

//Se declara una estructura de tipo "punto" con un parametro puntero del tipo "punto"

struct punto leer_punto(struct punto *a){

    printf("Coordenada horizontal (x): ");

    //Utilizamos el operador "->" para apuntar a la direccion de memoria de la subvariable de tipo float contenida en el tipo "punto"

    scanf("%f", &a->x);
    printf("Coordenada vertical (y): ");
    scanf("%f", &a->y);
    printf("\n\n");

    //Como necesitamos devolver los valores utilizamos "*a" para devolver los valores de la estructura.

    return *a;

}

void mostrar_punto(struct punto a){

    printf("Punto en:\n");
    printf("\tx: %f\n", a.x);
    printf("\ty: %f\n", a.y);

}

float distancia(struct punto a, struct punto b){

    float dist;

    dist = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));

    return dist;

}

struct punto punto_medio(struct punto a, struct punto b){

    struct punto c;

    c.x = (a.x + b.x) / 2;
    c.y = (a.y + b.y) / 2;

    return c;

}


