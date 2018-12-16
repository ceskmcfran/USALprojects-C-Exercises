#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define DIAS 7
#define MUESTRAS 5

/* Fuente: ESTATEMP.C
   Programa: ESTAD�STICA MUESTRAS TEMPERATURAS
   Descripci�n: Pide las MUESTRAS de temperaturas tomadas en DIAS d�as y presenta
   un informe estad�stico en pantalla, el cual incluye la temperatura m�xima, m�nima
   y media diaria y la temperatura m�xima, m�nima y media de las muestras
*/

int main(void) {

/* Definiciones de variables y constantes
   ---------------------------------------
*/
  float temperatura [DIAS][MUESTRAS];    /* Tabla de temperaturas      */
  float tmaxima [DIAS];                  /* Temperatura m�xima por d�a */
  float tminima [DIAS];                  /* Temperatura m�nima por d�a */
  float tmedia  [DIAS];                  /* Temperatura media por d�a  */

  float maxima_muestra, minima_muestra, media_muestra;

  int d, m;        /* Variables auxiliares para recorrer las matrices  */
  char  terminar;  /* Para pedir al usuario terminar o no              */


/* Presentaci�n del programa
   ---------------------------------------
*/
  system ("cls");  /* Borrado de la pantalla */

  printf("ESTADISTICA DE TEMPERATURAS\n");
  printf("===========================\n");
  printf("Se pedir�n por pantalla las %d muestras de temperatura tomadas "
         "en %d d�as.\n", MUESTRAS, DIAS);
  printf("Posteriormente el programa presentar� una tabla con la "
         "temperatura m�xima, \nm�nima y media d�a a d�a, y con la "
         "temperatura m�xima, m�nima y media de \nlas muestras.\n");

  do 
  {
    /* Petici�n de datos
       Lectura de teclado de las muestras de temperaturas tomadas
       ----------------------------------------------------------
     */
       puts("\nIntroduzca las muestras de temperaturas:");
       for (d=0; d < DIAS; d++)
           { for (m=0; m < MUESTRAS; m++)
                 { printf("D�a %d. Muestra %d?: ", d+1, m+1);
                   scanf("%f", &temperatura[d][m]);
                 }
             printf("\n");
           }

    /* C�lculo de la temperatura m�xima y m�nima diaria
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

 
    /* C�lculo de la temperatura media diaria
       Almacen�ndola en el vector correspondiente
       ------------------------------------------
     */
       for (d=0; d < DIAS; d++)
          { tmedia[d] = 0;
            for (m=0; m < MUESTRAS; m++)
                tmedia[d] += temperatura[d][m];
            tmedia[d] = tmedia[d] / MUESTRAS;
          }

    /* C�lculo de la temperatura m�xima y m�nima de las muestras
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
    /* C�lculo de la temperatura media de las muestras
       -----------------------------------------------
     */
       media_muestra = 0;
       for (d=0; d < DIAS; d++)
              media_muestra += tmedia[d];
       media_muestra = media_muestra / DIAS;


   /* Presentaci�n del informe en pantalla
      ------------------------------------
    */
      printf("\nINFORME TEMPERATURAS\n");
      printf("======================\n");
      printf("DIA   MAXIMA  MINIMA  MEDIA\n");
      for (d=0; d < DIAS; d++)
           printf("%3d   %5.2f   %5.2f   %5.2f\n",
                   d+1, tmaxima[d], tminima[d], tmedia[d]);

      printf("\nTemperatura m�xima muestras: %5.2f\n", maxima_muestra);
      printf("Temperatura m�nima muestras: %5.2f\n", minima_muestra);
      printf("Temperatura media  muestras: %5.2f\n", media_muestra);

 
    /* Petici�n de nueva ejecuci�n
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
