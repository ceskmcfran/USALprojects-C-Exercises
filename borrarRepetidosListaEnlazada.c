/*Programa:"borrarRepetidosListaEnlazada.c".
Autor:Francisco Blázquez Matías.
Curso:Primero de GII del grupo B3.
Fecha: 3/05/2015.
Descripción: Genera una lista con nº aleatorios y la muestra por pantalla, posteriormente genera otra con los mismos nº ordenados
y sin nº repetidos y la muestra por pantalla
Copyright:
*/



#include<stdio.h>
#include<stdlib.h>
#define MX 21

typedef struct nodo{

    int dato;
    struct nodo *sig;

} nodo;

typedef nodo * lista;

//Funciones

void borrarRepetidos(lista *);
void mostrarListaEnlazada(lista);
lista nuevoNodo(int);
void insertaNodoFinal(lista *, int);

int main(void){

    lista raiz;
    int dt;

    raiz = NULL;

    srand (time (0));  /* En otros compiladores randomize(); */

    for (dt = rand()%MX; dt; ){ /* Termina cuando se genera el número 0 */

        insertaNodoFinal(&raiz, dt);
        dt = rand()%MX;

    }

    mostrarListaEnlazada(raiz);

    printf("\n\n");

    borrarRepetidos(&raiz);

    mostrarListaEnlazada(raiz);

    printf("\n\n");



system("pause");
return 0;
}



void borrarRepetidos(lista *raiz){

    lista indice;
    lista aux;
    lista bucle;
    lista eliminar;
    int comparador;

    indice = *raiz;
    eliminar = *raiz;
    aux = *raiz;
    bucle = *raiz;

    while(bucle != NULL){

        comparador = bucle->dato;

        while(indice != NULL){

            if((comparador == indice->dato)&&(indice != bucle)){

                eliminar = indice;
                indice = indice->sig;
                free(eliminar);
                eliminar = NULL;
                aux->sig = indice;
                indice = aux;

            }

            aux = indice;
            indice = indice->sig;

        }


        bucle = bucle->sig;
        indice = bucle;
        aux = bucle;

    }
}



void mostrarListaEnlazada(lista raiz){

    lista indice;

    indice = raiz;

    while(indice != NULL){

        printf(" %d ", indice->dato);
        indice = indice->sig;

    }

    printf("\n\n");

}



lista nuevoNodo(int x) {
/* ---------------------------------------------------------- */
     lista a;

     a = (lista)malloc(sizeof(nodo));
     a -> dato = x;
     a -> sig  = NULL;
     return a;
}



void insertaNodoFinal (lista *raiz, int x) {
/* ---------------------------------------------------------- */
     lista nuevo;
     lista indice;

     nuevo = nuevoNodo(x);

     indice = *raiz;

     if (indice == NULL)
       /* Lista vacía. El nodo es el primero */
     *raiz = nuevo;
     else
       {
         /* Recorremos la lista hasta llegar a su final */
         while (indice->sig != NULL)
              indice = indice->sig;
         indice->sig = nuevo;
       }
}
