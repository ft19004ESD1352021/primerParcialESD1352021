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

char * leer(char *Path) {
   
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

        } else if (filas == 0 && letra == 44) {
            columnas++;

        }
    }
    
    filas++;
    columnas++;



    rewind(archivoP);
    
    char *matrizR = (char *) malloc(filas * columnas * sizeof (char));
    
    //static char matrizR[60][7];
    char valor[300];
    char *valorObtenido = "";
    char *prueba;
    int filasMuestra = 0;
    int contador = 0;

    void *alma; 
    do {
       

        contador = 0;

        fgets(valor, 300, archivoP);

        prueba = valor;
        //Obtenemos las demas columnas del strtok
        while (contador < columnas) {
            if (contador == 0) {
                 
                valorObtenido = strtok(valor, ", ");
                 
            }else{
                 valorObtenido = strtok(NULL, ", ");
            }
            printf(" %s ",valorObtenido);
            
            //*(matrizR + filasMuestra * columnas + contador) = (valorObtenido);
            contador++;
        }
        printf("\n");
        filasMuestra++;
    } while (feof(archivoP) == 0 &&  filasMuestra < filas);

    fclose(archivoP);
    
    return matrizR;
}