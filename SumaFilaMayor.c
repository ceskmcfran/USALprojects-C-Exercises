#include<stdio.h>
#include<stdlib.h>
#define COL 15
#define FIL 15
#define DEBUG

int* filaMayor(int**, int, int, int*);

int main(void){

    int **m;
    int *ptr;
    int nFil,nCol;
    int errNum, i, j;

    do{
        printf("¿Número de filas?: ");    scanf ("%d", &nFil);
        printf("¿Número de columnas?: "); scanf ("%d", &nCol);
    }while (nFil <= 0 || nCol <= 0 );

    if(NULL == (m = (int **)malloc(nFil*sizeof(int*)))){
        #ifdef DEBUG
            fprintf(stderr,"Error: Fallo en la reserva del vector de punteros a filas");
        #endif // DEBUG
        errNum = -1;

    }
    for(i=0; i<nFil; i++){
        if(NULL == (m[i]= (int*)malloc(nCol*sizeof(int)))){
            for(j=i-1; j>=0; j--){

                free(m[j]);

            }
            free(m);
        #ifdef DEBUG
            fprintf(stderr,"Error: Fallo en la reserva de los vectores columna");
        #endif // DEBUG

            errNum = -2;

        }
    }
    ptr = filaMayor(m,nFil,nCol,&errNum);

    for (i=0; i < nFil; i++){
     free(m[i]);
     free(m);
    }

system("pause");
return 0;
}



int* filaMayor(int **m, int nFil, int nCol, int *errNum){

    int *vector;
    int filMax = 0, sumaFil = 0, sumaMax = 0, i = 0, j = 0;

    sumaMax = m[0][0];
    for(i=0; i<nFil; i++){

        sumaFil = 0;
        for(j=0; i<nCol; j++){
            sumaFil += m[i][j];
            if(sumaFil>sumaMax){
                sumaMax = sumaFil;
                filMax = i;
            }
        }
    }
    if(NULL == (vector=(int)malloc(nCol*sizeof(int)))){
        #ifdef DEBUG
            fprintf(stderr,"Error: Fallo en la reserva del vector");
        #endif // DEBUG
        *errNum = -1;
        return NULL;
    }
    for(j=0; i<nCol; j++){
        vector[j] = m[filMax][j];
    }
    return vector;

}
