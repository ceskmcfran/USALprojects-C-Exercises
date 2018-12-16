#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXTEXTO 100

/* Fuente: ESTACHAR.C
   Programa: ESTADÍSTICAS DE CARACTERES EN TEXTOS
   Descripción: Obtiene la frecuencia absoluta de aparición de cada uno de los 
   caracteres dentro de un texto, y el porcentaje respecto al 
   número total de caracteres del texto.
*/

int main(void) {

/* Definiciones de variables y constantes
   ---------------------------------------
*/
  char texto [MAXTEXTO+1];          /* Texto a introducir              */
  int  estadistica [256] = {0};     /* Vector de estadística           */
  int  longtexto = 0;               /* Números de caracteres del texto */

  int i;               /* Variable auxiliar para recorrer los vectores */
  char  terminar;      /* Para pedir al usuario terminar o no          */


/* Presentación del programa
   ---------------------------------------
*/
  printf("Estadística en textos\n");
  printf("=====================\n");
  printf("Dado un texto, se obtendrá para cada carácter, la frecuencia "
         "absoluta \nde aparición y el porcentaje respecto al número "
         "total de caracteres.\n");
  do 
  {
    /* Petición de datos. Lectura del texto
       ---------------------------------------
     */
       printf("\nIntroduzca un texto (máx. %d caracteres):\n", MAXTEXTO);
       fflush(stdin); /* Vaciado del buffer de teclado */
       gets(texto);

 
    /* Recorremos el texto totalizando en el vector estadística el número
       de apariciones de cada carácter. Cada carácter se totaliza en el
       índice que representa su código ASCII
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

    /* Presentamos el número de veces que cada carácter ha aparecido en el 
       texto, y su porcentaje de aparición respecto al número de caracteres 
       totales del texto
       --------------------------------------
     */
       printf("\n----------------- ESTADISTICAS ------------------\n");
       printf("Longitud del texto: %d\n", longtexto);
       printf("Carácter Cod ASCII Frecuencia absoluta Porcentaje\n");
       printf("-------- --------- ------------------- ----------\n");
    
       for (i=0; i < 256; i++)
           if (estadistica[i] != 0)
               printf("%4c%11d%16d%16.2f\n",
                  i, i, estadistica[i], (estadistica[i] * 100.0)/longtexto);

    /* Petición de nueva ejecución
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
