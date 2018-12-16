/*Programa:"sacarColumnaOrdenadaAFichero".
Autor:Francisco Blázquez Matías.
Curso:Primero de GII del grupo B3.
Fecha: 30/5/2015.
Descripción: Crea una matriz aleatoria dínamica, sacar la columna introducida y meterla en una lista enlazada, ordenarla y meterla
en un fichero.
Copyright:
*/

#include<stdio.h>
#include<stdlib.h>
#define RANDS 1001

/*Tipos de datos*/

typedef struct matriz{

    int **m;
    int fil;
    int col;

}ma;

typedef ma* matRef;

typedef struct nod{

    int dato;
    struct nod *sig;

}nodo;

typedef nodo* lista;



/*Prototipos*/

matRef crearMatriz(int, int, int *);
void rellenarAleatoria(matRef);
void mostrarMatriz(matRef);
lista extraerColumnaALista(matRef mat, int colExt,int *errNum);
void mostrarListaEnlazada(lista);
void ordenarListaEnlazada(lista *, matRef);
void liberarListaEnlazada(lista *);
void liberarMatriz(matRef);


/*Modulo principal*/

int main(void){

    char menu; //Controlador del menu
    int nFil, nCol; //Filas y columnas de la matriz
    int errNum; //Controlador de errores
    int columna; //Columna a guardar en la lista enlazada
    matRef mat; //Matriz dinamica
    lista raiz; //Raiz de la lista enlazada
    FILE *ft; //Puntero al fichero de texto
    FILE *fb; //Puntero al fichero binario
    char fichbin[] = "sacarColumnaOrdenadaAFichero.bin"; //Archivo de texto
    char fichtxt[] = "sacarColumnaOrdenadaAFichero.txt"; //Archivo binario
    lista indice = NULL; //Controlador de la lista enlazada
    int numero; //Variable donde guardar la lectura de los ficheros


    do{
        system("cls");
        printf("----------------\n");
        printf("MENU DE OPCIONES\n");
        printf("----------------\n");
        printf("1. Introducir dimensiones y rellenar\n");
        printf("2. Mostrar matriz\n");
        printf("3. Introducir columna a ordenar y guardar en lista\n");
        printf("4. Mostrar lista enlazada\n");
        printf("5. Guardar en fichero texto\n");
        printf("6. Guardar en fichero binario\n");
        printf("7. Mostrar fichero texto\n");
        printf("8. Mostrar fichero binario\n");
        printf("9. Salir\n\n");

        printf("Elija una opcion (INTRODUCIR SOLO NUMEROS ENTEROS):  ");
        scanf("%c", &menu);

        switch(menu){

            case '1' :

                printf("Introduce el numero de filas:  ");
                scanf("%d", &nFil);
                printf("Introduce el numero de columnas:  ");
                scanf("%d", &nCol);

                mat = crearMatriz(nFil, nCol, &errNum);

                printf("\n\nLa matriz ha sido creada");

                rellenarAleatoria(mat);

                printf("\nLa matriz ha sido rellenada\n\n");
                system("pause");
                break;


            case '2' :

                if(mat->m != NULL){

                    mostrarMatriz(mat);

                }
                else{

                    printf("No existe una matriz todavia\n\n");

                }
                system("pause");
                break;


            case '3' :

                printf("Introduce la columna que quieres guardar en la lista enlazada:  ");
                scanf("%d", &columna);

                columna--;

                raiz = extraerColumnaALista(mat, columna, &errNum);

                printf("\n\nLa columna ha sido guardada en la lista enlazada");

                ordenarListaEnlazada(&raiz, mat);

                printf("\nLa lista esta ordenada\n\n");
                system("pause");
                break;


            case '4' :

                if(raiz != NULL){

                    mostrarListaEnlazada(raiz);
                }
                else{

                    printf("No existe ninguna lista enlazada todavia\n\n");

                }
                system("pause");
                break;


            case '5' :

                indice = raiz;

                if(NULL == (ft = fopen(fichtxt, "w"))){

                    errNum = -1;
                    printf("No se ha podido abrir el fichero");
                    system("pause");
                    break;

                }
                else{

                    while(indice != NULL){

                        fprintf(ft, "%d\n", indice->dato);
                        indice = indice->sig;

                    }

                }

                printf("Se ha escrito con exito en el fichero de texto.");

                fclose(ft);
                errNum = 0;

                printf("\n\n");
                system("pause");
                break;


            case '6' :

                indice = raiz;

                if(NULL == (fb = fopen(fichbin, "wb"))){

                    errNum = -1;
                    printf("No se ha podido abrir el fichero");
                    system("pause");

                }
                else{
                    while(indice != NULL){

                        fwrite(&(indice->dato), sizeof(int), 1, fb);

                        indice = indice->sig;

                    }
                }

                printf("\n\nSe ha escrito con exito en el fichero binario.\n");

                fclose(fb);
                errNum = 0;

                printf("\n\n");
                system("pause");
                break;


            case '7' :

                if(NULL == (ft = fopen(fichtxt, "r"))){

                    errNum = -1;
                    printf("No se ha podido abrir el fichero");
                    system("pause");

                }
                if(fflush(ft) == 0){

                    while( fscanf(ft, "%d", &numero) != EOF){

                        printf("| %d |\n", numero);

                    }
                }

                printf("\nEl fichero se ha leido correctamente");

                fclose(ft);
                errNum = 0;

                printf("\n\n");
                system("pause");
                break;


            case '8' :

                if(NULL == (fb = fopen(fichbin, "rb"))){

                    errNum = -1;
                    printf("No se ha podido abrir el fichero");
                    system("pause");

                }

                fread(&numero, sizeof(numero), 1, fb);

                while(!(feof(fb))){

                    printf("| %d |\n", numero);
                    fread(&numero, sizeof(numero), 1, fb);

                }

                printf("\n\nEl fichero se ha leido correctamente");

                fclose(fb);
                errNum = 0;

                printf("\n\n");
                system("pause");
                break;

        }
    }while (menu != '9');

    liberarListaEnlazada(&raiz);
    if(mat->m != NULL){

        liberarMatriz(mat);
        free(mat);
        mat = NULL;

    }

system("pause");
return 0;
}



