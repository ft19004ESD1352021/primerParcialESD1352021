#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cabecera.h"

/*------Generar matriz-------*/
int * generarMatriz(char *Path) {
    FILE *archivoP;
    archivoP = fopen(Path, "r");
    if (archivoP == 0) {
        printf("Hubo un problema en abrir el archivo");
        return 0;
        exit(0);
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
            contador++;
        }
        filasM++;
    } while (feof(archivoP) == 0);
    fclose(archivoP);
    return generada;
}
//---------------------------------------------------------------------------------
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
//---------------------------------------------------------------------------------
/*------Multiplicar matrices-------*/
int *productoMatriz(int *primerMatriz, int pFila, int pColumna, int *segundaMatriz, int sFila, int sColumna) {

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
        return 0;
        exit(0);
    }
}

//---------------------------------------------------------------------------------
/*------Generar carnets-------*/
const char * integrantes() {
    const char * grupo[] = {"#LR19047,#FT19004"};
    return *grupo;
}

//---------------------------------------------------------------------------------
/*------Retornar matriz-------*/

char * retornarArchivo(char *archivo) {
    FILE *puntero = fopen(archivo, "r");
    if (puntero == NULL) {
        printf("Esta vacio el archivo %s\n", archivo);
        return NULL;
    }
    int f = 1,c = 1;    
    while (feof(puntero) == 0) {
        char letra = fgetc(puntero);
        if (letra == '\n') {
            f++;
        } else if (f < 2 && letra == 44) {
            c++;
        }
    }  
    rewind(puntero);
    int i = 0;
    char *almacenamiento;
    char goku[10000];
    int columnas = 0;
    cambio *arrays;
    arrays = (cambio *) malloc(f * c * sizeof (cambio));
    while (i < f) {
        columnas = 0;
        fgets(goku, 10000, puntero);
        almacenamiento = strtok(goku, ",");
        while (almacenamiento != NULL) {
             strcpy( *(arrays + i * c + columnas), almacenamiento);
            almacenamiento = strtok(NULL, ",");          
            columnas++;
        }
        i++;
    }
    puts("");
    fclose(puntero);
    return arrays;
}