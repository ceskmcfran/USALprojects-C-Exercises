/*Programa:"compra_almacenes_discos.c".
Autor:Francisco Blázquez Matías.
Curso:Primero de GII del grupo B3.
Fecha: 18/10/2014.
Descripción:Compara y realiza el cálculo de precios de dos almacenes
Copyright:
*/


#include<stdio.h>
#include<stdlib.h>


int main (void){

    float preA1WD = 23.1, preA1ST = 45, preA1SS = 12.35, preA2WD = 25.95, preA2ST = 41.90, preA2SS = 15.45;
    /*Variables de los precios de los discos [(precio)+(almacen(numero))+(iniciales del producto)]*/
    int menu, comprar; /*Variable del menu*/
    int compra1 = 0, compra2 = 0, compra3 = 0, compra4 = 0, compra5 = 0, compra6 = 0; /*numero de discos que pide el comprador*/
    float result1 = 0, result2 = 0, result3 = 0, result4 = 0, result5 = 0, result6 = 0;
    float totalmic, totalbyt;

    printf("COMPARATIVA DE PRECIOS DE DOS ALMACENES\n");
    printf("=======================================\n\n");
    printf("Almacenes de venta de discos: MICROSAN y BYTE DE 9.\n");
    printf("Modelos de discos ofrecidos: WD20EARS, ST2000 y SSD204.\n\n");

    printf("Se solicitaran los precios unitarios de cada modelo de HD en cada almacen.\n");
    printf("Se solicitaran el numero de discos a realizar en el pedido.\n");
    printf("El programa realizara una tabla comparativa de precios en cada almacen.\n\n");
    system("pause");

    do{
        system("cls");
        printf("----------------\n");
        printf("MENU DE OPCIONES\n");
        printf("----------------\n");
        printf("1. Ver precios\n");
        printf("2. Comprar:\n");
        printf("3. Ver compra:\n");
        printf("4. Salir\n\n");

        printf("Elija una opcion (INTRODUCIR SOLO NUMEROS ENTEROS):  ");
        scanf("%d", &menu);

        switch (menu){

            case 1 :
                system("cls");
                printf("=========================\n");
                printf("Para el almacen MICROSAN:\n");
                printf("=========================\n");
                printf("WD20EARS.........%.1f $\n", preA1WD);
                printf("ST2000...........%.f $\n", preA1ST);
                printf("SSD204...........%.2f $\n\n", preA1SS);
                printf("=========================\n");
                printf("Para el almacen BYTE DE 9:\n");
                printf("=========================\n");
                printf("WD20EARS.........%.2f $\n", preA2WD);
                printf("ST2000...........%.2f $\n", preA2ST);
                printf("SSD204...........%.2f $\n\n", preA2SS);
                system("pause");
                break;

            case 2:

                do{
                    system("cls");
                    printf("\t\tCOMPRA DE DISCOS\n");
                    printf("====================================\n\n");
                    printf("Elija el almacen en el que quiere comprar:\n");
                    printf("1. MICROSAN\n");
                    printf("2. BYTE DE 9\n");
                    printf("3. Salir al menu principal\n\n");
                    printf("Elija una opcion:  ");
                    scanf("%d", &menu);

                    switch (menu){

                        case 1 :

                            do{
                                system("cls");
                                printf("\t\tMICROSAN\n");
                                printf("====================================\n\n");

                                printf("Elija el disco que quiere comprar:\n");
                                printf("1.WD20EARS\n");
                                printf("2.ST2000\n");
                                printf("3.SSD204\n");
                                printf("4.Volver al menu de almacenes\n\n");
                                printf("Elija una opcion:  ");
                                scanf("%d", &menu);

                                switch(menu){
                                    case 1 :

                                        printf("Cuantos discos quiere comprar?: ");
                                        scanf("%d", &compra1);
                                        break;

                                    case 2 :
                                        printf("Cuantos discos quiere comprar?: ");
                                        scanf("%d", &compra2);
                                        break;

                                    case 3 :
                                        printf("Cuantos discos quiere comprar?: ");
                                        scanf("%d", &compra3);
                                        break;

                                    case 4 :
                                        break;

                                    default :

                                        system("cls");
                                        printf("El numero introducido es erroneo, intentelo otra vez\n");
                                        system("pause");
                                        break;
                                }

                            }while (menu != 4);
                            break;

                        case 2 :

                            do{
                                system("cls");
                                printf("\t\tBYTE DE 9\n");
                                printf("====================================\n\n");

                                printf("Elija el disco que quiere comprar:\n");
                                printf("1.WD20EARS\n");
                                printf("2.ST2000\n");
                                printf("3.SSD204\n");
                                printf("4.Volver al menu de almacenes\n\n");
                                printf("Elija una opcion:  ");
                                scanf("%d", &menu);

                                switch(menu){
                                    case 1 :

                                        printf("Cuantos discos quiere comprar?: ");
                                        scanf("%d", &compra4);
                                        break;

                                    case 2 :
                                        printf("Cuantos discos quiere comprar?: ");
                                        scanf("%d", &compra5);
                                        break;

                                    case 3 :
                                        printf("Cuantos discos quiere comprar?: ");
                                        scanf("%d", &compra6);
                                        break;

                                    case 4 :
                                        break;

                                    default :

                                        system("cls");
                                        printf("El numero introducido es erroneo, intentelo otra vez\n");
                                        system("pause");
                                        break;
                                }

                            }while (menu != 4);
                            break;

                        case 3 :
                            break;

                        default :
                            system("cls");
                            printf("El numero introducido es erroneo, intentelo otra vez\n");
                            system("pause");
                            break;
                    }


                } while (menu != 3);
                break;

            case 3:

                result1 = compra1 * preA1WD;
                result2 = compra2 * preA1ST;
                result3 = compra3 * preA1SS;
                result4 = compra4 * preA2WD;
                result5 = compra5 * preA2ST;
                result6 = compra6 * preA2SS;
                totalmic = result1 + result2 + result3;
                totalbyt = result4 + result5 + result6;

                printf("\nCARRITO DE LA COMPRA\n");
                printf("================================================================================");
                printf("                                    MICROSAN           BYTE DE 9\n");
                printf("                            -----------------   ----------------\n");
                printf("Total discos tipo WD20EARS...%d * %.2f = %.2f   %d * %.2f = %.2f\n", compra1, preA1WD, result1, compra4, preA2WD, result4);
                printf("Total discos tipo ST2000.....%d * %.2f = %.2f   %d * %.2f = %.2f\n", compra2, preA1ST, result2, compra5, preA2ST, result5);
                printf("Total discos tipo SSD204.....%d * %.2f = %.2f   %d * %.2f = %.2f\n", compra3, preA1SS, result3, compra6, preA2SS, result6);
                printf("                            -----------------   ----------------\n");
                printf("Total compra..............             %.2f                %.2f\n", totalmic, totalbyt);
                system("pause");
                break;

            case 4:
                break;

            default :

                system("cls");
                printf("El numero introducido es erroneo, intentelo otra vez\n");
                system("pause");
                break;
        }

    }while (menu != 4);

system("pause");
return 0;
}
