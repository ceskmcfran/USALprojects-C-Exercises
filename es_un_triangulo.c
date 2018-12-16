#include<stdio.h>
#include<stdlib.h>

int main (void){

    float a, b, c;
    int triang, escal, equil, isos;

    printf("Introduzca la longitud de los lados:\n");
    scanf("%f %f %f", &a, &b, &c);

    printf("\Las cantidades introducidas son\n  a: %f     b: %f      c: %f\n\n", a, b, c);

    printf("Es triangulo?\n");
    /*¿Es triangulo? Para comprobarlo tendremos que saber si uno de los lados es mayor que los otros dos juntos*/
    triang = (a + b > c) || (a + c > b) || (b + c > a);
    printf("%d\n", triang);
    printf("Si es triangulo se imprimira por pantalla un ""1"", si no se imprimira un ""0""\n\n");

   /*Es escaleno? Para comprobarlo tendremos que saber si los tres lados son distintos entre si */
    printf("Es escaleno?\n");
    escal = (a != b) && (a != c) && (b != c);
    printf("%d\n", escal);
    printf("Si es escaleno se imprimira por pantalla un ""1"", si no se imprimira un ""0""\n\n");

    /*Es equilatero? Para comprobarlo tendremos que saber si todos los lados son iguales */
    printf("Es equilatero?\n");
    equil = (a == b) && (b == c);
    printf("%d\n", equil);
    printf("Si es equilatero se imprimira por pantalla un ""1"", si no se imprimira un ""0""\n\n");

    /*Es isosceles? Para comprobarlo tendremos que saber si dos de sus lados son iguales y el otro no*/
    printf("Es isosceles?\n");
    isos = (((a == b) && (a != c)) || ((a == c) && (a != b)) || ((b == c) && (b != a)));
    printf("%d\n", isos);
    printf("Si es isosceles se imprimira por pantalla un ""1"", si no se imprimira un ""0""\n\n");

    system("pause");
    return 0;
}
