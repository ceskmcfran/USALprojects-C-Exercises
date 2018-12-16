#include<stdio.h>
#include<stdlib.h>
#define LIMS 25
#define LIMI 0

int *concVect(int *, int *, int, int);

int main(void){

    //Variables
    int v1[LIMS], v2[LIMS];
    int tam1, tam2;
    int i, j;
    int *vv;



    //Main

    do{

        printf("Escribe la longitud del vector 1:  ");
        scanf("%d", &tam1);
        printf("\n");

    }while((tam1>LIMS)||(tam1<=LIMI));


    do{

        printf("Escribe la longitud del vector 2:  ");
        scanf("%d", &tam2);
        printf("\n");

    }while((tam2>LIMS)||(tam2<=LIMI)||(tam1==tam2));

    printf("\n");

    for(i = 0; i<tam1; i++){

        printf("Vector 1 -> introduzca elemento (%d):  ", i+1);
        scanf("%d", &v1[i]);
        printf("\n");

    }

    printf("\n");

        for(i = 0; i<tam2; i++){

        printf("Vector 2 -> Introduzca elemento (%d):  ", i+1);
        scanf("%d", &v2[i]);
        printf("\n");

    }

    vv = concVect(v1, v2, tam1, tam2);

    if(vv == NULL){
        printf("Error reservando memoria.\n");
        exit(-1);
    }
    printf("\n");
    printf("Vector concatenado:\n");
    for(j=0; j<tam1+tam2; j++){
        printf("%d", vv[j]);
    }

    printf("\n");
    free(vv);
    system("pause");
}


//Funcion


int *concVect(int *v1, int *v2, int tam1, int tam2){

    int *vConc;
    int i;

    if((vConc = (int *) calloc(tam1+tam2, sizeof(int))) == NULL){

        return NULL;

    }

    for(i = 0; i<tam1; i++)
        vConc[i]= v1[i];

    for(i = 0; i<tam2; i++)
        vConc[tam1+i] = v2[i];

    return vConc;


}
