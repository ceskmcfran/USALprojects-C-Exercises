/*Programa:"adivinar_numeros.c".
Autor:Francisco Blázquez Matías.
Curso:Primero de GII del grupo B3.
Fecha: 7/11/2014.
Descripción: Consiste en un pequeño juego en el que hay que adivinar un número generado aleatoriamente por el ordenador.
Copyright:
*/

#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define LIMS 10000


int main (void){

    char opcion;
    int num, aleat /*Numero aleatorio*/, dist = 0 /*Distancia del numero introducido al aleatorio*/, intent = 1/*Intentos*/;

    do{

        printf("===============================================\n");
        printf("            ADIVINA EL NUMERO\n");
        printf("===============================================\n\n");
        printf("    J) Jugar\n");
        printf("    I) Instrucciones\n");
        printf("    C) Creditos\n");
        printf("    S) Salir\n\n");
        printf("Introduzca la opcion deseada:  ");
        scanf("%c", &opcion);
        toupper(opcion);
        system("cls");

        switch(opcion){

            case 'j':
            case 'J':

                srand(time(NULL));
                aleat = rand() % (LIMS + 1);

                do{

                    printf("INTENTO NUMERO %d\n", intent);
                    printf("\nAdivina el numero:  ");
                    scanf("%d", &num);
                    intent++;

                    dist = abs(aleat - num);

                    if(num >= 0){

                        if(num > aleat){

                            if(dist >= 100){

                                printf("\nMuy frio!\n");

                            }
                            else if((dist < 100)&&(dist >= 10)){

                                printf("\nFrio!\n");

                            }
                                else if((dist < 10)&&(dist >= 5)){

                                    printf("\nCaliente!!\n");

                                }
                                    else if((dist < 5)&&(dist > 0)){

                                        printf("\nQUE TE QUEMAS!!!\n");

                                    }
                                        else{

                                        printf("\nMuy bien! has acertado el numero!\n\n");
                                        printf("Has adivinado el numero en %d intentos", intent);

                                    }

                            printf("\nMi numero es menor\n\n");

                        }

                            else if(num < aleat){

                                if(dist >= 100){

                                    printf("\nMuy frio!\n");

                                }
                                else if((dist < 100)&&(dist >= 10)){

                                    printf("\nFrio!\n");

                                }
                                    else if((dist < 10)&&(dist >= 5)){

                                        printf("\nCaliente!!\n");

                                    }
                                        else if((dist < 5)&&(dist > 0)){

                                            printf("\nQUE TE QUEMAS!!!\n");

                                        }
                                            else{

                                            printf("\nMuy bien! has acertado el numero!\n\n");
                                            printf("Has adivinado el numero en %d intentos", intent);

                                        }

                                printf("\nMi numero es mayor\n\n");

                            }

                                else{

                                    printf("\nLos numeros son iguales!!\n");
                                    printf("Tu numero:  %d\n", num);
                                    printf("Mi numero:  %d\n", aleat);

                                }

                        system("pause");
                        system("cls");
                    }

                    else{

                        intent = intent - 2; //Al ser intent = 1 e ir aumentando para dar el intento anterior al que abandona se resta 2.
                        printf("Has abandonado! Has utilizado %d intentos, el numero era %d\n\n", intent, aleat);
                        system("pause");
                        system("cls");

                    }

                }while((aleat != num)&&(num > 0));

                intent = 1;

                break;

            case 'i':
            case 'I':

                system("cls");
                printf("--------------------------------------------------------------------------------\n");
                printf("                                INSTRUCCIONES\n");
                printf("--------------------------------------------------------------------------------\n\n");
                printf("Adivina el numero que genera aleatoriamente el ordenador!(entre 0 y 10000)\n\n");
                printf("El programa te dira la lejania o cercania del numero aleatorio con un codigo:\n");
                printf("""Muy frio"" si la distancia de tu numero al aleatorio es superior a 100\n");
                printf("""Frio"" si la distancia de tu numero al aleatorio esta entre 10 y 100\n");
                printf("""Caliente"" si la distancia de tu numero al aleatorio esta entre 5 y 10\n");
                printf("""QUE TE QUEMAS"" si la distancia de tu numero al aleatorio es inferior a 5\n\n");
                printf("En caso de que quieras abandonar deberas poner un numero negativo\n");
                printf("Siempre se contara el numero de intentos, tanto si abandonas como si lo aciertas\n");
                printf("\nSUERTE!!\n");
                system("pause");
                break;

            case 'c':
            case 'C':

                system("cls");
                printf("Autor: Francisco Blazquez Matias\n");
                printf("Fecha: 7/11/2014\n\n");
                system("pause");
                break;

        }
    }while((opcion != 'S')&&(opcion != 's'));


system("pause");
return 0;
}
