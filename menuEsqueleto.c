/*Programa:"navia_esqueleto_menu.c".
Autor:Francisco Blázquez Matías.
Curso:Primero de GII del grupo B3.
Fecha: 18/1/2015.
Descripción: Esqueleto de menús
Copyright:
*/


#include<stdio.h>
#include<stdlib.h>



int main(void){

    int menu;

    do{
        system("cls");
        printf("----------------\n");
        printf("MENU DE OPCIONES\n");
        printf("----------------\n");
        printf("1. opcion 1\n");
        printf("2. opcion 2\n");
        printf("3. opcion 3\n");
        printf("4. opcion 4\n\n");
        printf("5. Salir\n\n");

        printf("Elija una opcion (INTRODUCIR SOLO NUMEROS ENTEROS):  ");
        scanf("%d", &menu);

        switch(menu){

            case 1 :

                do{
                    system("cls");
                    printf("1. submenu 1\n");
                    printf("2. submenu 2\n\n");
                    printf("3. Salir al menu principal\n\n");
                    printf("Elija una opcion:  ");
                    scanf("%d", &menu);

                    switch(menu){

                        case 1 :

                            do{
                                system("cls");
                                printf("1. subsubmenu 1\n");
                                printf("2. subsubmenu 2\n");
                                printf("3. subsubmenu 3\n\n");
                                printf("4.Volver al menu anterior\n\n");
                                printf("Elija una opcion:  ");
                                scanf("%d", &menu);

                                switch(menu){
                                    case 1 :

                                        printf("Caso 1");
                                        break;

                                    case 2 :
                                        printf("Caso 2");
                                        break;

                                    case 3 :
                                        printf("Caso 3");
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
                                printf("1. subsubmenu 1\n");
                                printf("2. subsubmenu 2\n");
                                printf("3. subsubmenu 3\n\n");
                                printf("4.Volver al menu anterior\n\n");
                                printf("Elija una opcion:  ");
                                scanf("%d", &menu);

                                switch(menu){
                                    case 1 :

                                        printf("Caso 1");
                                        break;

                                    case 2 :
                                        printf("Caso 2");
                                        break;

                                    case 3 :
                                        printf("Caso 3");
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

            case 2:

                do{
                    system("cls");
                    printf("1. submenu 1\n");
                    printf("2. submenu 2\n\n");
                    printf("3. Salir al menu principal\n\n");
                    printf("Elija una opcion:  ");
                    scanf("%d", &menu);

                    switch(menu){

                        case 1 :

                            do{
                                system("cls");
                                printf("1. subsubmenu 1\n");
                                printf("2. subsubmenu 2\n");
                                printf("3. subsubmenu 3\n\n");
                                printf("4.Volver al menu anterior\n\n");
                                printf("Elija una opcion:  ");
                                scanf("%d", &menu);

                                switch(menu){
                                    case 1 :

                                        printf("Caso 1");
                                        break;

                                    case 2 :
                                        printf("Caso 2");
                                        break;

                                    case 3 :
                                        printf("Caso 3");
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
                                printf("1. subsubmenu 1\n");
                                printf("2. subsubmenu 2\n");
                                printf("3. subsubmenu 3\n\n");
                                printf("4.Volver al menu anterior\n\n");
                                printf("Elija una opcion:  ");
                                scanf("%d", &menu);

                                switch(menu){
                                    case 1 :

                                        printf("Caso 1");
                                        break;

                                    case 2 :
                                        printf("Caso 2");
                                        break;

                                    case 3 :
                                        printf("Caso 3");
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

                 do{
                    system("cls");
                    printf("1. submenu 1\n");
                    printf("2. submenu 2\n\n");
                    printf("3. Salir al menu principal\n\n");
                    printf("Elija una opcion:  ");
                    scanf("%d", &menu);

                    switch(menu){

                        case 1 :

                            do{
                                system("cls");
                                printf("1. subsubmenu 1\n");
                                printf("2. subsubmenu 2\n");
                                printf("3. subsubmenu 3\n\n");
                                printf("4.Volver al menu anterior\n\n");
                                printf("Elija una opcion:  ");
                                scanf("%d", &menu);

                                switch(menu){
                                    case 1 :

                                        printf("Caso 1");
                                        break;

                                    case 2 :
                                        printf("Caso 2");
                                        break;

                                    case 3 :
                                        printf("Caso 3");
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
                                printf("1. subsubmenu 1\n");
                                printf("2. subsubmenu 2\n");
                                printf("3. subsubmenu 3\n\n");
                                printf("4.Volver al menu anterior\n\n");
                                printf("Elija una opcion:  ");
                                scanf("%d", &menu);

                                switch(menu){
                                    case 1 :

                                        printf("Caso 1");
                                        break;

                                    case 2 :
                                        printf("Caso 2");
                                        break;

                                    case 3 :
                                        printf("Caso 3");
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

            case 4:

                do{
                    system("cls");
                    printf("1. submenu 1\n");
                    printf("2. submenu 2\n\n");
                    printf("3. Salir al menu principal\n\n");
                    printf("Elija una opcion:  ");
                    scanf("%d", &menu);

                    switch(menu){

                        case 1 :

                            do{
                                system("cls");
                                printf("1. subsubmenu 1\n");
                                printf("2. subsubmenu 2\n");
                                printf("3. subsubmenu 3\n\n");
                                printf("4.Volver al menu anterior\n\n");
                                printf("Elija una opcion:  ");
                                scanf("%d", &menu);

                                switch(menu){
                                    case 1 :

                                        printf("Caso 1");
                                        break;

                                    case 2 :
                                        printf("Caso 2");
                                        break;

                                    case 3 :
                                        printf("Caso 3");
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
                                printf("1. subsubmenu 1\n");
                                printf("2. subsubmenu 2\n");
                                printf("3. subsubmenu 3\n\n");
                                printf("4.Volver al menu anterior\n\n");
                                printf("Elija una opcion:  ");
                                scanf("%d", &menu);

                                switch(menu){
                                    case 1 :

                                        printf("Caso 1");
                                        break;

                                    case 2 :
                                        printf("Caso 2");
                                        break;

                                    case 3 :
                                        printf("Caso 3");
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

            case 5:



                break;

            default :

                system("cls");
                printf("El numero introducido es erroneo, intentelo otra vez\n");
                system("pause");
                break;
        }

    }while (menu != 5);






system("pause");
return 0;
}

