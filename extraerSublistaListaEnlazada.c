/*Programa:"OrdenarListaEnlazada.c".
Autor:Francisco Blázquez Matías.
Curso:Primero de GII del grupo B3.
Fecha: 3/05/2015.
Descripción: Genera una lista con nº aleatorios y la muestra por pantalla
Copyright:
*/


#include<stdio.h>
#include<stdlib.h>
#define MAX 101

typedef struct tipoNodo{

    int dato;
    struct tipoNodo *sig;

} NODO;

void insertaNodoFinal (NODO **, int);
NODO *nuevoNodo(int);
int  numeroDeNodos (NODO *);
void escribeLista (NODO *);
NODO *extraerSublistaListaEnlazada(NODO **, int, int);


int main(void){

    NODO *lista; //Puntero al primer elemento de la lista enlazada
    NODO *listaext; //Puntero al primer elemento de la sublista enlazada
    int dt; //dato
    int num1, num2;

    lista = NULL;
    srand(time(0));
    for(dt = rand()%MAX; dt;){

        insertaNodoFinal(&lista, dt);
        dt = rand()%MAX;

    }

    printf("El numero de nodos de la lista es:  %d\n", numeroDeNodos(lista));
    printf("El contenido de la lista:\n\n ");
    escribeLista(lista);

    printf("\nIntroduce la posicion de inicio:  ");
    scanf("%d", &num1);
    printf("\nIntroduce la posicion final:  ");
    scanf("%d", &num2);

    listaext = extraerSublistaListaEnlazada(&lista, num1, num2);

    printf("\nEl numero de nodos de la lista principal es ahora:  %d\n", numeroDeNodos(lista));
    printf("El contenido de la lista ahora es:\n\n");
    escribeLista(lista);

    printf("\nEl numero de nodos de la sublista es:  %d\n", numeroDeNodos(listaext));
    printf("El contenido de la sublista es: \n\n");
    escribeLista(listaext);




system("pause");
return 0;
}



NODO *nuevoNodo(int x){

    NODO *a;

    a = (NODO *)malloc(sizeof(NODO));
    a -> dato = x;
    a -> sig = NULL;

    return a;
}



void insertaNodoFinal(NODO **lst, int x){

    NODO *indice, *nuevo;

    nuevo = nuevoNodo(x);

    indice = *lst;

    if(indice -> sig == NULL){

        *lst = nuevo;

    }
    else{

        while(indice -> sig != NULL){

            indice = indice -> sig;

        }

        indice -> sig = nuevo;

    }

}



int numeroDeNodos(NODO *lst){

    NODO *indice;
    int i = 0;

    indice = lst;

    while(indice != NULL){

        i++;
        indice = indice -> sig;

    }

return i;
}



void escribeLista(NODO* lst){

    NODO *indice;

    indice = lst;

    while(indice != NULL){

        printf("%8d", indice -> dato);
        indice = indice -> sig;

    }

}



NODO *extraerSublistaListaEnlazada(NODO **raiz, int inicio, int fin){

    NODO *raiz2; //Raiz de la sublista
    NODO *indice;
    NODO *ant;

    int temp;
    int i=0;


    raiz2 = NULL;
    ant = NULL;

    if(inicio > fin){

        temp = inicio;
        inicio = fin;
        fin = temp;

    }

    indice = *raiz;

    while(indice != NULL && i < fin){
        if(i++ < inicio){

            ant = indice;

        }
        indice = indice->sig;

    }
    if(ant == NULL){

        raiz2 = *raiz;

        if(indice != NULL){

            *raiz = indice->sig;
            indice->sig = NULL;

        }
        else{

            *raiz = indice;

        }
    }
    else{

        raiz2 = ant->sig;
        if(indice != NULL){

            ant->sig = indice->sig;
            indice->sig = NULL;

        }
        else{

            ant->sig = NULL;

        }
    }

return raiz2;
}

//Extraer sublista enlazada de otro modo más arreglado.
/*
NODO *extraerSublistaListaEnlazada2(NODO **raiz, int inicio, int fin){

    int temp, i;
    NODO aux;
    NODO ant;
    NODO raizDevolver;


    if(inicio > fin){

        temp = inicio;
        inicio = fin;
        fin = temp;

    }

    i=0;
    ant = NULL;
    aux = *raiz;

    while(aux->sig != NULL && i < fin){

        if(i++ < inicio){

            ant = aux;

        }

        aux = aux->sig;

    }
    if(ant == NULL){

        raizDevolver = *raiz;
        *raiz = aux->sig;
        aux->sig = NULL;

    }
    else{

        raizDevolver = ant->sig;
        ant->sig = aux->sig;
        aux->sig = NULL;

    }

return raizDevolver;
}
*/
