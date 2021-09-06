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