/*Funciones*/

matRef crearMatriz(int nFil, int nCol, int *errNum){

    matRef mat;
    int i;

    if(nFil <= 0 || nCol <= 0){

        *errNum = -1;
        return(NULL);

    }
    if(NULL == (mat = malloc(sizeof(ma)))){

        *errNum = -2;
        return NULL;
    }
    if(NULL == (mat->m = malloc(nFil*sizeof(int *)))){

        *errNum = -3;
        free(mat);
        mat = NULL;
        return NULL;

    }
    else{

        mat->col = nCol;
        mat->fil = nFil;

        for(i = 0; i<nFil; i++){
            if(NULL == (mat->m[i] = malloc(nCol*sizeof(int)))){

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
        return(mat);

    }
}



void rellenarAleatoria(matRef mat){

    int i, j;

    srand(time(NULL));

    for(i=0; i < mat->fil; i++){
        for(j=0; j < mat->col; j++){

            mat->m[i][j] = rand() % RANDS;

        }
    }
}



void mostrarMatriz(matRef mat){

    int i, j;

    for(i=0; i<mat->fil; i++){

        printf("|");

        for(j=0; j<mat->col; j++){

            printf(" %d ", mat->m[i][j]);

        }

        printf("|\n");

    }

printf("\n\n");

}



lista extraerColumnaALista(matRef mat, int colExt,int *errNum){

    lista raiz;
    lista creador;
    lista indice;
    int i;
    int *vect;

    if(NULL == (vect = malloc((mat->fil)*sizeof(int)))){

        *errNum = -1;
        return NULL;

    }


    for(i=0; i<mat->fil; i++){

        vect[i] = mat->m[i][colExt];

    }

    if(NULL == (raiz = (lista)malloc(sizeof(nodo)))){

        *errNum = -2;
        free(vect);
        vect = NULL;
        return NULL;

    }

    raiz->dato = vect[0];
    raiz->sig = NULL;
    indice = raiz;

    for(i=1; i<mat->fil; i++){
        if(NULL == (creador =(lista)malloc(sizeof(nodo)))){

            *errNum = -3;
            free(raiz);
            free(vect);
            raiz = NULL;
            return NULL;

        }

        indice->sig = creador;
        indice = indice->sig;
        creador = NULL;
        indice->dato = vect[i];
        indice->sig = NULL;

    }

    free(vect);
    *errNum = 0;
    return raiz;

}



void mostrarListaEnlazada(lista raiz){

    lista indice;

    indice = raiz;

    while(indice != NULL){

        printf("| %d | --->", indice->dato);
        indice = indice->sig;

    }

    printf("NULL\n\n");

}



void ordenarListaEnlazada(lista *raiz, matRef mat){

    lista indice;
    lista aux;
    lista bucle;
    int temp;
    int i;

    indice = *raiz;
    aux = (*raiz)->sig;
    bucle = *raiz;

    while(bucle != NULL){
        while(indice->sig != NULL){

            if((indice->dato) > (aux->dato)){

                temp = aux->dato;
                aux->dato= indice->dato;
                indice->dato = temp;

            }

            indice = aux;
            aux = aux->sig;

        }

        indice = *raiz;
        aux = (*raiz)->sig;
        bucle = bucle->sig;

    }
}



void liberarListaEnlazada(lista *raiz){

    lista indice;

    indice = *raiz;

    while(indice != NULL){

        *raiz = (*raiz)->sig;
        free(indice);
        indice = *raiz;

    }
}



void liberarMatriz(matRef mat){

    int i;

    for(i=0 ; i<mat->col; i++){

        free(mat->m[i]);

    }
    free(mat->m);
    mat->m = NULL;

}
