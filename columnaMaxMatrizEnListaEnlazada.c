/*Programa:"columnaMaxMatrizEnListaEnlazada.c".
Autor:Francisco Blázquez Matías.
Curso:Primero de GII del grupo B3.
Fecha: 24/5/2015.
Descripción:
Copyright:
*/

#include<stdio.h>
#include<stdlib.h>
#define RANDM 1001

/*Tipos de datos*/

typedef struct matInt{

    int **m;
    int numfil, numcol;

}matInt;


typedef matInt* matIntRef;


typedef struct tipoNodo{

    int info;
    struct tipoNodo *sig;

}tipoNodo;


typedef tipoNodo* tipoLista;


/*Prototipos*/

tipoLista obtenerListaEnlazadaColumnaMaxMatInt(matIntRef, int *);
matIntRef crearMatriz(int, int, int *);
void rellenarAleatoria(matIntRef);
void mostrarMatriz(matIntRef);
void mostrarListaEnlazada(tipoLista);
void liberarListaEnlazada(tipoLista *);


/*Modulo principal*/

int main(void){

    matIntRef mat;
    tipoLista raiz;
    int errNum;
    int nFil, nCol;
    int i;


    printf("Introduzca el numero de filas de la matriz:  ");
    scanf("%d", &nFil);

    printf("Introduzca el numero de columnas de la matriz:  ");
    scanf("%d", &nCol);

    mat = crearMatriz(nFil, nCol, &errNum);

    rellenarAleatoria(mat);

    printf("\nLa matriz es:\n\n");
    mostrarMatriz(mat);

    printf("\n\n");

    raiz = obtenerListaEnlazadaColumnaMaxMatInt(mat, &errNum);

    printf("Lista enlazada con la columna maxima:\n\n");
    mostrarListaEnlazada(raiz);

    liberarListaEnlazada(&raiz);
    free(raiz);
    for(i=0; i<nFil; i++){

        free(mat->m[i]);

    }
    free(mat->m);
    free(mat);
    mat = NULL;

    printf("\n\n");


system("pause");
return 0;
}



/*Funciones*/

tipoLista obtenerListaEnlazadaColumnaMaxMatInt(matIntRef ma, int *numError){

    tipoLista raiz;
    tipoLista creador;
    tipoLista indice;
    int *vect; //Puntero al vector dinamico
    int i, j; //contadores
    int nummay = 0;
    int colMax = 0;

    if((ma->numfil <= 0) || (ma->numcol <= 0) || (ma == NULL) || (ma->m == NULL)){

        *numError = -1;
        return NULL;

    }
    if(NULL == (vect = malloc(ma->numfil*sizeof(int)))){

        *numError = -2;
        return NULL;

    }

    for(i=0; i<ma->numfil; i++){
        for(j=0; j<ma->numcol; j++){

            if(ma->m[i][j] > nummay){

                nummay = ma->m[i][j];
                colMax = j;

            }
        }
    }
    for(j=0; j<ma->numfil; j++){

        vect[j] = ma->m[j][colMax];

    }
    if(NULL == (raiz = (tipoLista)malloc(sizeof(tipoNodo)))){

        *numError = -3;
        return NULL;

    }

    raiz->info = vect[0];
    raiz->sig = NULL;
    indice = raiz;

    for(i=1; i<ma->numfil; i++){
        if(NULL == (creador = (tipoLista)malloc(sizeof(tipoNodo)))){

            free(raiz);
            raiz = NULL;
            *numError = -4;
            return NULL;

        }
        indice->sig = creador;
        indice = indice->sig;
        indice->info = vect[i];
        indice->sig = NULL;
        creador = NULL;

    }

    *numError = 0;
    free(vect);

    return raiz;

}



matIntRef crearMatriz(int numfil, int numcol, int *errNum){

    matIntRef mat;
    int i;

    if(numfil <= 0 || numcol <= 0){

        *errNum = -1;
        return NULL;

    }
    if(NULL == (mat = malloc(sizeof(matInt)))){

        *errNum = -2;
        return NULL;

    }
    if(NULL == (mat->m = malloc(numfil*sizeof(int *)))){

        free(mat);
        *errNum = -3;
        return NULL;

    }
    else{

        mat->numfil = numfil;
        mat->numcol = numcol;

        for(i=0; i<numfil; i++){

            if(NULL == (mat->m[i] = malloc(numcol*sizeof(int)))){

                for(i--; i >= 0; i--){

                    free(mat->m[i]);

                }

                    free(mat->m);
                    free(mat);
                    *errNum = -4;
                    return NULL;
            }
        }

        *errNum = 0;
        return mat;
    }
}



void rellenarAleatoria(matIntRef mat){

    int i, j;

    srand(time(NULL));

    for(i=0; i < mat->numfil; i++){
        for(j=0; j < mat->numcol; j++){

            mat->m[i][j] = rand() % RANDM;

        }
    }
}



void mostrarMatriz(matIntRef mat){

    int i, j;

    for(i=0; i < mat->numfil; i++){

        printf("|");

        for(j=0; j < mat->numcol; j++){

            printf(" %d ", mat->m[i][j]);

        }

        printf("|\n");
    }
}



void mostrarListaEnlazada(tipoLista raiz){

    tipoLista indice;

    indice = raiz;

    while(indice != NULL){

        printf("| %d | ->", indice->info);
        indice = indice->sig;

    }
    printf(" NULL");

}



void liberarListaEnlazada(tipoLista *raiz){

    tipoLista indice;
    tipoLista ant;

    indice = *raiz;
    ant = indice;

    while(*raiz != NULL){

        *raiz = indice->sig;
        indice = indice->sig;
        free(ant);
        ant = *raiz;
        ant = indice = *raiz = NULL;

    }

}
