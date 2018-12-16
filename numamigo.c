/*Programa:"numamigo.c".
Autor:Francisco Blázquez Matías.
Curso:Primero de GII del grupo B3.
Fecha: 22/12/2014.
Descripción: Compara dos numeros y dicen si son amigos (= si la suma de los divisores distintos de si mismo de cada uno coincide con el otro numero).
Copyright:
*/

#include<stdio.h>
#include<stdlib.h>

int divisores(int);
int amigos (int, int);

int main (void){

    int n1, n2;

    do{

        printf("Escribe el primer numero:  ");
        scanf("%d", &n1);

        printf("\nEscribe el segundo numero:  ");
        scanf("%d", &n2);

    }while((n1 < 0)&&(n2 < 0));

    if(amigos(n1, n2)){

        printf("\nLos numeros %d y %d son amigos\n\n", n1, n2);

    }
    else{

        printf("\nLos numeros %d y %d no son amigos\n\n", n1, n2);

    }


system("pause");
return 0;
}



int divisores(int n){

    int divisor;
    int suma = 0;

    for(divisor=1; divisor<n; divisor++){

        if(n % divisor == 0){

            suma += divisor;

        }
    }

return(suma);

}



int amigos(int x, int y){

    int nx, ny;

    nx = divisores(x);
    ny = divisores(y);


return((nx == y)&&(ny == x));
}
