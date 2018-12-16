/*Programa:"Matrices.c".
Autor:Francisco Blázquez Matías.
Curso:Primero de GII del grupo B3.
Fecha: 19/11/2014.
Descripción:
Copyright:
*/

#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#define FIL  25
#define COL  25
#define RANSUP 1000


int main (void){

    int matriz[FIL][COL] = {}; //matriz A
    int matriz2[FIL][COL] = {}; // matriz B
    int matrizp[FIL][COL] = {}; // matriz producto
    int matrizs[FIL][COL] = {}; // matriz suma
    int f = 0, c = 0; //f, c --> contadores de las matrices
    int j;
    int filA = 0, colA = 0, filB = 0, colB = 0;
    int filP, colP;
    int max1 = 0, min1 = 0, aleat = 0, max2 = 0, min2 = 0;
    char opcion;


    do{

        f=0;
        c=0;

        system("cls");

        printf("=========================================================\n");
        printf("                MAXIMOS Y MINIMOS DE MATRICES\n");
        printf("=========================================================\n\n");
        printf(" a) Introducir dimensiones de las matrices\n");
        printf(" b) Cargar con valores introducidos\n");
        printf(" c) Cargar con valores aleatorios\n");
        printf(" d) Buscar maximos y minimos y mostrar sus posiciones\n");
        printf(" e) Multiplicar matrices\n");
        printf(" f) Sumar matrices\n");
        printf(" g) Mostrar matrices\n\n");
        printf(" s) Salir\n\n");
        printf("Introduzca la opcion deseada:  ");
        scanf("%c", &opcion);

        srand(time(NULL));

        switch(opcion){

            case 'a': //INTRODUCIR LOS LIMITES DE LA MATRIZ

                system("cls");


                do{
                    printf("Numero filas matriz A (max. %d)?: ", FIL);
                    scanf("%d", &filA);
                }while ((filA <=0) || (filA > FIL));

                do{
                    printf("Numero columnas matriz A (max. %d)?: ", COL);
                    scanf("%d", &colA);
                }while ((colA <=0) || (colA > COL));

                do{
                    printf("Numero filas matriz B (max. %d)?: ", FIL);
                    scanf("%d", &filB);
                }while ((filB <=0) || (filB > FIL));

                do{
                    printf("Numero columnas matriz B (max. %d)?: ", COL);
                    scanf("%d", &colB);
                }while ((colB <=0) || (colB > COL));

                break;

            case 'b': //LLENAR CON NUMEROS ELEGIDOS POR EL USUARIO

                system("cls");

                printf("\nIntroduzca la matriz A:\n");
                for (f = 0; f < filA; f++)
                    for (c = 0; c < colA; c++){

                        printf("Elemento (%d, %d)=> ", f+1, c+1);
                        scanf("%d", &matriz[f][c]);
                    }


                printf("\n\nIntroduzca la matriz B:\n");
                for (f = 0; f < filB; f++)
                    for (c = 0; c < colB; c++){

                        printf("Elemento (%d, %d)=> ", f+1, c+1);
                        scanf("%d", &matriz2[f][c]);
                    }

                system("pause");

                break;

            case 'c': //LLENAR LA MATRIZ CON NUMEROS ALEATORIOS

                system("cls");

                for(f = 0; f < filA; f++){
                    for(c = 0; c < colA; c++){

                        aleat = rand() % (RANSUP + 1);
                        matriz[f][c] = aleat;
                        printf("Matriz A, elemento (%d-%d) = %d\n", f+1, c+1, matriz[f][c]);

                    }
                }

                printf("\n\n");

                for(f = 0; f < filB; f++){
                    for(c = 0; c < colB; c++){

                        aleat = rand() % (RANSUP + 1);
                        matriz2[f][c] = aleat;
                        printf("Matriz B, elemento (%d-%d) = %d\n", f+1, c+1, matriz2[f][c]);

                    }
                }
                system("pause");

                break;

            case 'd':    /*CALCULO DEL MINIMO Y EL MAXIMO DE LA MATRIZ A*/

                system("cls");

                max1 = matriz[0][0];
                min1 = matriz[0][0];

                for(f = 0;f < filA; f++){
                    for(c = 0;c < colA; c++){

                        if(matriz[f][c] > max1){

                            max1 = matriz[f][c];

                        }
                        else if(matriz[f][c] < min1){

                            min1 =  matriz[f][c];

                        }
                    }
                }

                printf("\nMaximo de la matriz A:  %d\n", max1);
                printf("Minimo de la matriz A:  %d\n", min1);

                /*CALCULO DE LAS COORDENADAS DE LA MATRIZ A*/

                printf("\nCoordenadas del elemento maximo de la matriz A:");

                for(f = 0;f < filA; f++){
                    for(c = 0;c < colA; c++){

                        if(matriz[f][c] == max1){

                            printf("\n(%d-%d)\n\n", f+1, c+1);

                        }
                    }
                }

                printf("Coordenadas del elemento minimo de la matriz A:");

                for(f = 0;f < filA; f++){
                    for(c = 0;c < colA; c++){

                        if(matriz[f][c] == min1){

                            printf("\n(%d-%d)\n\n", f+1, c+1);

                        }
                    }
                }
                /*CALCULO DE MAXIMO Y MINIMO DE LA MATRIZ B*/

                max2 = matriz2[0][0];
                min2 = matriz2[0][0];

                for(f = 0;f < filB; f++){
                    for(c = 0;c < colB; c++){

                        if(matriz2[f][c] > max2){

                            max2 = matriz2[f][c];

                        }
                        else if(matriz2[f][c] < min2){

                            min2 =  matriz2[f][c];

                        }
                    }
                }

                printf("\nMaximo de la matriz B:  %d\n", max2);
                printf("Minimo de la matriz B:  %d\n", min2);

                /*CALCULO DE LAS COORDENADAS DE LA MATRIZ B*/

                printf("\nCoordenadas del elemento maximo de la matriz B:");

                for(f = 0;f < filB; f++){
                    for(c = 0;c < colB; c++){

                        if(matriz2[f][c] == max2){

                            printf("\n(%d-%d)\n", f+1, c+1);

                        }
                    }
                }

                printf("\nCoordenadas del elemento minimo de la matriz B:");

                for(f = 0;f < filB; f++){
                    for(c = 0;c < colB; c++){

                        if(matriz2[f][c] == min2){

                            printf("\n(%d-%d)\n\n", f+1, c+1);

                        }
                    }
                }
                system("pause");
                break;

            case 'e':

                system("cls");

                if(filB != colA){

                    printf("Para que las matrices se puedan multiplicar las columnas de la matriz A tienen que ser igual a las filas de la matriz B.\n\n");
                    system("pause");
                    break;
                }
                else{

                    filP = filA;
                    colP = colB;
                    for (f = 0; f < filA; f++){
                        for (c = 0; c < colB; c++){

                            matrizp[f][c] = 0;
                            for (j = 0; j < colA; j++){

                                matrizp[f][c] = matrizp[f][c] + (matriz[f][j] * matriz2[j][c]);

                            }
                        }
                    }
                    printf("Las matrices se han multiplicado\n\n");
                    system("pause");
                    break;

                }

            case 'f':

                system("cls");

                if((filA == filB)&&(colA == colB)){

                    for (f = 0; f < filA; f++){
                        for (c = 0; c < colA; c++){

                                matrizs[f][c] = matriz[f][c] + matriz2[f][c];

                        }
                    }

                    printf("Las matrices se han sumado\n\n");
                    system("pause");
                    break;

                }
                else{

                    printf("Para que se puedan sumar matrices las filas y las columnas de la matriz A tienen que ser iguales a las de la B.\n\n");
                    system("pause");
                    break;
                }

            case 'g':

                    system("cls");

                    printf("La matriz A utilizada:\n\n");

                    for(c = 0;c < colA; c++){

                        printf("| ");

                        for(f = 0; f < filA; f++){

                            printf(" %8.2d ", matriz[f][c]);

                        }

                        printf(" |\n");

                    }

                    printf("\n");


                    printf("La matriz B utilizada:\n\n");

                    for(c = 0;c < colB; c++){

                        printf("| ");

                        for(f = 0; f < filB; f++){

                            printf(" %8.2d ", matriz2[f][c]);

                        }

                        printf(" |\n");

                    }

                    printf("\n");

                    if(filB == colA){

                        printf("La matriz producto es:\n\n");

                        for(c = 0;c < colP; c++){

                            printf("| ");

                            for(f = 0; f < filP; f++){

                                printf(" %8.2d ", matrizp[f][c]);

                            }

                            printf(" |\n");

                        }

                        printf("\n");
                    }
                    else{

                        printf("\nNo se puede mostrar la matriz multiplicacion.\n");

                    }

                    if((filA == filB)&&(colA == colB)){

                        printf("La matriz suma es:\n\n");

                        for(c = 0;c < colA; c++){

                            printf("| ");

                            for(f = 0; f < filA; f++){

                                printf(" %8.2d ", matrizs[f][c]);

                            }

                            printf(" |\n");

                        }

                        printf("\n");

                    }
                    else{

                        printf("\nNo se puede mostrar la matriz suma.\n");

                    }

                    system("pause");
                    break;


        }




    }while(opcion != 's');

system("pause");
return 0;
}
