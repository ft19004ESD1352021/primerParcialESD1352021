#ifndef CABECERA_H
#define CABECERA_H

typedef char cambio[10000];

int * generarMatriz(char *Path);

int *transponerMatrices(int *matriz, int filas, int columnas);

int *productoMatriz(int *primerMatriz, int pFila, int pColumna, int *segundaMatriz, int sFila, int sColumna);

const char * integrantes();

char * retornarArchivo(char *nombre);

#endif