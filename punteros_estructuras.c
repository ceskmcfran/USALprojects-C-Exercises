#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>


typedef struct empleados {
    char apellidos[30];
    char nombre[15];
    int  matricula;
    //char bufferRelleno[50000];
} tipoEmpleado;


void cargarRegistrosAleatorios(tipoEmpleado * empleados, int numEmpleados);
void cargarUnRegistro(tipoEmpleado * empleado);

void mostrarRegistro(tipoEmpleado empleado);
void mostrarRegistrosRef(tipoEmpleado ** refsEmpleados, int numEmpleados);
void mostrarRegistros(tipoEmpleado * empleados, int numEmpleados);

void ordenarRegistrosRefApellido(tipoEmpleado ** refsEmpleados, int numEmpleados);
void ordenarRegistrosApellido(tipoEmpleado * empleados, int numEmpleados);


#define NUM_EMPLEADOS   10


int
main(void)
{
    tipoEmpleado regEmpleados[NUM_EMPLEADOS], unEmpleado;
    tipoEmpleado *regEmpleadosRef[NUM_EMPLEADOS];
    int i;
    clock_t tiempoInicial, tiempoFinal;



    cargarRegistrosAleatorios(regEmpleados, NUM_EMPLEADOS);

    mostrarRegistros(regEmpleados, NUM_EMPLEADOS);

    printf("\n\n Jugando con un único registro: \n");
    unEmpleado = regEmpleados[2];
    mostrarRegistro(unEmpleado);
    mostrarRegistro(regEmpleados[2]);
    mostrarRegistros(&unEmpleado, 1);

    cargarUnRegistro(&unEmpleado);
    printf("\n\nEl registrocargado es: \n");
    mostrarRegistro(unEmpleado);
    printf("\ny el registro regEmpleados[2] es: \n");
    mostrarRegistro(regEmpleados[2]);

    for (i = 0; i < NUM_EMPLEADOS; i++)
	    regEmpleadosRef[i] = &regEmpleados[i];

    printf("\n\nValores no clasificados (a través matriz punteros): \n");
    mostrarRegistrosRef(regEmpleadosRef, NUM_EMPLEADOS);

    tiempoInicial = tiempoFinal = clock ();
    ordenarRegistrosRefApellido(regEmpleadosRef, NUM_EMPLEADOS);
    tiempoFinal = clock ();


    printf("\n\nValores clasificados (a través matriz punteros): \n");
    printf("Tiempo tardado: %f\n",(tiempoFinal-tiempoInicial)/(double)CLOCKS_PER_SEC);
    mostrarRegistrosRef(regEmpleadosRef, NUM_EMPLEADOS);

    printf("\n\nAhora valores no clasificados matriz de registros original: \n");
    mostrarRegistros(regEmpleados, NUM_EMPLEADOS);

    tiempoInicial = tiempoFinal = clock ();
    ordenarRegistrosApellido(regEmpleados, NUM_EMPLEADOS);
    tiempoFinal = clock ();

    printf("\n\nAhora valores clasificados matriz de registros original: \n");
    printf("Tiempo tardado: %f\n",(tiempoFinal-tiempoInicial)/(double)CLOCKS_PER_SEC);
    mostrarRegistros(regEmpleados, NUM_EMPLEADOS);
    system("pause");
    return 0;
}

void
cargarRegistrosAleatorios(tipoEmpleado * empleados, int numEmpleados)
{
    int i;
    static char apellidos [][15] = {"ALONSO","ALVAREZ","ARBESU",
        "DOMINGUEZ","FERNANDEZ","FLORIANO",
        "GONZALEZ","GOMEZ","GUTIERREZ",
        "MARTIN", "MORO", "PEREZ","TURRION",
        "ZAMBRANO"};
    static char nombres [][15] = {"ALVARO","ARSENIO","DOMINGO",
        "FELIPE","FATIMA","FABIAN",
        "GONZALO","PEDRO","PATRICIA",
        "TOMAS", "ZOILO"};
    int numApellidos = sizeof(apellidos)/15;
    int numNombres = sizeof(nombres)/15;
    char buffer[5];

    srand(time(NULL));
    for (i = 0; i < numEmpleados; i++) {
        sprintf(empleados[i].apellidos,"%s %s",apellidos[rand() % numApellidos],
                apellidos[rand() % numApellidos]);
        sprintf(empleados[i].nombre,"%s",nombres[rand() % numNombres]);
        sprintf(buffer,"%c%c%c%c",(char)('0' + rand() % 10),
                (char)('0' + rand() % 10),
                (char)('0' + rand() % 10),
                (char)('0' + rand() % 10));
        empleados[i].matricula = atoi(buffer);
    }
}


