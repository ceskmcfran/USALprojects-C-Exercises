/*Programa:"columnaMaxMatrizDinamica.c".
Autor:Francisco Blázquez Matías.
Curso:Primero de GII del grupo B3.
Fecha: 22/5/2015.
Descripción:
Copyright:
*/

#include<stdio.h>
#include<stdlib.h>
#define RANDS 1001

/*Tipos de datos*/

typedef struct matInt{

    int **m;
    int numfil, numcol;

}matInt;

typedef matInt* matIntRef;


/*Prototipos*/

int *obtenerVectorColumnaMaxMatInt(matIntRef, int *);
matIntRef crearMatriz(int, int, int *);
void rellenarAleatoria(matIntRef);
void mostrarMatriz(matIntRef);


/*Modulo principal*/

int main(void){

    matIntRef mat;
    int *vectCol;
    int nFil, nCol;
    int errNum;
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

    vectCol = obtenerVectorColumnaMaxMatInt(mat, &errNum);

    printf("\nLa columna de la matriz es: \n");

    for(i=0; i<nFil; i++){

        printf("| %d |\n", vectCol[i]);

    }

    free(vectCol);
    for(i=0; i<nFil; i++){

        free(mat->m[i]);

    }
    free(mat->m);
    free(mat);



system("pause");
return 0;
}



/*Funciones*/

int *obtenerVectorColumnaMaxMatInt(matIntRef ma, int *numError){

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

    *numError = 0;

return vect;
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

        mat->numcol = numcol;
        mat->numfil = numfil;
        for(i=0; i< numfil; i++){
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

    for(i=0; i<mat->numfil; i++){
        for(j=0; j<mat->numcol; j++){

            mat->m[i][j] = rand() % RANDS;

        }
    }
}



void mostrarMatriz(matIntRef mat){

    int i, j;

    for(i=0; i<mat->numfil; i++){

        printf("| ");

        for(j=0; j<mat->numcol; j++){

            printf("%d ", mat->m[i][j]);

        }
        printf("|\n");
    }
}
