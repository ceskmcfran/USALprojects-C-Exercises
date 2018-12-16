#include<stdio.h>
#include<stdlib.h>

int main (void){

    int x, y, temp;

    printf("Escriba los dos numeros enteros que desea intercambiar:\n");
    scanf("%d", &x);
    scanf("%d", &y);

    printf("\n\nLos numeros enteros que has escrito son:\n      x-->%d \n      y-->%d \n", x, y);

    temp = x;
    x = y;
    y = temp;

    printf("\nAhora sus variables han quedado de la siguiente manera:\n      x-->%d \n      y-->%d \n\n", x, y);

    system("pause");
    return 0;

}
