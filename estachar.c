#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXTEXTO 100

/* Fuente: ESTACHAR.C
   Programa: ESTAD�STICAS DE CARACTERES EN TEXTOS
   Descripci�n: Obtiene la frecuencia absoluta de aparici�n de cada uno de los 
   caracteres dentro de un texto, y el porcentaje respecto al 
   n�mero total de caracteres del texto.
*/

int main(void) {

/* Definiciones de variables y constantes
   ---------------------------------------
*/
  char texto [MAXTEXTO+1];          /* Texto a introducir              */
  int  estadistica [256] = {0};     /* Vector de estad�stica           */
  int  longtexto = 0;               /* N�meros de caracteres del texto */

  int i;               /* Variable auxiliar para recorrer los vectores */
  char  terminar;      /* Para pedir al usuario terminar o no          */


/* Presentaci�n del programa
   ---------------------------------------
*/
  printf("Estad�stica en textos\n");
  printf("=====================\n");
  printf("Dado un texto, se obtendr� para cada car�cter, la frecuencia "
         "absoluta \nde aparici�n y el porcentaje respecto al n�mero "
         "total de caracteres.\n");
  do 
  {
    /* Petici�n de datos. Lectura del texto
       ---------------------------------------
     */
       printf("\nIntroduzca un texto (m�x. %d caracteres):\n", MAXTEXTO);
       fflush(stdin); /* Vaciado del buffer de teclado */
       gets(texto);

 
    /* Recorremos el texto totalizando en el vector estad�stica el n�mero
       de apariciones de cada car�cter. Cada car�cter se totaliza en el
       �ndice que representa su c�digo ASCII
       --------------------------------------
     */

       longtexto = 0;
       for (i=0; i < 256; i++)
            estadistica[i] = 0;
 
       i = 0;
       while (texto[i] != '\0')
       { longtexto++;
         estadistica[(unsigned char) texto[i]]++;
         i++;
       }

    /* Presentamos el n�mero de veces que cada car�cter ha aparecido en el 
       texto, y su porcentaje de aparici�n respecto al n�mero de caracteres 
       totales del texto
       --------------------------------------
     */
       printf("\n----------------- ESTADISTICAS ------------------\n");
       printf("Longitud del texto: %d\n", longtexto);
       printf("Car�cter Cod ASCII Frecuencia absoluta Porcentaje\n");
       printf("-------- --------- ------------------- ----------\n");
    
       for (i=0; i < 256; i++)
           if (estadistica[i] != 0)
               printf("%4c%11d%16d%16.2f\n",
                  i, i, estadistica[i], (estadistica[i] * 100.0)/longtexto);

    /* Petici�n de nueva ejecuci�n
       --------------------------
     */
       printf("\n");
       do
       { printf("Salir del programa (S/N)?: ");
	     fflush(stdin); /* Vaciado del buffer de teclado */
	     scanf("%c", &terminar);
	     terminar = toupper(terminar);
       } while (terminar != 'S' && terminar != 'N');

       system ("cls"); /* Borrado de la pantalla */

  } while (terminar != 'S');

  return 0;
}
