#include<stdio.h>
#include<stdlib.h>
#define PI 3.14159

int main (void){

    float grados, rad;

    printf("Escribe los grados a convertir:\n");
    scanf("%f", &grados);

    rad = (PI * grados) / 180;

    printf("\nEl resultado en radianes es: %f\n", rad);
    system("pause");
    return 0;
}
