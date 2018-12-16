/*Programa:"columnaMaxMatrizFicheros.c".
Autor:Francisco Blázquez Matías.
Curso:Primero de GII del grupo B3.
Fecha: 25/5/2015.
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

int escribirFicheroColumnaMaxMatInt(matIntRef, char *);
matIntRef crearMatriz(int, int, int *);
void rellenarAleatoria(matIntRef);
void mostrarMatriz(matIntRef);


/*Modulo principal*/

int main(void){

    int nFil, nCol;
    matIntRef mat;
    int errNum;
    int i;
    char menu;
    int objEsc; //Numero de objetos escritos en el fichero
    char nombreFichero[] = "columnaMaxMatrizFicheros.bin";
    int vect; //Vector para leer el fichero
    FILE *fp;

    do{

        system("cls");
        printf("----------------\n");
        printf("MENU DE OPCIONES\n");
        printf("----------------\n");
        printf("1. Escribir matriz en fichero\n");
        printf("2. Leer matriz del fichero\n");
        printf("3. Salir\n\n");

        printf("Elija una opcion (INTRODUCIR SOLO NUMEROS ENTEROS):  ");
        scanf("%c", &menu);

        switch(menu){

            case '1' :

                printf("Numero de filas de la matriz:  ");
                scanf("%d", &nFil);

                printf("Numero de columnas de la matriz:  ");
                scanf("%d", &nCol);

                mat = crearMatriz(nFil, nCol, &errNum);

                rellenarAleatoria(mat);

                printf("La matriz es:\n");
                mostrarMatriz(mat);

                objEsc = escribirFicheroColumnaMaxMatInt(mat, nombreFichero);

                printf("\n\nEn el fichero se han escrito %d objetos", objEsc);

                for(i=0; i<nFil; i++){

                    free(mat->m[i]);

                }
                free(mat->m);
                free(mat);
                mat = NULL;

                printf("\n\n");
                system("pause");

                break;


            case '2' :

                if(NULL == (fp = fopen(nombreFichero, "rb"))){

                    printf("No se ha podido abrir el fichero.\n\n");
                    system("pause");
                    break;

                }

                printf("En el interior del fichero se encuentra:\n\n");

                fread(&vect, sizeof(vect), 1, fp);

                while(!feof(fp)){

                    printf("| %d |\n", vect);

                    fread(&vect, sizeof(vect), 1, fp);
                }
                printf("\nEl fichero se ha leido correctamente\n\n");

                fclose(fp);
                system("pause");
                break;


        }

    }while(menu != '3');

system("pause");
return 0;
}



/*Funciones*/

int escribirFicheroColumnaMaxMatInt(matIntRef ma, char *nombreFichero){

    int *vect; //Puntero al vector dinamico
    int i, j; //contadores
    FILE *fp;
    int nummay = 0;
    int objEsc;
    int colMax = 0;

    if((ma->numfil <= 0) || (ma->numcol <= 0) || (ma == NULL) || (ma->m == NULL)){

        return -1;

    }
    if(NULL == (vect = malloc(ma->numfil*sizeof(int)))){

        return -2;

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

    if(NULL == (fp = fopen(nombreFichero, "wb"))){

        printf("No se ha podido abrir el fichero.\n\n");
        system("pause");
        return -3;

    }

    objEsc = fwrite(&vect[0], sizeof(vect[0]), ma->numfil, fp);

    printf("\nEl fichero se ha modificado correctamente");

    fclose(fp);

    free(vect);
    vect = NULL;

    return objEsc;

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
        mat = NULL;
        *errNum = -3;
        return NULL;

    }
    mat->numcol = numcol;
    mat->numfil = numfil;

    for(i=0; i<numfil; i++){
        if(NULL == (mat->m[i] = malloc(numcol*sizeof(int)))){

            for(i--; i>=0; i--){

                free(mat->m[i]);

            }
            free(mat->m);
            free(mat);
            mat = NULL;
            *errNum = -4;
            return NULL;

        }
    }

    *errNum = 0;
    return mat;

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
