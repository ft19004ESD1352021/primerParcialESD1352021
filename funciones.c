#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cabecera.h"

/*------Generar matriz-------*/
int * generarMatriz(char *Path) {

    FILE *archivoP;
    archivoP = fopen(Path, "r");

    if (archivoP == NULL) {
        printf("Hubo un problema en abrir el archivo");
    }

    int filas = 0;
    int columnas = 0;
    //Cuentas filas y columnas  del archivo
    while (feof(archivoP) == 0) {
        char letra = fgetc(archivoP);
        if (letra == '\n') {
            filas++;
        } else if (filas < 1 && letra == 44) {
            columnas++;
        }
    }

    rewind(archivoP);

    int *generada = (int *) malloc(columnas * filas * sizeof (int));
    char valor[60];
    char *valorObtenido;
    char *prueba;
    int filasM = 0;
    char ignorando;

    do {
        //Descartamos la cabecera
        while (ignorando != '\n') {
            ignorando = fgetc(archivoP);
        }
        int contador = 0;
        fgets(valor, 60, archivoP);
        prueba = valor;

        strtok(prueba, ", ");
        //Obtenemos las demas columnas del strtok
        while (contador < columnas) {
            valorObtenido = strtok(NULL, ",");

            *(generada + filasM * columnas + contador) = atoi(valorObtenido);
            //printf("%s", valorObtenido);
            contador++;
        }
        filasM++;
    } while (feof(archivoP) == 0);
    fclose(archivoP);
    return generada;
}

/*------Transponer matriz-------*/
int * transponerMatrices(int *matriz, int filas, int columnas) {
    int *transpuesta = (int *) malloc(columnas * filas * sizeof (int));

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            *(transpuesta + j * filas + i) = *(matriz + i * columnas + j);
        }
    }
    return transpuesta;
}

int *multiplyMatrices(int *primerMatriz, int pFila, int pColumna, int *segundaMatriz, int sFila, int sColumna) {

    if (pColumna == sFila) {
        int aux;
        int *result = (int*) malloc(pFila * sColumna * sizeof (int));
        for (int i = 0; i < pFila; i++) {
            for (int j = 0; j < sColumna; j++) {
                aux = 0;
                for (int x = 0; x < pColumna; x++) {
                    aux += (*(primerMatriz + i * pColumna + x)) * (*(segundaMatriz + x * sColumna + j));
                }
                *(result + i * sColumna + j) = aux;
            }
        }
        return result;
    } else {
        puts("Dimenciones no son correctas");
        exit(0);
    }
}

const char * integrantes() {
    const char * grupo[] = {"LR19047,FT19004"};
    return *grupo;
}

char * Leer_archivo(char *nombre) {


    FILE *fpdo = fopen(nombre, "r");



    if (fpdo == NULL) {
        printf("No hay nada en %s\n", nombre);
        return 0;

    }

    int f = 1;
    int c = 1;
    while (feof(fpdo) == 0) {
        char letra = fgetc(fpdo);
        if (letra == '\n') {
            f++;
        } else if (f < 2 && letra == 44) {
            c++;
        }
    }

    
    rewind(fpdo);
    int i = 0;
    char *m;
    char temp[10024];

    char aux;
    int columnas = 0;

    //modificacion array[f][c];

    modificacion *arrays;
    arrays = (modificacion *) malloc(f * c * sizeof (modificacion));
    while (i < f) {

        columnas = 0;
        fgets(temp, 10024, fpdo);

        m = strtok(temp, ",");

        while (m != NULL) {
            //strcpy(array[i][columnas], m);
             strcpy( *(arrays + i * c + columnas), m);
            m = strtok(NULL, ",");
           
            columnas++;
        }
        i++;

    }

    /*
        for (int j = 0; j < f; j++) {
            for (int x = 0; x < c; x++) {
                printf(" %s ", array[j][x]);
            }
            puts("");
        }
     */

    puts("\n");
    fclose(fpdo);
    return arrays;
}