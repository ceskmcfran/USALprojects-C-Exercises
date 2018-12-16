#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define DIMMAX 11

/* Fuente: ESTADEPO.C
   Programa: ESTADÍSTICA EQUIPO DEPORTIVO
   Descripción: Pide por el nombre la edad y la estatura de cada uno de
   los jugadores de un equipo y presenta diversas estadísticas: edad y
   estatura máxima, mínima y media
*/

int main(void) {
/* Definiciones de variables y constantes
   ---------------------------------------
*/
  char  nombre[DIMMAX][50];  /* Vector para nombres de los jugadores    */
  int   edad[DIMMAX];        /* Vector para edad de los jugadores       */
  float talla[DIMMAX];       /* Vector para estatura de los jugadores   */
  char  nombre_equipo[30];   /* Nombre del equipo que se está tratando  */

  float edad_media;          /* Edad media del equipo a calcular        */
  int   edad_min;            /* Edad mínima del equipo a calcular       */
  int   numjug_edad_min;     /* Número de jugadores con edad mínima     */

  float talla_media;         /* Estatura media del equipo a calcular    */
  float talla_max;           /* Estatura máxima del equipo a calcular   */
  int   numjug_talla_max;    /* Número de jugadores con estatura máxima */

  int i;               /* Variable auxiliar para recorrer los vectores */
  char  terminar;      /* Para pedir al usuario terminar o no          */

/* Presentación del programa
   ---------------------------------------
*/
  system ("cls");  /* Borrado de la pantalla */
  printf("ESTADISTICA DEPORTIVA\n");
  printf("=====================\n\n");
  printf("Se pedirán por pantalla los nombres, edades y estaturas "
	 "de los %d jugadores \n"
	 "de un equipo, y posteriormente se presentará:\n", DIMMAX);
 
  printf("   - La estatura y edad media del equipo.\n"
	   "   - La edad mínima del equipo y el número, nombre y estatura de "
	   "los jugadores \n     que la poseen.\n"
	   "   - La estatura máxima del equipo y el número, nombre y edad de "
	   "los jugadores \n     que la poseen.\n\n");

  do
  { 
    /* Petición y validación de datos
       ---------------------------------------
     */
       fflush(stdin); /* Vaciado del buffer de teclado */
       printf("Introduzca el nombre del equipo: ");
       gets(nombre_equipo);

       puts("\nIntroduzca los datos de los jugadores:");
       for (i=0; i < DIMMAX; i++)
	    {
	      fflush(stdin); /* Vaciado del buffer de teclado */
	      printf("Nombre jugador   %2d?: ", i+1);
	      gets(nombre[i]);
	      printf("Edad jugador     %2d?: ", i+1);
	      scanf("%d", &edad[i]);
	      printf("Estatura jugador %2d?: ", i+1);
	      scanf("%f", &talla[i]);
	      printf("\n");
	    }


    /* Cálculos
       ---------------------------------------
    */

    /*
     * Edad mínima y media
     * Número de jugadores con edad mínima
     */
	edad_media = edad_min = edad[0];
	numjug_edad_min = 1;
	for (i=1; i < DIMMAX; i++)
	    { edad_media += edad[i];
	      if (edad[i] == edad_min)
		  numjug_edad_min++;
	      else
		 if (edad[i] < edad_min)
		   { edad_min = edad[i];
		     numjug_edad_min = 1;
		   }
	    }

	edad_media /= (float) DIMMAX;


    /*
     * Estatura máxima y media
     * Número de jugadores con estatura máxima
     */
	talla_media = talla_max = talla[0];
	numjug_talla_max = 1;
	for (i=1; i < DIMMAX; i++)
	    { talla_media += talla[i];
	      if (talla[i] == talla_max)
		  numjug_talla_max++;
	      else
		 if (talla[i] > talla_max)
		   { talla_max = talla[i];
		     numjug_talla_max = 1;
		   }
	    }

	talla_media /= (float) DIMMAX;


    /* Resultados
       ---------------------------------------
    */
       printf("\n\n");
       puts(nombre_equipo);
       for (i=1; i<=strlen(nombre_equipo); i++)
	    printf("=");

       printf("\nEdad media del equipo..........: %.2f\n", edad_media);
       printf("Estatura media del equipo......: %.2f\n", talla_media);

       printf("\nEdad mínima del equipo.........: %d\n", edad_min);
       printf("Jugadores con edad mínima......: %d\n", numjug_edad_min);
       printf("            Nombre             Estatura\n");
       printf("------------------------------ --------\n");
       for (i=0; i < DIMMAX; i++)
	    if (edad[i] == edad_min)
		printf ("%-30s %7.2f\n", nombre[i], talla[i]);

       printf("\nEstatura máxima del equipo.....: %.2f\n", talla_max);
       printf("Jugadores con estatura máxima..: %d\n", numjug_talla_max);
       printf("            Nombre               Edad  \n");
       printf("------------------------------ --------\n");
       for (i=0; i < DIMMAX; i++)
	    if (talla[i] == talla_max)
		printf ("%-30s %7d\n", nombre[i], edad[i]);

 
       printf("\n\n");
       do
       { printf("Salir del programa (S/N)?: ");
	     fflush(stdin); /* Vaciado del buffer de teclado */
	     scanf("%c", &terminar);
	     terminar = toupper(terminar);
       } while (terminar != 'S' && terminar != 'N');

       system ("cls");  /* Borrado de la pantalla */

  } while (terminar != 'S');

  return 0;
}
