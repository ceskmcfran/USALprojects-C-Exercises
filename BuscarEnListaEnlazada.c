#include<stdio.h>
#include<stdlib.h>
#define MX 51

//Definicion del nodo

     typedef struct Nodo {
         int  dato;
         struct Nodo *sig;
     } NODO;

//Prototipos

NODO *nuevoNodo (int);
void insertaNodoFinal (NODO **, int);
void escribeLista (NODO *);
int  numeroDeNodos (NODO *);
void eliminaNodo (NODO **, int);



int main(void){

    NODO *lista;
    int dt;
    int num;


    lista =  NULL;
    srand (time (0));  /* En otros compiladores randomize(); */
    for (dt = rand()%MX; dt; ) /* Termina cuando se genera el número 0 */
    {  insertaNodoFinal (&lista, dt);
       dt = rand()%MX;
    }

     printf("Número de nodos de la lista: %d\n", numeroDeNodos(lista));
     printf("Contenido de la lista:\n");
     escribeLista(lista);

     printf("\n");

     printf("Introduce un numero:  ");
     scanf("%d", &num);

     eliminaNodo(&lista, num);

     printf("Número de nodos de la lista: %d\n", numeroDeNodos(lista));
     printf("Contenido de la lista:\n");
     escribeLista(lista);


system("pause");
return 0;
}


/* ---------------------------------------------------------- */
   NODO *nuevoNodo (int x) {
/* ---------------------------------------------------------- */
     NODO *a;

     a = (NODO *) malloc (sizeof(NODO));
     a -> dato = x;
     a -> sig  = NULL;
     return a;
}



/* ---------------------------------------------------------- */
   void insertaNodoFinal (NODO **lst, int x) {
/* ---------------------------------------------------------- */
     NODO *nuevo, *indice;

     nuevo = nuevoNodo (x);

     indice = *lst;
     if (indice == NULL)
       /* Lista vacía. El nodo es el primero */
     *lst = nuevo;
     else
       {
         /* Recorremos la lista hasta llegar a su final */
         while (indice -> sig != NULL)
              indice = indice -> sig;
         indice -> sig = nuevo;
       }
}


/* ---------------------------------------------------------- */
   void escribeLista (NODO *lst) {
/* ---------------------------------------------------------- */
     NODO *indice;

     indice = lst;
     while (indice != NULL)
     { printf("%8d", indice -> dato);
       indice = indice -> sig;
     }
}



/* ---------------------------------------------------------- */
   int numeroDeNodos (NODO *lst) {
/* ---------------------------------------------------------- */
     int k=0;
     NODO *indice;

     indice = lst;
     while (indice != NULL) {
        k++;
        indice = indice -> sig;
     }
    return (k);
}


/* ---------------------------------------------------------- */
   void eliminaNodo(NODO **lst, int num){
/* ---------------------------------------------------------- */

    NODO *indice, *anterior;

    indice = *lst;
    anterior = indice;

    while(indice != NULL){

        if(indice->dato == num){

              anterior->sig = indice->sig;
              free(indice);
              indice = anterior->sig;
        }
        else{

              anterior = indice;
              indice = indice->sig;

        }
    }

}
