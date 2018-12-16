/*Programa: "calculo_vectorial"
Autor:Francisco Blázquez Matías
Curso:Primero de GII del grupo B3
Fecha: 18/10/2014
Descripción:Cálculo de módulo, media y vector unitario de un vector tridimensional.
Copyright:
*/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main (void){

    float x,y,z,m,media,u1,u2,u3;


    printf("Escriba las componentes de su vector ""V""\n");
    scanf("%f %f %f", &x, &y, &z);

    printf("Su vector sera el siguiente:\n");
    printf("    V = (%f , %f , %f\n)", x, y, z);

    m = sqrt((x*x)+(y*y)+(z*z));

    printf("El módulo de su vector sera:                    %f\n", m);

    media = (x + y + z)/ 3;

    printf("La media de su vector sera:                     %f\n", media);

    u1 = x/m;
    u2 = y/m;
    u3 = z/m;

    printf("El vector unitario en su misma direccion sera:  (%f, %f, %f)\n", u1, u2, u3);

system("pause");
return 0;
}
