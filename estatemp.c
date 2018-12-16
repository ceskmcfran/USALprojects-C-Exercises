#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define DIAS 7
#define MUESTRAS 5

/* Fuente: ESTATEMP.C
   Programa: ESTADÍSTICA MUESTRAS TEMPERATURAS
   Descripción: Pide las MUESTRAS de temperaturas tomadas en DIAS días y presenta
   un informe estadístico en pantalla, el cual incluye la temperatura máxima, mínima
   y media diaria y la temperatura máxima, mínima y media de las muestras
*/

int main(void) {

/* Definiciones de variables y constantes
   ---------------------------------------
*/
  float temperatura [DIAS][MUESTRAS];    /* Tabla de temperaturas      */
  float tmaxima [DIAS];                  /* Temperatura máxima por día */
  float tminima [DIAS];                  /* Temperatura mínima por día */
  float tmedia  [DIAS];                  /* Temperatura media por día  */

  float maxima_muestra, minima_muestra, media_muestra;

  int d, m;        /* Variables auxiliares para recorrer las matrices  */
  char  terminar;  /* Para pedir al usuario terminar o no              */


/* Presentación del programa
   ---------------------------------------
*/
  system ("cls");  /* Borrado de la pantalla */

  printf("ESTADISTICA DE TEMPERATURAS\n");
  printf("===========================\n");
  printf("Se pedirán por pantalla las %d muestras de temperatura tomadas "
         "en %d días.\n", MUESTRAS, DIAS);
  printf("Posteriormente el programa presentará una tabla con la "
         "temperatura máxima, \nmínima y media día a día, y con la "
         "temperatura máxima, mínima y media de \nlas muestras.\n");

  do 
  {
    /* Petición de datos
       Lectura de teclado de las muestras de temperaturas tomadas
       ----------------------------------------------------------
     */
       puts("\nIntroduzca las muestras de temperaturas:");
       for (d=0; d < DIAS; d++)
           { for (m=0; m < MUESTRAS; m++)
                 { printf("Día %d. Muestra %d?: ", d+1, m+1);
                   scanf("%f", &temperatura[d][m]);
                 }
             printf("\n");
           }

    /* Cálculo de la temperatura máxima y mínima diaria
       Almacenando cada una de ellas en el vector correspondiente
       ----------------------------------------------------------
     */

       for (d=0; d < DIAS; d++)
          { tmaxima[d] = temperatura[d][0];
            tminima[d] = temperatura[d][0];
            for (m=1; m < MUESTRAS; m++)
                if (temperatura[d][m] > tmaxima[d])
                       tmaxima[d] = temperatura[d][m];
                else if (temperatura[d][m] < tminima[d])
                           tminima[d] = temperatura[d][m];
          }

 
    /* Cálculo de la temperatura media diaria
       Almacenándola en el vector correspondiente
       ------------------------------------------
     */
       for (d=0; d < DIAS; d++)
          { tmedia[d] = 0;
            for (m=0; m < MUESTRAS; m++)
                tmedia[d] += temperatura[d][m];
            tmedia[d] = tmedia[d] / MUESTRAS;
          }

    /* Cálculo de la temperatura máxima y mínima de las muestras
       ---------------------------------------------------------
     */
       maxima_muestra = tmaxima[0];
       minima_muestra = tminima[0];
       for (d=1; d < DIAS; d++)
          { if (tmaxima[d] > maxima_muestra)
                 maxima_muestra = tmaxima[d];
            if (tminima[d] < minima_muestra)
                 minima_muestra = tminima[d];
          } 
    /* Cálculo de la temperatura media de las muestras
       -----------------------------------------------
     */
       media_muestra = 0;
       for (d=0; d < DIAS; d++)
              media_muestra += tmedia[d];
       media_muestra = media_muestra / DIAS;


   /* Presentación del informe en pantalla
      ------------------------------------
    */
      printf("\nINFORME TEMPERATURAS\n");
      printf("======================\n");
      printf("DIA   MAXIMA  MINIMA  MEDIA\n");
      for (d=0; d < DIAS; d++)
           printf("%3d   %5.2f   %5.2f   %5.2f\n",
                   d+1, tmaxima[d], tminima[d], tmedia[d]);

      printf("\nTemperatura máxima muestras: %5.2f\n", maxima_muestra);
      printf("Temperatura mínima muestras: %5.2f\n", minima_muestra);
      printf("Temperatura media  muestras: %5.2f\n", media_muestra);

 
    /* Petición de nueva ejecución
       --------------------------
     */
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