void
cargarUnRegistro(tipoEmpleado * empleado)
{
    /*
     * Esta función recibe un ÚNICO REGISTRO de tipo tipoEmpleado
     * y el alumno debe escribir el código necesario para que
     * se pidan los datos necesarios por pantalla y cargar
     * los campos del registro con los datos introducidos
     * por teclado por el usuario
     */
    printf("Introduzca sus apellidos:  ");
    gets(empleado->apellidos);
    printf("Introduzca el nombre:  ");
    gets(empleado->nombre);
    printf("Introduzca el numero de matricula: ");
    scanf("%d", &empleado->matricula);


}


void
mostrarRegistro(tipoEmpleado empleado)
{
    /*
     * Esta función muestra por pantalla y en una única línea
     * los datos almacenados en los campos del registro
     * recibido
     */
     printf("Apellidos: %s\n", empleado.apellidos);
     printf("Nombre: %s\n", empleado.nombre);
     printf("Matricula: %d\n", empleado.matricula);


}


void
mostrarRegistros(tipoEmpleado * empleados, int numEmpleados)
{
    /*
     * Esta función recibe un vector de registros de tipoEmpleado
     * de tamaño numEmpleados, y muestra por pantalla el contenido
     * de los campos de todos los registros de dicho vector, un
     * registro por línea
     */
    int i;

    for(i=0; i<numEmpleados; i++){

        printf("Apellidos: %s\n", (empleados[i]).apellidos);
        printf("Nombre: %s\n", (empleados[i]).nombre);
        printf("Matricula: %d\n", (empleados[i]).matricula);


    }

}

void
mostrarRegistrosRef(tipoEmpleado ** refsEmpleados, int numEmpleados)
{
    /*
     * Esta función recibe un vector de  punteros a registros de
     * tipoEmpleado, de tamaño numEmpleados (el vector), y muestra por pantalla
     * el contenido de los campos de todos los registros referenciados
     * por los punteros del vector, mostrando un registro por línea
     */
    int i;

    for(i=0; i<numEmpleados; i++){

        printf("Apellidos: %s\n", (refsEmpleados[i])->apellidos);
        printf("Nombre: %s\n", (refsEmpleados[i])->nombre);
        printf("Matricula: %d\n", (refsEmpleados[i])->matricula);

    }

}


void
ordenarRegistrosApellido(tipoEmpleado * empleados, int numEmpleados)
{
    int i,j;
    tipoEmpleado temp;

    for (i = 0; i < numEmpleados - 1 ; i++) {
        for (j = numEmpleados-1; j > i; j--) {
            if ((strcmp(empleados[j].apellidos, empleados[j - 1].apellidos)) < 0) {
                temp = empleados[j];
                empleados[j] = empleados[j - 1];
                empleados[j - 1] = temp;
            }
        }
    }
}

void
ordenarRegistrosRefApellido(tipoEmpleado ** refsEmpleados, int numEmpleados)
{
        /*
         * Esta función es análoga a la función ordenarRegistrosApellido
         * pero con la diferencia que en vez de recibir un vector de
         * registros, recibe un vector de punteros a registros. La función
         * utiliza el mismo algoritmo de ordenación (burbuja) para ordenar
         * pero en vez de ordenar los registros, se ordenará el vector
         * de punteros, utilzando la información del campo apellidos
         * del registro apuntado.
         */
    int i,j;
    tipoEmpleado temp;

    for (i = 0; i < numEmpleados - 1 ; i++) {
        for (j = numEmpleados-1; j > i; j--) {
            if ((strcmp((refsEmpleados[j])->apellidos, (refsEmpleados[j - 1])->apellidos)) < 0) {
                temp = *refsEmpleados[j];
                *refsEmpleados[j] = *refsEmpleados[j - 1];
                *refsEmpleados[j - 1] = temp;
            }
        }
    }

}
