/* Fuente: PSILLA.C
   Programa: PUNTOS DE SILLA
   Descripción: Localiza puntos de silla en una matriz.
   Se dice que una matriz tiene un punto de silla si algún elemento de
   la matriz es el menor valor de su fila, y a la vez el mayor de su columna.

   La función puntosdesilla() localiza un punto de silla por fila. Es decir, en caso de que una
   fila tuviera varios elementos repetidos y todos ellos fueran punto silla, sólo indicará el
   primero de ellos, por ello esta función trabaja óptimamente para el caso de matrices sin
   elementos repetidos.

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define FIL  25
#define COL  25

/* ---------------------------------------------------------- */
/* Prototipos                                                 */
/* ---------------------------------------------------------- */
void presentacion     (void);
void modulo_principal (void);
void leer_matriz      (long (*)[COL], int, int);
void escribir_matriz  (long (*)[COL], int, int);
void puntosdesilla    (long (*)[COL], int, int, int *);

/* ---------------------------------------------------------- */
   int main (void) {
/* ---------------------------------------------------------- */
     char respuesta;

     system ("cls");
     presentacion();
     do
       { printf("\n");
	 modulo_principal();
	 printf("\n");
	 do
	   { printf("¿Otra ejecución (S/N)?: ");
	     fflush(stdin); /* Limpia el buffer de teclado */
	     respuesta = toupper(getchar());
	   }
	 while (respuesta != 'S' && respuesta != 'N');

       }
     while (respuesta != 'N');

     return 0;

} /* Fin del main */


/* ---------------------------------------------------------- */
   void presentacion(void) {
/* ---------------------------------------------------------- */
     puts ("Programa para calcular los puntos de silla de una matriz");
     puts ("--------------------------------------------------------");
     puts ("Determina un único punto de silla por fila.");
     puts ("La matriz no debe tener elementos repetidos.");
     puts ("");
}


/* ---------------------------------------------------------- */
   void modulo_principal (void) {
/* ---------------------------------------------------------- */
      long matrizA[FIL][COL]; /* matriz                              */
      int filA, colA;         /* filas, columnas efectivas matriz    */
      int lista_ps[FIL];      /* vector con los puntos de silla      */

      int f, c;               /* índices para recorrido matriz       */
      int total_puntos;       /* Número total de puntos de silla     */

   /* Se lee del número de filas y columnas de la primera matriz --- */
     do
      { printf("¿Número filas matriz (máx. %d)?: ", FIL);
        scanf("%d", &filA);
      } while ((filA <=0) || (filA > FIL));

     do
      { printf("¿Número columnas matriz (máx. %d)?: ", COL);
        scanf("%d", &colA);
      } while ((colA <=0) || (colA > COL));


   printf("Introduzca la matriz:\n");
   leer_matriz(matrizA, filA, colA);

   puntosdesilla (matrizA, filA, colA, lista_ps);

   printf("\nMatriz:\n");
   escribir_matriz(matrizA, filA, colA);

   printf("\nPuntos de silla:\n");
   total_puntos = 0;
   for (f = 0; f < filA; f++)
       if (lista_ps[f] != -1)
          { total_puntos++;
            printf("Punto de silla en [%02d][%02d] con valor %6ld \n",
                    f, lista_ps[f], matrizA[f][lista_ps[f]]);
          }

   if (total_puntos)
        printf("Número total de puntos de silla: %d\n", total_puntos);
   else printf("La matriz no tiene puntos de silla\n");
}


/* ---------------------------------------------------------- */
   void leer_matriz (long (*ma)[COL], int filas, int columnas) {
/* ---------------------------------------------------------- */
/* ------- Se solicita la matriz por filas ------------ */
     int f,c;
     for (f = 0; f < filas; f++)
       for (c = 0; c < columnas; c++)
   	 { printf("Elemento (%d, %d)=> ", f+1, c+1);
   	   scanf("%ld", &ma[f][c]);
          }
}


/* ---------------------------------------------------------- */
   void escribir_matriz (long (*ma)[COL], int filas, int columnas) {
/* ---------------------------------------------------------- */
/* ------- Se escribe la matriz por filas ------------ */
     int f,c;
     for (f = 0; f < filas; f++)
     {
       for (c = 0; c < columnas; c++)
   	  printf("%5ld", ma[f][c]);
       printf("\n");
     }
}


/* ---------------------------------------------------------- */
   void puntosdesilla (long (*ma)[COL], int filas, int columnas, int *ps) {
/* ---------------------------------------------------------- */
/* --- La longitud de ps debe ser el número de filas de ma ---- */
     int f, f2, c; /* Para recorrido matriz                        */
     int menorf;   /* Determina el menor elemento de la fila       */
     int cm;       /* Determina la columna de menorf               */
     int flag_ps;  /* Flag para determinar si el punto es silla    */

     for (f = 0; f < filas; f++)  /*(1)*/ /* Recorrido por filas */
     {
        menorf = ma[f][0];
        cm     = 0;
        for (c = 1; c < columnas; c++)
          if (menorf > ma[f][c])
            { menorf = ma[f][c];
              cm     = c;
            }
         /* -----> Ha quedado determinado el menor de la fila f */
         /* -----> La columna del menorf es mc                  */

         /* -----> Recorremos la columna cm hasta que encontrar */
         /* -----> un valor mayor que menorf. Si fuera así, el  */
         /* -----> el punto menorf en la fila f, no es de silla */
         flag_ps = 1;
         f2      = 0;
         while (flag_ps && f2 < filas)
           {  flag_ps = menorf >= ma[f2][cm];
              f2++;
           }

         if (flag_ps)
              ps[f]  = cm;  /* ---> Si el punto de la fila f es de silla, */
         else ps[f]  = -1;  /* ---> su columna es cm. Si no es de silla.  */
                            /* ---> Si no es de silla informamos -1 como  */
                            /* ---> número de columna                     */
     } /* Fin de (1) */

}
